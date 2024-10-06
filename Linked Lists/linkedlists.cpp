#include "DynamicList.h"
#include <iostream>

// inserts x at the beginning of the list
void DynamicList::insertFirst(int x) {
	DynamicNode* q = new DynamicNode;
	q->info = x;
	q->next = head;
	head = q;
}

int main()
{
    DynamicList newList = DynamicList();
    
    newList.print();

    // test inserts
    newList.insertFirst(1);
    newList.insertFirst(2);
    newList.insertFirst(5);
    newList.insertFirst(3);

    std::cout << "The list after inserts: ";
    newList.print();
}