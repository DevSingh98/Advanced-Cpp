//
//  node.hpp
//  Polynomial
//
//  Created by Deveshwar Singh on 10/13/19.
//  Copyright © 2019 Deveshwar Singh. All rights reserved.
//

#ifndef node_h
#define node_h

class node{
    
private:
    int coe;
    int exp;
    node *next;
public:
    node();//default constructor
    node(int x);//one argument constructor
    node(int x, int y);//two argument constructor
    node(int x, int y, node &p);//3* argument constructor
    node(const node &x);//copy constructor
    ~node();//destructor

    //Mutators
    void setCoe(int x);
    void setExp(int x);
    void setNext(node *x);
    
    //Accessors
    int getCoe();
    int getExp();
    node* getNext();
    
    //overloading operators
    node& operator=(node &x);//overload = operator
    bool operator<(const node &x);//overload < operator
    bool operator>(const node &x);//overload > operator
    bool operator==(node &x);//overload == operator
    bool operator!=(node &x);//overload != operator
    node& operator+(node &x);//overload + operator
    void print();
};

#endif /* node_h */
