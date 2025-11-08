/**
 * @file base_node.h
 * @author Charliechen114514 (chengh1922@mails.jlu.edu.cn)
 * @brief basenode for the holdings
 * @version 0.1
 * @date 2025-11-08
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once

namespace plan_parser::base_components {

enum class BaseNodeType {
	LIST,
	LISTITEM,
	HEADING,
	PARAGRAPH,
	QUOTE
};

struct IBaseNode {
	virtual ~IBaseNode() = default;
	IBaseNode() = delete;

	IBaseNode(BaseNodeType t)
	    : t_(t) { }
	const BaseNodeType get_node_type() const { return t_; }

private:
	const BaseNodeType t_;
};

} // namespace plan_parser::base_components