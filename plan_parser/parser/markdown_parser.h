#pragma once

#include "parser/parser.h"
namespace plan_parser {
namespace parser {
	struct MarkdownParser : public Parser {
		std::vector<std::shared_ptr<plan_parser::base_components::IBaseNode>>
		parse(const std::vector<std::string>& lines) override;
	};
}
}