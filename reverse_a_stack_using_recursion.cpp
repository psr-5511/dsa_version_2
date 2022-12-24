#include<iostream>
#include<stack>
using namespace std;
#define endl "\n"

void insert_at_bottom(stack<int>& st , int element)
{
	if(st.size() == 0)
		st.push(element);
	else
	{
		int a = st.top();
		st.pop();

		insert_at_bottom(st , element);

		st.push(a);

	}
}

void reverse(stack<int>& st)
{
	if(st.size() > 0)
	{
		int x = st.top();
		st.pop();

		reverse(st);

		insert_at_bottom(st , x);
	}
	return ;
}

int main()
{
	stack<int> st , st2 ;

	for (int i = 1; i <=4; ++i)
	{
		st.push(i);
	}

	st2 = st;

	cout << "Original stack: ";

	while(!st2.empty())
	{
		cout << st2.top() << " ";
		st2.pop();
	}


	reverse(st);

	cout << "Reversed stack : ";

	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}

/*
	time complexity : O(N*N)

	space complexity : O(N) use of stack 
*/

// article link : https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/