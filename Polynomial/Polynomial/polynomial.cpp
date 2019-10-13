//
//  polynomial.cpp
//  Polynomial
//
//  Created by Deveshwar Singh on 10/13/19.
//  Copyright © 2019 Deveshwar Singh. All rights reserved.
//

#include "polynomial.h"
#include <iostream>
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
    
    if(this->size ==0){ //empty
        this->head = &x;
        this->tail = &x;
        this->size++;
    }
    else if(this->size ==1){ //one term
        if((*(this->tail)).getExp() == x.getExp()){
            (*(this->tail)).setCoe((*(this->tail)).getCoe() + x.getCoe());
        }
        else if((*(this->tail)).getExp() < x.getExp()){
            head = &x;
            x.setNext(this->tail);
            this->size++;
        }
        else{
            tail = &x;
            (*(this->head)).setNext(tail);
            this->size++;
        }
    }
    else if(this->size ==2){ // two terms
        if((*(this->tail)).getExp() == x.getExp()){//if exp same as tail
            (*(this->tail)).setCoe((*(this->tail)).getCoe() + x.getCoe());
        }
        else if((*(this->tail)).getExp() > x.getExp()){//tail is bigger then incoming
            (*(this->tail)).setNext(&x);
            tail = &x;
            this->size++;
         }
        
         else if( (*(this->tail)).getExp() < x.getExp() &&
             (*(this->head)).getExp() > x.getExp() ){//if tail is smaller but head is larger
             ((*this->head)).setNext(&x);
             x.setNext(tail);
             this->size++;
         }
        
         else if((*(this->head)).getExp() == x.getExp()){ //same size as head, combine
             (*(this->head)).setCoe((*(this->head)).getCoe() + x.getCoe());
         }
    }
    else{//more then 2 terms
        int count =1;
        node * pointer;
        pointer =this->head;
        //pointer starts at the head
        
        if((*pointer).getExp()< x.getExp()){ //if input is biggest term
                       x.setNext(this->head);
                       head = &x;
            this->size++;
        }
        
        else if((*(this->tail)).getExp() > x.getExp()){//tail is bigger then incoming
           (*(this->tail)).setNext(&x);
           tail = &x;
           this->size++;
        }
        
        else{
            while(count != this->size){
                if((*pointer).getExp() == x.getExp()){//if input has the same power
                    (*pointer).setCoe((*pointer).getCoe() + x.getCoe());
                    break;
                }
                
                else{
                    pointer=  (*pointer).getNext();
                    count++;
                    
                }
            }
        }
    }
}


void polynomial::print() const{
    node *temp = this->head;
    int count = 1;
    while (count<this->size) {
        if(temp->getCoe() > 0){
            std::cout << (temp->getCoe()) << "x^"<< (temp->getExp())<<"+";
        }
        temp = temp->getNext();
        count++;
    }
    //std::cout<<std::endl;
    if(temp->getCoe() > 0){
        std::cout << (temp->getCoe()) << "x^"<< (temp->getExp())<<std::endl;
    }
    
    
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

const polynomial& operator+(polynomial &x, polynomial &y){//make a friend function
   
    
    polynomial *temp = new polynomial();
    node *pointer = new node();
    node *pointer2 = new node();
    pointer = x.getHead();//start of left side
    pointer2 = y.getHead(); //side of right side
     
    while(pointer != x.getTail()){
        (*temp).insert(*pointer);
        pointer = (*pointer).getNext();
    }
    (*temp).insert(*(x.getTail()));
    
    
    while(pointer2 != y.getTail()){
           (*temp).insert(*pointer2);
           pointer2 = (*pointer2).getNext();
       }
       (*temp).insert(*(y.getTail()));
    return *temp;
    
    
    /*
    polynomial *temp = new polynomial();
    node *pointer = x.getHead();//start of left side
    node *pointer2 = y.getHead();; //side of right side
    //(*temp).setSize(1);
    int size1 = x.getSize();
    int count1 =1;
    while(pointer != x.getTail()){
        (*temp).insert(*pointer);
        pointer = (*pointer).getNext();
            count1++;
    }
    (*temp).insert(*(x.getTail()));
    
    
    int size2 = y.getSize();
    int count2 =1;
    while(pointer2 != y.getTail()){
        (*temp).insert(*pointer2);
        pointer2 = (*pointer2).getNext();
        count2++;
    }
   (*temp).insert(*(y.getTail()));
    std::cout<< temp->getSize()<<std::endl;
    temp->print();
    temp->setSize(temp->getSize()+1);
    return *temp;*/
}



/*
polynomial& polynomial::operator-(polynomial &x){
   
    polynomial *temp = new polynomial();
    node *pointer = this->head;//start of left side
    node *pointer2 = x.head; //side of right side
    
    int size1 = this->size;
    int count1 =1;
    while(count1 <size1){
        (*temp).insert(*pointer);
        pointer = (*pointer).getNext();
            count1++;
    }
    (*temp).insert(*(this->tail));
    
    int size2 = x.size;
    int count2 =1;
    while(count2 <size2){
        (*pointer2).setCoe((*pointer2).getCoe()*-1);
        (*temp).insert(*pointer2);
        pointer2 = (*pointer2).getNext();
        count2++;
    }
    (*(x.tail)).setCoe((*(x.tail)).getCoe()*-1);
    (*temp).insert(*(x.tail));
    return *temp;
}*/
