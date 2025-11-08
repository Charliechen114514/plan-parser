/**
 * @file text_helper.h
 * @author Charliechen114514 (chengh1922@mails.jlu.edu.cn)
 * @brief
 * @version 0.1
 * @date 2025-11-08
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once
#include <string>
namespace plan_parser {
namespace utils {
	enum class TrimMethod {
		LEFT_TRIM,
		RIGHT_TRIM,
		ALL_TRIM
	};

	/**
	 * @brief trim string
	 *
	 * @param str
	 * @param m
	 * @return std::string
	 */
	std::string trim(const std::string& str,
	                 const TrimMethod m = TrimMethod::ALL_TRIM);

	int count_indent(const std::string& s);

}
}
