#include "stringUtils.hpp"

//returns index of delimiter
int delimCheck(char c,const char* delims)
{
	int i=0;
	while(delims[i]!='\0')
	{
		if(c==delims[i]) return i;
		i++;
	}
	return -1;
}