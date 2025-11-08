/**
 * @file heading_match.h
 * @author Charliechen114514 (chengh1922@mails.jlu.edu.cn)
 * @brief
 * @version 0.1
 * @date 2025-11-08
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once
#include "simple_matcher.h"

namespace plan_parser::matcher {

struct HeadingMatcher : public PlainMatcher {
	match_result_t match(const std::string& src) override;
};

}
