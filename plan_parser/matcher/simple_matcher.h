/**
 * @file simple_matcher.h
 * @author Charliechen114514 (chengh1922@mails.jlu.edu.cn)
 * @brief
 * @version 0.1
 * @date 2025-11-08
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once
#include "base_components/base_node.h"
#include <memory>
#include <optional>
#include <string>

namespace plan_parser {
namespace matcher {
	struct PlainMatcher {
		using match_result_t = std::optional<std::shared_ptr<base_components::IBaseNode>>;
		virtual ~PlainMatcher() = default;
		virtual match_result_t match(const std::string& src) = 0;
	};
}
}
