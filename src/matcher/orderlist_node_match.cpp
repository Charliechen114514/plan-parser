#include "base_components/list.h"
#include "base_components/list_item.h"
#include "matcher/ordered_list_node_match.h"
#include "text_helper.h"
#include <memory>
#include <regex>
#include <string>

namespace plan_parser::matcher {

OrderListMatcher::match_result_t
OrderListMatcher::match(const std::string& src) {
	std::smatch m;
	static std::regex re(R"(^\s*\d+[\.\)]\s+(.*)$)");
	if (!std::regex_match(src, m, re)) {
		return std::nullopt;
	}
	auto item = std::make_shared<base_components::ListItem>();
	item->text.set(utils::trim(m[1].str()));
	return item;
}

}
