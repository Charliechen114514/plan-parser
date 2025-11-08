#include "matcher/tasklist_node_match.h"
#include "base_components/list.h"
#include "base_components/list_item.h"
#include "text_helper.h"
#include <memory>
#include <regex>
#include <string>

namespace plan_parser::matcher {

TaskListMatcher::match_result_t
TaskListMatcher::match(const std::string& src) {
	std::smatch m;
	static std::regex re(R"(^\s*[-+*]\s+\[( |x|X)\]\s+(.*)$)");
	if (!std::regex_match(src, m, re)) {
		return std::nullopt;
	}
	auto item = std::make_shared<base_components::ListItem>();

	bool done = (m[1].str() == "x" || m[1].str() == "X");
	item->done.set(done);
	item->task.set(true);
	item->text.set(utils::trim(m[2].str()));
	return item;
}

}
