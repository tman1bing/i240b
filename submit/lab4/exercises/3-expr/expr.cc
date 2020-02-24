#include "expr.hh"

#include <string>
#include <sstream>
using namespace std;

int AddExpr::eval()
{
	int leftEval = left->eval();
	int rightEval = right->eval();
	return leftEval + rightEval;
}

std::string
IntExpr::toString() const
{
  std::stringstream s;
  s << value;
  return s.str();
}

static std::string
binaryExprToString(std::string op, ExprPtr left, ExprPtr right)
{
  std::stringstream s;
  s << "(" << *left << ") " << op << " (" << *right << ")";
  return s.str();
}

std::string
AddExpr::toString() const
{
	cout << eval() << endl;
  return binaryExprToString("+", left, right);
}

std::string
SubExpr::toString() const
{
  return binaryExprToString("-", left, right);
}

std::string
MulExpr::toString() const
{
  return binaryExprToString("*", left, right);
}

std::string
DivExpr::toString() const
{
  return binaryExprToString("/", left, right);
}

