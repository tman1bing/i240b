#include <cctype>

#include "digit-sum.hh"

int
digitSum(const char* str)
{
	int acc = 0;
	bool wantDigit = true;
	for(int i = 0; str[i] != '\0'; i++)
	{
		if(isdigit(str[i]))
		{
			if(wantDigit)
			{
				acc += str[i] - '0';
				wantDigit = false;
			}
			else
				break;
		}
		else if(str[i] == '+')
			if(!wantDigit)
				wantDigit = true;
			else
				break;
		else if(str[i] == ' ')
			continue;
		else
			break;
	}
	return acc;
}
