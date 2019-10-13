//
//  polynomial.hpp
//  Polynomial
//
//  Created by Deveshwar Singh on 10/13/19.
//  Copyright © 2019 Deveshwar Singh. All rights reserved.
//

#ifndef polynomial_h

#define polynomial_h
#include "node.h"

class polynomial{
private:
    node *head;
    node *tail;
    int size;
public:
    polynomial();
    polynomial(node &x, node &y);
    polynomial(const polynomial &x);
    ~polynomial();
    node* getHead();
    node* getTail();
    int getSize();
    void setSize(int x);
    void insert(node &x);
    void print()const;
    polynomial& operator=(polynomial &x);
    friend const polynomial& operator+(polynomial &x,polynomial &y);
    polynomial& operator-(polynomial &x);
};

#endif /* polynomial_h */
