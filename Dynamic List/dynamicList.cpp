// File: dynamicList.cpp
//   By: John Holik
// Desc: An implementation of the DynamicList.h file
//Class: COP 3530

#include "DynamicList.h"
#include <iostream>

// inserts x at the beginning of the list
void DynamicList::insertFirst(int x) {
	DynamicNode* q = new DynamicNode;
	q->info = x;
	q->next = head;
	head = q;
}// insertFirst


// Insert x at the end of the list
void DynamicList::insertLast(int x) {
    DynamicNode* q = new DynamicNode;
    q->info = x;
    q->next = nullptr;
    DynamicNode* temp = nullptr;
    if (isEmpty()){
        head =  q;
    } else{
        for(temp = head; temp->next != nullptr; temp = temp->next);// empty loop
        }
        temp->next = q;
} // insertLast


// isEmpty
bool DynamicList::isEmpty(){
    if(head == nullptr){
        return true;
    } else
        return false;
}


void DynamicList::print() {
    // Loop through nodes till null
    DynamicNode* temp = head;

    std::cout << "Head: " << head << "\n";

    while(temp !=nullptr){
        std::cout << temp->info << " ";
        temp = temp->next;
    }
    std::cout << "\n";
} //Print


DynamicNode* DynamicList::search(int x) {
    DynamicNode* temp = head;
    while(temp !=nullptr){
        if(temp->info == x)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}// Search


void DynamicList::removeX(int x) {
    DynamicNode* temp = head;
    while(temp !=nullptr){
        if(temp->info == x)

        temp = temp->next;
    }
}// removeX


// Delete after x
int DynamicList::deleteAfter(DynamicNode *p){
    if(isEmpty()){
        std::cout << "The list is empty, there is nothing to delete";
    } else{

    }


}// deleteAfter


// get the Nth node and return its value
DynamicNode* DynamicList::getNth(int pos) {
    DynamicNode* temp = head;

    if(temp == nullptr){ // check if the list is empty
        std::cout<< "The list is empty there are no values to return";
        return nullptr;
    }else{
        for(int count = 0; count != pos; count++) // runs through list until it reaches the requested position
            temp = temp->next;
        if(temp != nullptr){ // if there is a value at that position return it
            std::cout<< "The value of index " << pos << " is: " << temp->info << "\n";
            return temp;
        }else // if there is not a value at that position return an error message
            std::cout << "The list does not contain a value at index " << pos << "\n";
        return nullptr;
    }
} // getNth

// findOrInsert
DynamicNode* DynamicList::findOrInsert(int x) {
    DynamicNode* temp = head;
    DynamicNode* q = new DynamicNode;
    q->info = x;
    q->next = nullptr;

    if (temp == nullptr) {
        head = q;
        std::cout << "The list was empty, inserted the value " << x << " at the head." << "\n";
        return q;
    } else {
        while (temp->next != nullptr) {
            if (temp->info == x) {
                std::cout << "The value " << x << " was found at " << temp << "\n";
                delete q;
                return temp;
            }
            temp = temp->next;
        }

        // Now temp points to the last node in the list
        if (temp->info == x) {
            std::cout << "The value " << x << " was found at " << temp << "\n";
            delete q;
            return temp;
        } else {
            temp->next = q;
            std::cout << "The value " << x << " was not found in the original list. Inserted at the end." << "\n";
            return q;
        }
    }
}// findOrInsert


// printReverse
void DynamicList::printReverse(DynamicNode* nd) {
    if(nd == nullptr)
        return;
    else {
        printReverse(nd->next);
        std::cout << nd->info << "";
    }
}// printReverse


// count
int DynamicList::count(DynamicNode *p) {
    // int counter = 0; not needed
    if (p == nullptr){
        return 0;
    }
    return 1 + count(p->next); // 1 is stored in the stack
}


int DynamicList::mystery() {
    int return_val = -1; // some error code
    if (head == nullptr) {
        return return_val; // some error code
    }
    else {
        DynamicNode* current = nullptr;
        DynamicNode* temp1 = head;
        DynamicNode* temp2 = head;

        while (temp2->next != nullptr) {
            current = temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
            if (temp2->next == nullptr) {
                return return_val; // some error code
            }
            else {
                temp2 = temp2->next;
            }
        }


        if (current == nullptr) {  // only 1 value in list
            return_val=head->info;
            head = nullptr;
            delete temp1;
        } else {
            return_val=temp1->info;
            current->next = temp1->next;
            delete temp1;
        }
        return return_val;
    }
}




int main()
{
    DynamicList newList = DynamicList();


//    newList.insertFirst(6);
//    newList.insertFirst(7);
//    newList.insertLast(10);
//    newList.print();
//    newList.findOrInsert(6);
//    newList.print();


   // newList.insertFirst(5);
    newList.insertFirst(4);
    newList.insertFirst(3);
    newList.insertFirst(2);
    newList.insertFirst(1);
    newList.print();

    std::cout << newList.mystery();






    // test inserts
//    newList.insertFirst(1);
//    newList.insertFirst(2);
//    newList.insertFirst(5);
//    newList.insertFirst(3);
//    std::cout << "The list after inserts: ";
//    newList.print();
//    newList.findOrInsert(10);
//    newList.print();
//   newList.findOrInsert(1);
//   newList.print();
//   newList.getNth(3);
//   newList.getNth(4);
//    std::cout << "Find the value 5 in the list: ";
//    std::cout << newList.search(5);
//    std::cout << "Insert the value 10 at the end of the list: ";
//    newList.insertLast(10);
//    newList.print();


}// Main