#include<iostream>
#include <stack>
using namespace std;
#define endl "\n"

bool is_operand(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// get infix for a postix expression

string get_infix(string s)
{
	stack<string> st;
	for (int i = 0; i < s.length(); ++i)
	{
		if(is_operand(s[i])) st.push(string(1,s[i]));

		else
		{
			string op1 = st.top(); st.pop();

			string op2 = st.top(); st.pop();

			st.push("(" + op2 + s[i] + op1 + ")");
		}
	}

	// there must be a single element which is the required infix .
	return st.top();
}

int main()
{
	string exp = "ab*c+";

	cout << get_infix(exp);
	return 0;
}

// Time Complexity: O(N) where N is the length of the string

// Auxiliary Space: O(N) where N is the stack size.


// article link : https://www.geeksforgeeks.org/postfix-to-infix/