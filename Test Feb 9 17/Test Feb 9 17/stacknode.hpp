//
//  stacknode.hpp
//  Test Feb 9 17
//
//  Created by danielle ryall on 2017-02-11.
//  Copyright © 2017 w0293490. All rights reserved.
//

#ifndef _STACKNODE_HPP
#define _STACKNODE_HPP

class StackNode
{
private:
    int _data;
    StackNode *_next;
    
public:
    StackNode();
    StackNode( int data, StackNode* next );
    virtual ~StackNode();
    
    int getData();
    void setData( int data );
    
    StackNode* getNext();
    void setNext( StackNode *next );
};

#endif
