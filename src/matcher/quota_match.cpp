/**
 * @file quota_match.cpp
 * @author Charliechen114514 (chengh1922@mails.jlu.edu.cn)
 * @brief
 * @version 0.1
 * @date 2025-11-08
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "base_components/quote.h"
#include "matcher/quote_match.h"
#include <optional>
#include <regex>
#include <string>

namespace plan_parser::matcher {

QuoteMatcher::match_result_t
QuoteMatcher::match(const std::string& src) {
	std::smatch m;
	static std::regex re(R"(^\s*>\s?(.*)$)");
	if (!std::regex_match(src, m, re)) {
		return std::nullopt;
	}
	auto quote = std::make_shared<base_components::Quote>();
	return quote;
}

} // namespace plan_parser::matcher
