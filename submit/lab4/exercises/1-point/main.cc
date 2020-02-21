#include "point.hh"
#include <sstream>
#include <iostream>
using namespace std;

class Line
{
	public:
		Point p1, p2;

		Line(Point p, Point pp) : p1(p), p2(pp) {}
		double length();
		string toString();	
};

double Line::length()
{
	return p1.distance(p2);
}

string Line::toString()
{
	string str = "";
	str = p1.toString() + " -- " + p2.toString();
	return str;
}

//declare an array of points
static const Point points[] = {
  Point(0, 0), Point(3, 4), Point(1, 1), Point(4, 5),
};
//use standard idiom to figure out number of elements in array
static constexpr auto nPoints = sizeof(points)/sizeof(points[0]);

static void
outSizes(std::ostream& out) {
  out << "sizeof(double) = " << sizeof(double) << std::endl;
  out << "sizeof(Point) = " << sizeof(Point) << std::endl;
}

/** output pair-wise distance between all points in points[] to out. */
static void
outDistances(std::ostream& out)
{
  for (auto i = 0u; i < nPoints - 1; i++) {
    Point pi = points[i];
    for (auto j = i + 1; j < nPoints; j++) {
      Point pj = points[j];
      out << "distance from " << pi.toString()
	  << " to " << pj.toString()
	  << " is " << pi.distance(pj)
	  << std::endl;
    }
  }
}

int main() {

  //instead of hardcoding std::cout in functions, we pass it as a param.
  //so if we wanted to output to a file, the code for the functions
  //would not need to change (the code in this function would change).
  
  //std::ostream& out = std::cout;

  //outDistances(out); out << std::endl;

  //outSizes(out);
  unsigned int size = nPoints;
  if(nPoints % 2 != 0)
	  size = nPoints - 1;
  for(unsigned int i = 0; i < size - 1; i += 2)
  {
	  Line l(points[i], points[i+1]);
	  cout << l.toString() << " length = " << l.length() << endl;
  }
}
