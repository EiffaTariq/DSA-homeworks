#include<iostream>
#include"Node.h"
#ifndef QUEUEDLL2_H
#define QUEUEDLL2_H
class QueueDLL2
{
	Node* front;
	Node* rear;
public:
	QueueDLL2();
	bool isEmpty()const
	{
		return rear == nullptr;
	}
	void insert(int x);
	int service();
	~QueueDLL2();
};
#endif