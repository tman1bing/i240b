#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char **argv)
{
	string delimiters[] = {"(", "<", "[", "{", ")", ">", "]", "}"};
	stack<string> st;
	if(argc == 1)
	{
		cerr << "usage: ./balanced '(' ')' '<' '>' '[' ']' '{' '}'" << endl;
		return EXIT_FAILURE;
	}
	for(int i = 1; i < argc; i++)
	{
		for(int j = 0; j < sizeof(delimiters)/sizeof(delimiters[0]); j++)
		{
			//if argv[i] is a delimiter;
			if(argv[i] == delimiters[j])
			{
				//if argv[i] is an opening delimiter;
				if(j < 4)
					st.push(argv[i]);
				//else if argv[i] is a closeing delimiter;
				else if(j >= 4)
				{
					if(st.empty())
					{
						cerr << "unbalanced at argument " << i << endl;
						return EXIT_FAILURE;
					}
					else
					{
						int k = 0;
						//get index of delimiter on stack top;
						for(; k < (sizeof(delimiters)/sizeof(delimiters[0])) / 2; k++)
						{
							if(st.top() == delimiters[k])
								break;
						}
						//delimiter on stack top has its complement halfway accross the delimiter list;
						if(delimiters[k + (sizeof(delimiters)/sizeof(delimiters[0])) / 2] != delimiters[j])
						{
							cerr << "unbalanced at argument " << j << endl;
							return EXIT_FAILURE;
						}
						else
							st.pop();
					}
				}
				break;
			}
			else if(j == sizeof(delimiters)/sizeof(delimiters[0]) - 1)
			{
				cerr << "Invalid delimiter " << argv[i] << endl;
				return EXIT_FAILURE;
			}
		}
	}
	if(st.empty())
		return EXIT_SUCCESS;
	else
	{
		cerr << "unbalanced at argument " << argc - 1 << endl;
		return EXIT_FAILURE;
	}
}
