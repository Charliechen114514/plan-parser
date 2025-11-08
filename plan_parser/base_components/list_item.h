/**
 * @file list_item.h
 * @author Charliechen114514 (chengh1922@mails.jlu.edu.cn)
 * @brief contains list items
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
#include <string>
#include <vector>

namespace plan_parser::base_components {

struct IBaseNode; // forward declaration

struct ListItem : public IBaseNode {
	ListItem()
	    : IBaseNode(BaseNodeType::LISTITEM) { }
	utils::property<std::string> text;
	std::vector<std::shared_ptr<IBaseNode>> children;

	utils::property<bool> task { false };
	utils::property<bool> done { false };
};

}