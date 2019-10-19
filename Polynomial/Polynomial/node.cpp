//
//  node.cpp
//  Polynomial
//
//  Created by Deveshwar Singh on 9/18/19.
//  Copyright © 2019 Deveshwar Singh. All rights reserved.
//


#include <stdio.h>
#include "node.h"
#include <iostream>

node::node(){//default constructor
    coe = NULL;
    exp = NULL;
    next = nullptr;
}

node::node(int x){//one argument constructor
    coe = x;
    exp = 1;
    next = nullptr;
}

node::node(int x, int y){//two argument constructor
    coe = x;
    exp = y;
    next = nullptr;
}

node::node(int x, int y,node &p){//three argument constructor
    coe = x;
    exp = y;
    next = &p;
}

node::node(const node &x){//copy constructor
    coe = x.coe;
    exp = x.exp;
    //next = x.next;
}

node::~node(){//deconstructor
    //delete next;
}


//mutators
void node::setCoe(int x){
    coe = x;
}

void node::setExp(int x){
    exp=x;
}

void node::setNext(node *x){
    next=x;
}


//accessors
int node::getCoe(){
    return this->coe;
}

int node::getExp(){
    
    if(this->exp == NULL){
        return 0;
    }
    
    else{
        return this->exp;
    }
}

node* node::getNext(){
    return next;
}


//operator overloads
node& node::operator=(node &x){
        this->coe = x.coe;
        this->exp = x.exp;
        this->next = x.next;
    return *this;
}

bool node::operator<(const node &x){
    if(this->exp < x.exp){
        return true;
    }
    else if(this->exp == x.exp && this->coe < x.coe){
        return true;
    }
    else{
        return false;
    }
}

bool node::operator>(const node &x){
    if(this->exp > x.exp){
        return true;
    }
    else if(this->exp == x.exp && this->coe > x.coe){
        return true;
    }
    else{
        return false;
    }
}


bool node::operator==(node &x){
    if(this->getExp() == x.getExp()){
        if(this->getCoe() == x.getCoe()){
            if(this->getNext() == x.getNext()){
                return true;
            }
        }
    }
    return false;
}

bool node::operator!=(node &x){
    if(this->getExp() != x.getExp()){
        return true;
    }
    else if(this->getCoe() != x.getCoe()){
        return true;
    }
    else if(this->getNext() != x.getNext()){
        return true;
    }
    else{
        return true;
    }
}

node& node::operator+(node &x){
    if(exp == x.exp){
        node *temp = new node();
        temp->exp = this->exp;
        temp->coe = this->coe +x.coe;
        return *temp;
    }
    else{
        throw "cannot add two different powers";
    }
}

void node::print(){
    std::cout<<this->getCoe()<<"x^"<<this->getExp()<<std::endl;
}

