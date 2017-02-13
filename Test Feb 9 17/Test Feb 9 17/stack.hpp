//
//  stack.hpp
//  Test Feb 9 17
//
//  Created by danielle ryall on 2017-02-11.
//  Copyright © 2017 w0293490. All rights reserved.
//

#ifndef _STACK_HPP
#define _STACK_HPP

#include <iostream>
#include "stacknode.hpp"

using namespace std;
enum myerror_code { success, underflow, overflow };

class Stack
{
private:
    StackNode *_top;
    
public:
    Stack();
    virtual ~Stack();
    
    myerror_code Push( int num );
    int Peek();
    myerror_code Pop();
    
    friend ostream& operator<<( ostream& output, Stack& stack );
};

#endif
