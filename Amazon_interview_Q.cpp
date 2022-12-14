#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

const int MAXX = 1000 ;

class St{
	int minn ;
	int size ;

public:

	St(){
		minn = 99999;
		size = -1;
	}

	vector<pair<int, int>> arr ;

	int GetLastElement();
	int RemoveLastElement();
	int AddElement(int element);
	int GetMin();
};

// utility function for adding a new element 

int St::AddElement(int element)
{
	if (size > MAXX)
	{
		cout << "St overflow , max size reached!\n";
		return 0 ;
	}

	if (element < minn)
	{
		minn = element;
	}

	arr.push_back(make_pair(element , minn));

	size++;

	return 1 ;

}

// utility function for removing the last element of St 

int St ::GetLastElement()
{
	if (size == -1)
	{
		cout << "St is empty \n";
		return 0 ;
	}

	return arr[size].first;
}

// utility function for removing last element successfully

int St::RemoveLastElement()
{

	if (size == -1)
	{
		cout << "St empty\n";
		return 0 ;
	}

	if (size > 0 && arr[size -1].second > arr[size].second)
	{
		minn = arr[size -1].second ;
	}

	arr.pop_back();

	size -= 1 ;
	return 1;
}

int St::GetMin()
{
	if (size == -1)
	{
		cout << "St overflow!!\n";
		return 0 ;
	}
	return arr[size].second;
}


int main()
{
	St s;

	int success = s.AddElement(5);

	if (success == 1)
        cout << "5 inserted successfully\n";
 
    success = s.AddElement(7);
    if (success == 1)
        cout << "7 inserted successfully\n";
 
    success = s.AddElement(3);
    if (success == 1)
        cout << "3 inserted successfully\n";
    int min1 = s.GetMin();
    cout << "min element  :: " << min1 << endl;
 
    success = s.RemoveLastElement();
    if (success == 1)
        cout << "removed successfully\n";
 
    success = s.AddElement(2);
    if (success == 1)
        cout << "2 inserted successfully\n";
 
    success = s.AddElement(9);
    if (success == 1)
        cout << "9 inserted successfully\n";
    int last = s.GetLastElement();
    cout << "Last element :: " << last << endl;
 
    success = s.AddElement(0);
    if (success == 1)
        cout << "0 inserted successfully\n";
    min1 = s.GetMin();
    cout << "min element  :: " << min1 << endl;
 
    success = s.RemoveLastElement();
    if (success == 1)
        cout << "removed successfully\n";
 
    success = s.AddElement(11);
    if (success == 1)
        cout << "11 inserted successfully\n";
    min1 = s.GetMin();
    cout << "min element  :: " << min1 << endl;
	return 0;
}

// Time complexity: Each function runs in O(1)

// Auxiliary space: O(n) for stack