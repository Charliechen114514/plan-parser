#pragma once
#include "base_components/base_node.h"
#include <memory>
#include <vector>
namespace plan_parser {

namespace parser {

	struct Parser {
		virtual ~Parser() = default;
		virtual std::vector<std::shared_ptr<base_components::IBaseNode>>
		parse(const std::vector<std::string>& lines) = 0;
	};

}

}