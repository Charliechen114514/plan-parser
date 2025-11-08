#include "base_components/base_node.h"
#include "base_components/heading.h"
#include "base_components/list.h"
#include "base_components/list_item.h"
#include "base_components/paragraph.h"
#include "base_components/quote.h"
#include "parser/markdown_parser.h"
#include <exception>
#include <fstream>
#include <ios>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

std::vector<std::string> from_files(const std::string file_path) {
	std::fstream f;
	std::vector<std::string> res;
	f.open(file_path, std::ios_base::in);
	std::string line;
	while (std::getline(f, line)) {
		res.emplace_back(line);
	}
	f.close();
	return res;
}

using namespace plan_parser::base_components; //< for IBaseNode
using namespace plan_parser::parser; //< Markdown Parser

void dump_block(std::vector<std::shared_ptr<IBaseNode>>& nodes, int depth = 0) {
	std::string pad(depth * 2, ' ');
	for (const auto& each : nodes) {
		switch (each->get_node_type()) {
		case BaseNodeType::HEADING: {
			auto h = std::dynamic_pointer_cast<Heading>(each);
			std::cout << pad << "Heading(level=" << h->level.get() << ", text=\"" << h->text.get() << "\")\n";
			break;
		}
		case BaseNodeType::LIST: {
			auto lst = std::dynamic_pointer_cast<List>(each);
			std::cout << pad << (lst->ordered ? "OrderedList" : "UnorderedList") << ":\n";
			for (auto& it : lst->items) {
				std::cout << pad << "  - ";
				if (it->task)
					std::cout << "[task " << (it->done ? "done" : "todo") << "] ";
				std::cout << it->text.get() << "\n";
				dump_block(it->children, depth + 2);
			}
		} break;
		case BaseNodeType::LISTITEM:
			// shouldnt
			break;
		case BaseNodeType::PARAGRAPH: {
			auto para = std::dynamic_pointer_cast<Paragraph>(each);
			std::cout << pad << "Paragraph: " << para->text.get() << "\n";
		} break;
		case BaseNodeType::QUOTE: {
			auto q = std::dynamic_pointer_cast<Quote>(each);
			std::cout << pad << "> QuoteBlock:\n";
			dump_block(q->children, depth + 1);
		} break;
		}
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " " << "<markdown_file_path>\n";
		return 1;
	}

	std::cout << "Executing print for " << argv[1] << std::endl;

	MarkdownParser parser;
	try {
		auto result = parser.parse(from_files(argv[1]));
		dump_block(result);
	} catch (const std::exception& e) {
		std::cerr << "Exception occurs " << e.what();
		return 1;
	}
}
