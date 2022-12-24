#include<iostream>
#include <stack>
using namespace std;
#define endl "\n"

string reverseWords (string s)
{
	stack<char>st;

	string res="";

	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='.')
		{

			while(!st.empty())
			{
				res+=st.top();

				st.pop();
			}

			res+='.';

		}

		else{

			st.push(s[i]);

		}

	}

	if(!st.empty()){

		while(!st.empty()){

			res+=st.top();

			st.pop();

		}

	}

	return res;
}

int main()
{
	string S  = "i.like.this.program.very.much";

	string res = reverseWords(S);

	cout << res << endl;

	return 0;
}


// article - https://practice.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string1001/1