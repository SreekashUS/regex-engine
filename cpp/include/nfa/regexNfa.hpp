#pragma once

#include <vector>
#include <string>
#include <stack>
#include <cstring>
#include <iostream>

#include "stringUtils/stringUtils.hpp"
#include "debug/debug.hpp"

/*
Note:
	1. This is edge based simulation NFA, which means that the simulation 
	runs on each vertex and compares the edge string/fragment and breaks if found and adds next
	simulation state
		- pros:
			- some expressions can be matched early, thus reducing simulation time
		- cons:
			- increases state nodes for *,+ etc increases memory
	2. This is vertex based simulation, simulation proceeds only if the matching expression
	matches the string in vertex
		- pros:
			- reduced state nodes
		- cons:
			- have to maintain multiple dynamic simulation states in the queue

	3. TODO: 
		a) Analysis required on above methods for NFA method
		b) Change parsing to directly make NFA graphs instead of converting to postfix
			- pros:
				- fixes concatenation issues
			- cons:
				- idk
*/


typedef enum regexType
{
	START=0
	,END
}regexType;

typedef struct regexVertex regexVertex;
struct regexVertex
{
	//patterns to reach this
	std::vector<std::string> patterns;

	int groupNumber;
	unsigned int matchStart;
	unsigned int matchEnd;

	//patterns to next States
	std::vector<regexVertex*> nextStates;
};

typedef struct regexSegment
{
	std::string expression;
	int group;
}regexSegment;

void getREdges(std::vector<std::string> patterns,regexVertex* regexDest,int group);

class regexParser
{
private:
	regexVertex *m_start,*m_end;
	std::string m_regexPattern;
	std::string m_postFixString;
public:
	regexParser(std::string regexPattern);

	~regexParser();

	void postfixNotation();
	void printPostfix();
	void clearPostfix();
	void generateNfa();
};