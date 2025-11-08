/**
 * @file heading.h
 * @author Charliechen114514 (chengh1922@mails.jlu.edu.cn)
 * @brief headings config
 * @version 0.1
 * @date 2025-11-08
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once
#include "base_node.h"
#include "property.hpp"
#include <string>

namespace plan_parser::base_components {

struct Heading : public IBaseNode {
	Heading()
	    : IBaseNode(BaseNodeType::HEADING) { }
	utils::property<int> level { 1 };
	utils::property<std::string> text {};
};

} // namespace plan_parser::base_components