#include<iostream>
#include <stack>
using namespace std;
#define endl "\n"

// function to check if character is operator or not 

bool isOperator(char c){
	switch(c){
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
			return true;
	}

	return false;
}

// convert prefix to infix 

string convert_to_infix(string s)
{
	stack<string> st;
	for (int i = s.length(); i >=0; i--)
	{
		// check if symbol is an operator 
		if (isOperator(s[i]))
		{
			// pop two operands from stack 
			string op1 = st.top(); st.pop();

			string op2 = st.top(); st.pop();

			// concat the operands and the operator 
			string temp = "(" + op1 + s[i] + op2 + ")";

			// push string temp back to stack
			st.push(temp);
		}

		// if symbol is an operand 
		else{
			// push the operand to the stack 
			st.push(string(1,s[i]));
		}
	}

	// stack now contains the infix expression 
	return st.top();
}

int main()
{
	string pre_exp =  "*-A/BC-/AKL";
	
	cout << "Infix:" << convert_to_infix(pre_exp);
	return 0;
}

// time complexity : O(n)

// space complexity : O(n)