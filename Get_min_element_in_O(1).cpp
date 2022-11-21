#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class my_stack{

	stack<int> s ;

	int minEle ;

	public:

	void getMin()
	{
		if(s.empty())
			cout << "Stack is empty" << endl;
		else
			cout << "Minimum element in the stack is :"<<minEle << endl;
	}

	void peek()
	{
		if(s.empty()){
			cout << "Stack is empty" << endl;
			return;
		}

		int t = s.top();

		cout << "Top most element is:"  ;

		(t < minEle)? cout << minEle: cout << t ;
	}

	void pop()
	{
		if (s.empty())
		{
			cout << "Stack is empty" << endl;
			return ;
		}

		cout << "Topmost element removed :";

		int t = s.top();

		s.pop();

		if (t < minEle)
		{
			cout << minEle << endl;
			minEle = 2*minEle - t ;
		}

		else
			cout << t << endl;
	}

	void push(int x)
	{
		if (s.empty())
		{
			minEle = x;
			s.push(x);
			cout << "Number inserted :" << x << endl;
			return ;
		}

		else if (x < minEle)
		{
			s.push(2*x - minEle);
			minEle = x;
		}
		else
			s.push(x);

		cout << "Number inserted :" << x << endl;
	}

};

int main()
{
	my_stack s;

	s.push(3);
	s.push(5);
	s.getMin();
	s.push(2);
	s.push(1);
	s.getMin();
	s.pop();
	s.getMin();
	s.pop();
	s.peek();
	return 0;
}