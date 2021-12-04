#include <iostream>
#include <vector>
#include <fstream>

#define MOVE_RIGHT '>'
#define MOVE_LEFT '<'
#define PLUS '+'
#define MINUS '-'
#define DOT '.'
#define RPAREN ']'
#define LPAREN '['

#include "brainfuck.h"

/*
	>	ptr++
	<	ptr--
	+	array[ptr]++
	-	array[ptr]--
	.	print(chr(array[ptr]))
	[	while(array[ptr]){
	]	}
*/

// step 2: write a lexer
// step 3: write a parser
// step 4: write the compile part
// step 5: optimize the code and shit

std::vector<char> tokBF(std::string filename) {
	// file object
	std::ifstream file (filename);

	// vars to store tokens
	std::vector<char> tokens;
	char tok; 

	// push all file contents to the stack as chars
	if (file.is_open()) {
		while (file >> tok) {
			tokens.push_back(tok);
		}
		file.close();
	}

	// return the vector of all chars
	return tokens;
}

bool lexBF(std::vector<char> tokens) {
	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] == MOVE_RIGHT) {
			std::cout << "MOVE RIGHT" << std::endl;
		} else if (tokens[i] == MOVE_LEFT) {
			std::cout << "MOVE LEFT" << std::endl;
		} else if (tokens[i] == PLUS) {
			std::cout << "PLUS" << std::endl;
		} else if (tokens[i] == MINUS) {
			std::cout << "MINUS" << std::endl;
		} else if (tokens[i] == DOT) {
			std::cout << "DOT" << std::endl;
		} else if (tokens[i] == RPAREN) {
			std::cout << "RPAREN" << std::endl;
		} else if (tokens[i] == LPAREN) {
			std::cout << "LPAREN" << std::endl;
		}
	}
	return true;
}

int main(int argc, char **argv) {
	std::vector<char> tokens = tokBF(argv[1]);
	lexBF(tokens);
}
