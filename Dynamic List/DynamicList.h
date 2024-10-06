

#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include <iostream>

struct DynamicNode{
  int info;
  DynamicNode *next;
};

class DynamicList{
public:
	// constructors
	DynamicList(){	head = nullptr;} // default constructor

	// methods (inserts, deletes, print, search)
	void insertFirst(int x);

    void insertAfter(DynamicNode *p, int x);

    int deleteFirst();

    int deleteAfter(DynamicNode *p);

    bool isEmpty();

    void print();

    DynamicNode* search(int x);

    void removeX(int x);

    void insertLast(int x);

    DynamicNode* getNth(int pos);

    DynamicNode* findOrInsert(int x);

    void printReverse(DynamicNode *p);

    int count(DynamicNode *p);

    int mystery();

private:
	DynamicNode* head;
};

#endif
