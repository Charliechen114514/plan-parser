#include "text_helper.h"

namespace {

/**
 * @brief trim and simplified the string by removing left
 *
 * @param str
 * @return std::string
 */
inline std::string ltrim(const std::string& str) {
	size_t i = 0;
	while (i < str.size() && isspace((unsigned char)str[i]))
		i++;
	return str.substr(i);
}

/**
 * @brief trim and simplified the string by removing right
 *
 * @param str
 * @return std::string
 */
inline std::string rtrim(const std::string& str) {
	size_t i = str.size();
	while (i > 0 && isspace((unsigned char)str[i - 1]))
		i--;
	return str.substr(0, i);
}
}

namespace plan_parser::utils {

std::string trim(const std::string& str,
                 const TrimMethod m) {
	switch (m) {
	case TrimMethod::LEFT_TRIM:
		return ltrim(str);
	case TrimMethod::RIGHT_TRIM:
		return rtrim(str);
	case TrimMethod::ALL_TRIM:
		return ltrim(rtrim(str));
	}
	return str;
}

int count_indent(const std::string& s) {
	static constexpr char indent_ch = ' ';
	int n = 0;
	for (const char c : s) {
		if (c != indent_ch)
			return n;
		n++;
	}
	return n;
}

}