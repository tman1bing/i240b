#include <iostream>
#include <string>
#include <algorithm>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <utility>
using namespace std;

typedef set<string> FileNames;

map<string, int> 
readNums(vector<string> fileNames)
{
  map<string, int> m; //empty collection
  for (auto fileName : fileNames) { //let compiler figure out fileName is string
    ifstream in(fileName); //open file
    if (!in) {
      cerr << "cannot read \"" << fileName << "\"" << endl;
      exit(1);
    }
    int i;
    while (in >>i) {
	    if(m.find(fileName) != m.end())
      		m.find(fileName)->second += i;
	    else
		    m.insert(pair<string, int>(fileName, i));
    }
    if (!in.eof()) {
      cerr << "i/o error on file \"" << fileName << "\"" << endl;
      exit(1);
    }
  } //for
  return m;
}
/*
static ostream&
operator<<(ostream& out, const set<string>& set)
{
  for (auto element : set) { out << element << " "; }
  return out;
}
*/
static void
interact(const map<string, int>& m)
{
  string s;
  cout << ">> ";
  while (cin >> s) {
    try {
      if(m.find(s) != m.end())
      	cout << s << ": " << m.find(s)->second << endl;
      else
	      cout << s << ": " << "cannot be NOT FOUND" << endl;
    }
    catch (out_of_range& err) {
      cout << s << ": " << "NOT FOUND" << endl;
    }
    cout << ">> ";
  } //while
}

int
main(int argc, char* argv[])
{
  if (argc < 2) {
    cerr << "usage: " << argv[0] << " FILE..." << endl;
    exit(1);
  }
  auto map = readNums(vector<string>(&argv[1], &argv[argc]));
  interact(map);
}

