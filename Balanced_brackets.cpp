#include<iostream>
#include <stack>
using namespace std;
#define endl "\n"

bool balanced(string str)
{
	// declare a stack to hold previous brackets 
	stack<char> st;

	for (int i = 0; i < str.length(); i++)
	{
		// if the stack is empty just push the brackets 
		if(st.empty()) st.push(str[i]);

		// if we found any complete pair of brackets then pop
		else if (str[i] == ')' && st.top() == '(' || str[i] == ']' && st.top() == '[' || str[i] == '}' && st.top() == '{')
		{
			st.pop();
		}

		else st.push(str[i]);
	}


	// if stack is empty return true
	if(st.empty()) return true;

	else return false;

}

int main()
{
	string expr = "{()}[]";

	if(balanced(expr)) cout<<"balanced";
	else cout<<"not-balanced";
	return 0;
}

// Time Complexity: O(N), Iteration over the string of size N one time.
// Auxiliary Space: O(N) for stack. 

// article link : https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/