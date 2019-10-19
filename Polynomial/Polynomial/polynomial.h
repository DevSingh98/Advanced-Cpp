//
//  polynomial.hpp
//  Polynomial
//
//  Created by Deveshwar Singh on 9/18/19.
//  Copyright © 2019 Deveshwar Singh. All rights reserved.
//

#ifndef polynomial_h

#define polynomial_h
#include "node.h"
#include <iostream>

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
    void copy(polynomial &x);
    void insert(node &x);
    void print()const;
    void print(std::string s);
    polynomial(std::string p1);
    polynomial& operator=(polynomial &x);
    friend polynomial& operator+(polynomial &x,polynomial &y);
    friend polynomial& operator-(polynomial &x, polynomial &y);
    friend polynomial& operator*(polynomial &x, polynomial &y);
};

#endif /* polynomial_h */
