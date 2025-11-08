#include "base_components/heading.h"
#include "matcher/heading_match.h"
#include "text_helper.h"
#include <memory>
#include <regex>

namespace plan_parser::matcher {

HeadingMatcher::match_result_t HeadingMatcher::match(const std::string& src) {
	static std::regex re(R"(^\s*(#{1,6})\s*(.+?)\s*$)");
	std::smatch m;
	if (std::regex_match(src, m, re)) {
		auto node = std::make_shared<base_components::Heading>();
		node->level.set(static_cast<int>(m[1].str().size()));
		node->text.set(utils::trim(m[2].str()));
		return node;
	}
	return std::nullopt;
}

}
