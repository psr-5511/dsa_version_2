#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

// function to return the precedence of operators 

int prec(char c)
{
	if(c=='^') return 3;

	else if(c=='+' || c=='-') return 1;

	else if(c=='*' || c=='/') return 2 ;

	else return -1;
}

// main function to convert infix expression to postfix expression

void infix_to_postfix(string str)
{

	stack<char> s;

	string s1 = "";

	for (int i = 0; i < str.length(); ++i)
	{
		char c = str[i];


		// if '(' is found push it in stack 
		if(c=='(') s.push(c);

		// if the scanned character is an operand , then add it  to output string 
		else if(c>= 'a' && c<='z' || c>= 'A' && c<='Z' || c>='0' && c=='9') s1+=c;

		// if the scanned character is ')' then start popping the stack until an '(' is recieved 
		else if(c==')')
		{
			while(s.top()!= '(')
			{
				s1+=s.top();
				s.pop();
			}
			s.pop();
		}

		// if operator is recieved then check it's precedence if it is greater than the top element of stack then push it to the stack else keep popping from the stack and print till lower precedence operator is found .
		else{
			while(!s.empty() && prec(c) <= prec(s.top()))
			{
				s1 += s.top();
				s.pop();
			}
			s.push(c);
		}


	}

	// once expression is completed , keep popping from the stack and print it . 
	while(!s.empty())
	{
		s1 += s.top();
		s.pop();
	}

	cout << s1 << endl;

}

int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i";

	infix_to_postfix(exp);
	return 0;
}

// time complexity : O(N)
// reason : N is the size of infix expression 

// space complexity : O(N)


// https://www.geeksforgeeks.org/convert-infix-expression-to-postfix-expression/
