#include<iostream>
#include<stack>
using namespace std;
#define endl "\n"

char* reverse(char *s , int len)
{
	stack<char> st; 

	

	for (int i = 0; i < len; ++i)
		st.push(s[i]);

	for (int i = 0; i < len; ++i)
	{
		s[i] = st.top();
		st.pop();
	}
	return s;
}

int main()
{
	int n ; cin >> n ;

	char  str[n] ;

	cin >> str; 

	int len = sizeof(str)/ sizeof(char);

	char* res = reverse(str, len);

	for (int i = 0; i < len; ++i)
	{
		if(res[i] == NULL)
			continue;
		else
			cout << res[i];
	}
	return 0;
}

/*

 Time Complexity: O(N)
 Auxiliary Space: O(N)

*/

// article link : https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1