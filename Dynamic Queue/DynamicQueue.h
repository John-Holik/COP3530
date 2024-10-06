#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

struct DynamicNode{ // node is the same as in the dynamic list code 
  int info;
  DynamicNode *next;
};

class DynamicQueue {
public:
	//---------------------------------------------------------------
	// constructors
	//---------------------------------------------------------------
	DynamicQueue();

	//---------------------------------------------------------------
	// methods (inserts and deletes)
	//---------------------------------------------------------------
	bool empty();
	void insert(int x);
	int remove();

private:
	DynamicNode* front;
	DynamicNode* rear;
};
#endif

