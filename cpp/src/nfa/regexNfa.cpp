#include "nfa/regexNfa.hpp"

regexParser::regexParser(std::string regexPattern)
{
	m_regexPattern=regexPattern;
}
regexParser::~regexParser()
{
	//cleanup
}

void regexParser::postfixNotation()
{
	/*
	requirements
		{
		1. need a stack
		2. need a group number variable to assign groups
		3. concatenate continuous strings to match string patterns
	optimizations
		{(later)
		1. see if using a char reduces code size
		2. convert some parts into DFA based on some metric
	*/

	//make a postfix notation with group numbers inside for catching group strings
	std::string postFixString;

	//for grouping and other operators (),[],{}
	std::stack<char> operatorStack;

	unsigned int i=0;
	unsigned int stringSize=m_regexPattern.size();
	char c,topChar,lastChar;
	int group=0;
	while(i<stringSize)
	{
		c=m_regexPattern[i];
		if(operatorStack.size()!=0)
			topChar=operatorStack.top();
		else
			topChar='\0';
		// add syntax errors for brace grouping
		if(c=='(')
		{
			group++;
			operatorStack.push('(');
		}
		else if(c==')')
		{
			group--;
			//pop operators to string until (
			while(operatorStack.size()>=2)
			{
				postFixString+=operatorStack.top();
				operatorStack.pop();
			}
			//pop last brace?
			operatorStack.pop();
		}
		else if(delimCheck(c,"{}[]")!=-1)
		{
			if(delimCheck(topChar,"{}[]")!=-1)
			{
				operatorStack.push(c);
			}
		}
		else if(delimCheck(c,"?|+.*")!=-1)
		{
			if(delimCheck(topChar,"?|[{(+*.^$:")!=1)
			{
				if(c=='|')
					operatorStack.push('|');
				else
					postFixString+=c;
			}
			else
			{
				DEBUG_LINE();
				std::cout<<"Syntax error: "<<c<<" can't be after "<<topChar<<"\n";
			}
		}
		//push this block down after dealing with ^$#,- etc other special characters
		else if(isalnum(c))
		{
			postFixString+=c;
		}
		//add cases for ^$- etc
		else if(true)
		{
			//do nothing
		}
		lastChar=c;
		i++;
	}
	/*
	[==]
	[::]
	[..]
	[]
	()
	* + ? {m,n}
	^ $
	|
	*/
	// char precedenceOrder[]="";
	m_postFixString=postFixString;
}

void regexParser::printPostfix()
{
	std::cout<<m_postFixString<<"\n";
}

void regexParser::clearPostfix()
{
	m_postFixString="";
}