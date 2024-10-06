#include "DynamicQueue.h"
#include <iostream>
#include <stdlib.h>

//-------------------------------------------------------------------------------
// constructors
//-------------------------------------------------------------------------------
/********************************************************************************
default constructor
********************************************************************************/
DynamicQueue::DynamicQueue() {
	front = nullptr;
	rear = nullptr;
}

//---------------------------------------------------------------
// methods (inserts and deletes)
//---------------------------------------------------------------
bool DynamicQueue::empty() {
	return (front == nullptr);
}

void DynamicQueue::insert(int x) {
	DynamicNode* p = new DynamicNode;
	p->info =x;
	p->next = nullptr;

	if (empty()) {
		front = p;
	}
	else {
		rear->next = p;
	}

	rear = p;
}

int DynamicQueue::remove() {
	if (empty()) {
		std::cout << "queue underflow";
		exit(1);
	}

	DynamicNode* p = front;
	int temp = p->info;
	front = p->next;
	delete p;
	if (front == nullptr)
		rear = nullptr;

	return temp;
}
