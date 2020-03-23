#ifndef OUT_HH_
#define OUT_HH_

#include <vector>
#include <algorithm>

using namespace std;

/** Output a line containing "FOUND" if arg is found in [begin, end),
 *  otherwise output "NOT FOUND"..
 */
template <typename Iterator>
void loopFn(Iterator begin, Iterator end, int arg) {
	while(begin != end)
	{
		if(*begin == arg)
		{
			cout << "FOUND" << endl;
			return;
		}
		begin++;
	}
	cout << "NOT FOUND" << endl;
}

/** Exactly like loopFn() but no loops should be used */
template <typename Iterator>
void noLoopFn(Iterator begin, Iterator end, int arg) {
	if(find(begin, end, arg) != end)
		cout << "FOUND" << endl;
	else
		cout << "NOT FOUND" << endl;
}

#endif //ifndef OUT_HH_
