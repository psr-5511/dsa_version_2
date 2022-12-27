#include<iostream>
using namespace std;
#define endl "\n"

class Node{
public:
	int data ;
	Node* next ;
};

class my_stack{
public:
	Node* head ;
	Node* tail ;

	my_stack()
	{
		head = NULL;
		tail = NULL;
	}
};

my_stack* create()
{
	my_stack* st = new my_stack();
}

void push(int data , my_stack* ms)
{
	Node* temp = new Node();
	temp -> data = data;

	temp -> next = ms ->head ;

	if(ms -> head == NULL)
		ms -> tail = temp ;

	ms -> head = temp ;
}

int pop(my_stack* ms)
{
	if(ms -> head == NULL)
	{
		cout << "stack underflow" << endl ;
		return 0 ;
	}

	else
	{
		Node* temp = ms -> head ;

		ms -> head = ms->head -> next ;

		int popped = temp -> data ;

		delete temp ;

		return popped ;
	}
}

void merge(my_stack* ms1 , my_stack* ms2)
{
	if(ms1 -> head == NULL)
	{
		ms1->head = ms2->head;
		ms1->tail = ms2->tail;
		return ;
	}

	ms1->tail->next = ms2->head;
	ms1->tail = ms2->tail ;
}

void display(my_stack* ms)
{
	Node* temp = ms->head;
	while(temp != NULL)
	{
		cout << temp->data ;
		temp = temp->next;
		if(temp != NULL)
			cout <<"->";
	}
}


int main()
{
	my_stack* ms1 = create();
	my_stack* ms2 = create();

	push(6,ms1);
	push(5,ms1);
	push(4,ms1);
	push(9,ms2);
	push(8,ms2);
	push(7,ms2);

	merge(ms1,ms2);
	display(ms1);

	return 0;
}

// article link : https://www.geeksforgeeks.org/create-mergable-stack/