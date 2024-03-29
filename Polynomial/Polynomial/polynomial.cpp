//
//  polynomial.cpp
//  Polynomial
//
//  Created by Deveshwar Singh on 9/18/19.
//  Copyright © 2019 Deveshwar Singh. All rights reserved.
//

#include "polynomial.h"
#include <iostream>
using namespace std;
polynomial::polynomial(){
    head = nullptr;
    tail = nullptr;
    size =0;
}


polynomial::polynomial(node &x, node &y){
    this->head = &x;
    (*head).setNext(&y);
    tail = &y;
    size =2;
}

polynomial::~polynomial(){
    if(size==1){
        //delete head;
    }
    //delete head;
    //delete tail;
}

polynomial::polynomial(const polynomial &x){
    this->head = x.head;
    this->tail = x.tail;
    this->size = x.size;
}

node* polynomial::getHead(){
    return this->head;
}

node* polynomial::getTail(){
    return this->tail;
}

void polynomial::setSize(int x){
    this->size =x;
}

int polynomial::getSize(){
    return this->size;
}

void polynomial::insert(node &x){
    node *temp = new node();
    temp->setCoe(x.getCoe());
    temp->setExp(x.getExp());
    if(this->size ==0){ //empty
        this->head = temp;
        this->tail = temp;
        this->size++;
    }
    else if(this->size ==1){ //one term
        if((*(this->tail)).getExp() == x.getExp()){
            (*(this->tail)).setCoe((*(this->tail)).getCoe() + x.getCoe());
        }
        else if((*(this->tail)).getExp() < x.getExp()){
            head = temp;
            temp->setNext(this->tail);
            this->size++;
        }
        else{
            tail = temp;
            (*(this->head)).setNext(tail);
            this->size++;
        }
    }
    else if(this->size ==2){ // two terms
        if((*(this->tail)).getExp() == x.getExp()){//if exp same as tail
            (*(this->tail)).setCoe((*(this->tail)).getCoe() + x.getCoe());
        }
        else if((*(this->tail)).getExp() > x.getExp()){//tail is bigger then incoming
            (*(this->tail)).setNext(temp);
            tail = temp;
            this->size++;
         }
        
         else if( (*(this->tail)).getExp() < x.getExp() &&
             (*(this->head)).getExp() > x.getExp() ){//if tail is smaller but head is larger
             ((*this->head)).setNext(temp);
             temp->setNext(tail);
             this->size++;
         }
        
         else if((*(this->head)).getExp() == x.getExp()){ //same size as head, combine
             (*(this->head)).setCoe((*(this->head)).getCoe() + x.getCoe());
         }
         else if((*(this->head)).getExp() < x.getExp()){
             temp->setNext(this->head);
             head = temp;
             this->size++;
         }
    }
    else{//more then 2 terms
        int count =1;
        node *pointer;
        pointer =this->head;
        //pointer starts at the head
        
        if((*pointer).getExp()< x.getExp()){ //if input is biggest term
            temp->setNext(this->head);
            head = temp;
            this->size++;
        }
        
        else if((*(this->tail)).getExp() > x.getExp()){//tail is bigger then incoming
           (*(this->tail)).setNext(temp);
           tail = temp;
           this->size++;
        }
        
        else{
            while(count != this->size+1){
                if((*pointer).getExp() == x.getExp()){//if input has the same power
                    (*pointer).setCoe((*pointer).getCoe() + x.getCoe());
                    break;
                }
                else if(((*pointer).getExp() > x.getExp()) && ((*(pointer->getNext())).getExp() < x.getExp())){
                    temp->setNext((pointer->getNext()));
                    pointer->setNext(temp);
                    this->size++;
                    break;
                }
                else{
                    pointer =  (*pointer).getNext();
                    count++;
                    
                }
            }
        }
    }
}



polynomial::polynomial(std::string p1){
    int size1 = p1.length();
    int count =0;
    bool iscoe = true;
    int coe;
    int exp;
    bool pair =false;
    while(count < size1){
        if(p1[count] != ' '){
            if(iscoe==true){
                if(p1[count]=='-'){
                    count++;
                    coe = -(p1[count]%48);
                    iscoe=false;
                    count++;
                }
                else{
                    coe = (p1[count]%48);
                    iscoe=false;
                    count++;
                }
            }
            else if(iscoe ==false){
                if(p1[count]=='-'){
                    count++;
                    exp = -(p1[count]%48);
                    iscoe=true;
                    node *temp = new node();
                    temp->setCoe(coe);
                    temp->setExp(exp);
                    this->insert(*temp);
                    count++;
                }
                else{
                    exp = (p1[count]%48);
                    iscoe=true;
                    count++;
                    node *temp = new node();
                    temp->setCoe(coe);
                    temp->setExp(exp);
                    this->insert(*temp);
                }
            }
        }
        else{
            count++;
        }
    }
};

void polynomial::print() const{
    node *temp = this->head;
    int count = 1;
    while (count<=this->size) {
        if(count ==1 && temp->getCoe() != 0){
            std::cout << (temp->getCoe()) << "x^"<< (temp->getExp());
        }
        
        else if(temp->getCoe() > 0){
            std::cout << "+"<< (temp->getCoe()) << "x^"<< (temp->getExp());
        }
        else if(temp->getCoe() < 0){
            std::cout<< (temp->getCoe()) << "x^"<< (temp->getExp());
        }
        if( count != size)
        temp = temp->getNext();
        count++;
    }
    std::cout<<std::endl;
}

polynomial& polynomial::operator=(polynomial &x){
    node *temp = new node();
    *temp = *head;
    node temp2 = node();
    temp2 = *((*temp).getNext());

    
    int count=2;
    while(count<x.size){
        this->insert(*temp);
        temp->setCoe((temp2).getCoe());
        temp->setExp((temp2).getExp());
        count++;
    }
    this->insert(*(x.tail));
    this->size = x.size;
    
    return *this;
}


polynomial& operator+(polynomial &x, polynomial &y){//make a friend function
    polynomial *temp = new polynomial();

    node *pointer = new node();
    pointer = x.getHead();
    node *next = new node();
    next = x.getHead();
    int size = x.getSize();
    int count =1;
    
    while(count < size){
        next = (*next).getNext();
        temp->insert(*pointer);
        pointer = next;
        count++;
    }
    temp->insert(*next);
    
    
    node *pointery = new node();
    pointery = y.getHead();
    node *nexty = new node();
    nexty = y.getHead();
    int sizey = y.getSize();
    int county =1;
        
    while(county < sizey){
        nexty = (*nexty).getNext();
        temp->insert(*pointery);
        pointery = nexty;
        county++;
    }
    temp->insert(*nexty);
    

    return *temp;
}




polynomial& operator-(polynomial &x, polynomial &y){
    
    polynomial *temp = new polynomial();
    node *pointer = new node();
    pointer = x.getHead();
    node *next = new node();
    next = x.getHead();
    int size = x.getSize();
    int count =1;
    while(count < size){
        next = (*next).getNext();
        temp->insert(*pointer);
        pointer = next;
        count++;
    }
    temp->insert(*next);
    
    node *pointery = new node();
    pointery = y.getHead();
    node *nexty = new node();
    nexty = y.getHead();
    int sizey = y.getSize();
    int county =1;
           
    while(county < sizey){
        node *temp2 = new node();
        temp2->setExp(pointery->getExp());
        nexty = (*nexty).getNext();
        temp2->setCoe((*pointery).getCoe()*-1);
        temp->insert(*temp2);
        pointery = nexty;
        county++;
    }
    node *temp3 = new node();
    (*temp3).setCoe((*nexty).getCoe()*-1);
    temp->insert(*temp3);
       

    return *temp;
}


polynomial& operator*(polynomial &x, polynomial &y){
    polynomial *temp = new polynomial();
    //polynomial *temp2 = new polynomial();
    node *pointery = new node();
    pointery = y.getHead();
    node *nexty = new node();
    nexty = y.getHead();
    int sizey = y.getSize();
    int county =1;
       
    while(county < sizey){
        node *pointer = new node();
        pointer = x.getHead();
        node *next = new node();
        int size = x.getSize();
        next = x.getHead();
        int count =1;
        while(count < size){
            next = (*next).getNext();
            node *t = new node();
            t->setCoe(pointer->getCoe() * pointery->getCoe());
            t->setExp(pointer->getExp() + pointery->getExp());
            temp->insert(*t);
            pointer = next;
            count++;
        }
        node *t = new node();
        t->setCoe(pointer->getCoe() * pointery->getCoe());
        t->setExp(pointer->getExp() + pointery->getExp());
        temp->insert(*t);
        nexty = (*nexty).getNext();
        pointery = nexty;
        county++;
    }
    
    int count = x.getSize();
    node *pointer = new node();
    pointer = x.getHead();
    node *next = new node();
    next = x.getHead();
    int size = x.getSize();
    while(count < size){
        next = (*next).getNext();
        node *t = new node();
        t->setCoe(pointer->getCoe() * pointery->getCoe());
        t->setExp(pointer->getExp() + pointery->getExp());
        temp->insert(*t);
        pointer = next;
        count++;
    }
    next = (*next).getNext();
    node *t = new node();
    t->setCoe(pointer->getCoe() * pointery->getCoe());
    t->setExp(pointer->getExp() + pointery->getExp());
    temp->insert(*t);
    
    return *temp;
}
