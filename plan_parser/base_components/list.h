/**
 * @file list.h
 * @author Charliechen114514 (chengh1922@mails.jlu.edu.cn)
 * @brief
 * @version 0.1
 * @date 2025-11-08
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once

#include "base_node.h"
#include "property.hpp"
#include <memory>
#include <vector>

namespace plan_parser::base_components {

struct ListItem;
struct List : public IBaseNode {
	List()
	    : IBaseNode(BaseNodeType::LIST) { }
	utils::property<bool> ordered { false };
	std::vector<std::shared_ptr<ListItem>> items;
};

}