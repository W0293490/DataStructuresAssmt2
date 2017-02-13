//
//  stacknode.cpp
//  Test Feb 9 17
//
//  Created by danielle ryall on 2017-02-11.
//  Copyright © 2017 w0293490. All rights reserved.
//

#include "stacknode.hpp"
#include "stdafx.hpp"
#include <iostream>
#include "stacknode.hpp"

using namespace std;

StackNode::StackNode() : _data(0), _next(NULL)
{
}

StackNode::StackNode( int data, StackNode* next ) : _data(data), _next(next)
{
}

StackNode::~StackNode()
{
}

int StackNode::getData()
{
    return _data;
}

void StackNode::setData( int data )
{
    _data = data;
}

StackNode* StackNode::getNext()
{
    return _next;
}

void StackNode::setNext( StackNode *next )
{
    _next = next;
}
