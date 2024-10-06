// file: main.cpp
//   By: John Holik
// Desc: Source code for Practice With Stacks assignment
//  Org: COP 3530
// Date: 1/22/24

#include "Stack.h"
#include <iostream>




int main(){
    Stack name = Stack();
    // Last Name = Holik
    char array[6] = {"Holik"};

    // Loop to run through name array & push to stack
    std::cout << "Pushed Code:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        name.push(array[i]);
        std::cout << array[i];
    }
    std::cout<< std::endl << "Popped Code:" << std::endl;
    while(!name.empty()){
        // Loop to run through stack and pop
        std::cout<< name.pop();
    }
}

