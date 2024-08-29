#include <iostream>
#include "nfa/regexNfa.hpp"

int main(int argc, char** argv)
{
	if(argc==1)
	{
		//print usage
	}
	else
	{
		std::string regexExpr(argv[1]);

		regexParser rParser(regexExpr);

		rParser.postfixNotation();

		rParser.printPostfix();
	}
}