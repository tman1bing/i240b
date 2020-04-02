#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;

void setup(int argc, char **argv);
void readWordCounts(int argc, char **argv);
bool compareCount(pair<string, int>a, pair<string, int>b);
bool compareFirstLetter(pair<string, int>a, pair<string, int>b);
bool compareCountThenLetter(pair<string, int>a, pair<string, int>b);

int main(int argc, char **argv)
{
	setup(argc, argv);
	readWordCounts(argc, argv);
}

void setup(int argc, char**argv)
{
	if(argc < 5)
	{
		cout << "usage: ./wordcounts MAX_N_OUT MIN_WORD_LEN MAX_WORD_LEN FILE..." << endl;
		exit(1);
	}
	else
	{
		for(int i = 1; i < 4; i++)
			for(unsigned int j = 0; j < strlen(argv[i]); j++)
				if(!(isdigit(argv[i][j])))
				{
					cout << "bad integer value \"" << argv[i] << "\" for ";
					if(i == 1)
						cout << "MAX_N_OUT" << endl;
					else if(i == 2)
						cout << "MIN_WORD_LEN" << endl;
					else if(i == 3)
						cout << "MAX_WORD_LEN" << endl;
					exit(1);
				}
		
		if(atoi(argv[2]) > atoi(argv[3]))
		{
			cout << "MIN_WORD_LEN " << argv[3] << " is greater than MAX_WORD_LEN " << argv[4] << endl;
			exit(1);
		}
	}
}

void readWordCounts(int argc, char **argv)
{
	unordered_map<string, int> words;
	unordered_map<string, int>::iterator wordsIterator = words.begin();

	//get all words across all files listed;
	for(int fileCount = 4; fileCount < argc; fileCount++)
	{
		ifstream file;
		file.open(argv[fileCount]);
	
		//if file not found;
		if(!file.is_open())
		{
			cout << "cannot read " << argv[fileCount] << ": " << endl << "  no such file or directory" << endl;
			exit(1);
		}
	
		for(; !file.eof(); )
		{
			string tempWord;
			file >> tempWord;
	
			for(unsigned int i = 0; i < tempWord.length(); i++)
			{
				if(isalpha(tempWord[i]))
					tempWord[i] = tolower(tempWord[i]);
				//if not a letter;
				else
				{
					tempWord.erase(tempWord.begin() + i);
					continue;
				}
			}
	
			if(tempWord.length() > 0)
			{
				wordsIterator = words.find(tempWord);
				if(wordsIterator == words.end())
					words.insert({tempWord, 1});
				//if found, increment count;
				else
					wordsIterator->second++;
			}
		}
		file.close();
	}

	//vector of pairs initialized witih values of unordered_map words;
	vector<pair<string, int>> v(words.begin(), words.end());
	vector<pair<string, int>>::iterator vIterator = v.begin();
	sort(v.begin(), v.end(), compareCountThenLetter);

	for(unsigned int i = 0, j = 0; i < (unsigned int)atoi(argv[1]); j++)
	{
		if((vIterator + j)->first.length() < (unsigned int)atoi(argv[2]) || (vIterator + j)->first.length() > (unsigned int)atoi(argv[3]))
		{
			if(vIterator + j == v.end())
				break;
			else
				continue;
		}
		cout << (vIterator + j)->first << ": " << (vIterator + j)->second << endl;
		i++;
	}
}

//compare the second value (the int value in the pair);
//sort in descending order;
bool compareCountThenLetter(pair<string, int>a, pair<string, int>b)
{
	return (a.second > b.second) || (a.second == b.second && a.first < b.first);
}