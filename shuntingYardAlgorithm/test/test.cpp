/* C++ Language
Make a program that uses the Shunting-yard algorithim to turn infix notation to postfix notation.
*/

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	string infix;
	string postfix;
	stack<char> opStack;
	vector<char> postfixVector;
	char temp;
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int m = 0;
	int n = 0;
	int o = 0;
	int p = 0;
	int q = 0;
	int r = 0;
	int s = 0;
	int t = 0;
	int u = 0;
	int v = 0;
	int w = 0;
	int x = 0;
	int y = 0;
	int z = 0;

	cout << "Enter infix notation: ";
	cin >> infix;

	for (i = 0; i < infix.length(); i++)
	{
		if (infix[i] == '(')
		{
			opStack.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while (opStack.top() != '(')
			{
				postfixVector.push_back(opStack.top());
				opStack.pop();
			}
			opStack.pop();
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
		{
			while (!opStack.empty() && (opStack.top() == '+' || opStack.top() == '-' || opStack.top() == '*' || opStack.top() == '/' || opStack.top() == '^'))
			{
				postfixVector.push_back(opStack.top());
				opStack.pop();
			}
			opStack.push(infix[i]);
		}
		else
		{
			postfixVector.push_back(infix[i]);
		}
	}

	while (!opStack.empty())
	{
		postfixVector.push_back(opStack.top());
		opStack.pop();
	}

	for (j = 0; j < postfixVector.size(); j++)
	{
		postfix += postfixVector[j];
	}

	cout << "Postfix notation: " << postfix << endl;

	return 0;
}
