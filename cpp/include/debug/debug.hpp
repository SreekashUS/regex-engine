#pragma once

#include <iostream>

#define DEBUG 1

#ifdef DEBUG
	#define DEBUG_LINE() \
		std::cout<<__FILE__<<":"<<__LINE__<<":0 "
#else 
	#define DEBUG_LINE()
#endif