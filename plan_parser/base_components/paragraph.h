#pragma once
#include "base_node.h"
#include "property.hpp"
#include <string>

namespace plan_parser::base_components {

struct Paragraph : public IBaseNode {
	Paragraph()
	    : IBaseNode(BaseNodeType::PARAGRAPH) { }
	utils::property<std::string> text;
};

} // namespace plan_parser::base_components