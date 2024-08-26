#include<iostream>
#include "QueueDLL2.h"
#include "QueueDLL2.h"
using namespace std;
QueueDLL2::QueueDLL2()
{
	front = NULL;
	rear = NULL;
}
QueueDLL2::~QueueDLL2()
{
	Node* current = front;
	Node* nextNode;

	while (current != NULL)
	{
		nextNode = current->next;
		delete current;
		current = nextNode;
	}

	front = NULL;
	rear = NULL;
}
void QueueDLL2::insert(int x)
{
	if (front == NULL)
	{
		rear = new Node(x);
	}
	else
	{
		Node* t1 = new Node(x);
		t1->prev = rear;
		rear->next = t1;
		rear = t1;
	}
}
int QueueDLL2::service()
{
	Node* temp = front;
	if (front != NULL)
	{
		front - front ->next;
		front->prev = NULL;
		delete temp;
		if (front == NULL)
		{
			rear = NULL;
		}
	}
	else if(temp->next == NULL)
	{
		front = front->next;
		rear = front;
		delete temp;
	}
	else
	{
		cout << "Emptry queue\n";
		return -1;
	}
}
