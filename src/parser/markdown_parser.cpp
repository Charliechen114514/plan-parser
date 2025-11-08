#include "parser/markdown_parser.h"
#include "base_components/base_node.h"
#include "base_components/list.h"
#include "base_components/list_item.h"
#include "base_components/paragraph.h"
#include "base_components/quote.h"
#include "matcher/heading_match.h"
#include "matcher/ordered_list_node_match.h"
#include "matcher/quote_match.h"
#include "matcher/simple_matcher.h"
#include "matcher/tasklist_node_match.h"
#include "matcher/unordered_list_node_match.h"
#include "text_helper.h"
#include <cstddef>
#include <memory>
#include <optional>
#include <regex>
#include <string>
#include <vector>
using namespace std;

namespace {
using namespace plan_parser::base_components;

std::vector<std::shared_ptr<IBaseNode>>
parse_blocks(const std::vector<std::string>& lines, size_t& i, int baseIndent);

std::shared_ptr<IBaseNode> parse_nodes(const std::string& raw) {
	using namespace plan_parser::matcher;
	static std::vector<std::shared_ptr<PlainMatcher>> matchers = {
		std::make_shared<TaskListMatcher>(),
		std::make_shared<OrderListMatcher>(),
		std::make_shared<UnorderListMatcher>()
	};

	for (auto& each : matchers) {
		auto nodes = each->match(raw);
		if (nodes) {
			return nodes.value();
		}
	}
	return nullptr;
}

std::shared_ptr<IBaseNode> parse_list(
    const std::vector<std::string>& lines,
    size_t& i,
    int baseIndent, bool ordered) {
	auto lst = std::make_shared<List>();
	lst->ordered.set(ordered); ///< set with ordered
	while (i < lines.size()) {
		const std::string raw = lines[i];

		// empty check
		if (plan_parser::utils::trim(raw).empty()) {
			i++;
			continue;
		}

		const int indent_cnt = plan_parser::utils::count_indent(raw);
		if (indent_cnt < baseIndent) {
			break;
		}

		auto listItem = std::dynamic_pointer_cast<ListItem>(parse_nodes(raw));
		if (!listItem) {
			break;
		}

		// Ok, these is items;
		i++;
		auto sub = parse_blocks(lines, i, indent_cnt + 2);
		listItem->children = std::move(sub);
		auto shared_one = (listItem);
		lst->items.push_back(listItem);
	}

	return lst;
}

std::optional<std::string> parse_quote_string(const std::string raw) {
	smatch m;
	std::string res;
	static std::regex re(R"(^\s*>\s?(.*)$)");
	if (regex_match(raw, m, re)) {
		return { m[1] };
	}
	return std::nullopt;
}

std::shared_ptr<IBaseNode> parse_quote(const std::vector<std::string>& lines,
                                       size_t& i,
                                       int baseIndent) {
	std::vector<std::string> inners;
	while (i < lines.size()) {
		const string raw = lines[i];
		auto res = parse_quote_string(lines[i]);
		if (!res) {
			break;
		}
		inners.emplace_back(res.value());
		i++;
	}
	size_t j = 0;
	auto q = std::make_shared<Quote>();
	q->children = parse_blocks(inners, j, 0);
	return q;
}

std::shared_ptr<IBaseNode> parse_paragragh(const vector<string>& lines, size_t& i, int baseIndent) {
	string accum;
	while (i < lines.size()) {
		const string raw = lines[i];
		// empty check
		if (plan_parser::utils::trim(raw).empty()) {
			i++;
			break;
		}

		const int indent_cnt = plan_parser::utils::count_indent(raw);
		if (indent_cnt < baseIndent) {
			break;
		}

		if (regex_match(raw, regex(R"(^\s*[#>\-\*\d].*)")))
			break; // next IBaseNode
		if (!accum.empty())
			accum += " ";
		accum += plan_parser::utils::trim(raw);
		i++;
	}
	auto para = std::make_shared<Paragraph>();
	para->text = accum;
	return para;
}

std::vector<std::shared_ptr<IBaseNode>>
parse_blocks(const std::vector<std::string>& lines, size_t& i, int baseIndent) {
	using namespace plan_parser::matcher;
	std::vector<std::shared_ptr<IBaseNode>> blocks {};

	HeadingMatcher head_matcher;
	QuoteMatcher quote_match;
	OrderListMatcher order_matcher;
	UnorderListMatcher unorder_matcher;
	TaskListMatcher tasklist_matcher;

	while (i < lines.size()) {
		const string raw = lines[i];
		// empty check
		if (plan_parser::utils::trim(raw).empty()) {
			i++;
			continue;
		}

		const int indent_cnt = plan_parser::utils::count_indent(raw);
		if (indent_cnt < baseIndent) {
			break;
		}

		auto head = head_matcher.match(raw);
		if (head) {
			blocks.emplace_back(head.value());
			i++;
			continue;
		}

		auto quote = quote_match.match(raw);
		if (quote) {
			blocks.emplace_back(parse_quote(lines, i, baseIndent));

			continue;
		}

		if (order_matcher.match(raw)) {
			blocks.emplace_back(parse_list(lines, i, baseIndent, true));

			continue;
		}

		if (tasklist_matcher.match(raw)
		    || unorder_matcher.match(raw)) {
			blocks.emplace_back(parse_list(lines, i, baseIndent, false));
			continue;
		}

		blocks.emplace_back(parse_paragragh(lines, i, baseIndent));
	}
	return blocks;
}

}

namespace plan_parser::parser {
std::vector<std::shared_ptr<base_components::IBaseNode>>
MarkdownParser::parse(const std::vector<std::string>& lines) {
	size_t i = 0;
	return parse_blocks(lines, i, 0);
}
}
