//
//  main.cpp
//  Polynomial
//
//  Created by Deveshwar Singh on 10/13/19.
//  Copyright © 2019 Deveshwar Singh. All rights reserved.
//

#include <iostream>
#include "node.h"
#include "polynomial.h"
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    polynomial one ;
    polynomial two;
    
    ifstream file("input.txt");
    ofstream out("output.txt");
        
    while(!file.eof()){
        string p1;
        string p2;
        getline(file, p1);
        getline(file, p2);
        if(p1=="" || p2 == "") {
            break;
        }
        
        polynomial one = polynomial(p1);
        polynomial two = polynomial(p2);
     
        out<< "Input: "<< endl << "p1: ";
        
        node *temp = one.getHead();
        int count = 1;
        while (count<=one.getSize()) {
            if(count ==1 && temp->getCoe() != 0){
                out << (temp->getCoe()) << "x^"<< (temp->getExp());
            }
            
            else if(temp->getCoe() > 0){
                out<< "+"<< (temp->getCoe()) << "x^"<< (temp->getExp());
            }
            else if(temp->getCoe() < 0){
                out<< (temp->getCoe()) << "x^"<< (temp->getExp());
            }
            if( count != one.getSize())
            temp = temp->getNext();
            count++;
        }
        out<<std::endl;
        out<< "p2: ";
        node *temp2 = two.getHead();
        int count2 = 1;
        while (count2<=two.getSize()) {
            if(count2 ==1 && temp2->getCoe() != 0){
                out << (temp2->getCoe()) << "x^"<< (temp2->getExp());
            }
            else if(temp2->getCoe() > 0){
                out<< "+"<< (temp2->getCoe()) << "x^"<< (temp2->getExp());
            }
            else if(temp2->getCoe() < 0){
                out<< (temp2->getCoe()) << "x^"<< (temp2->getExp());
            }
            if( count2 != two.getSize())
                temp2 = temp2->getNext();
                count2++;
            }
        out<<std::endl;
        
        
        out<< "Sum: ";
        polynomial sum = one+two;
        int count3 = 1;
        node *temp3 = sum.getHead();
        while (count3<=sum.getSize()) {
            if(count3 ==1 && temp3->getCoe() != 0){
                out << (temp3->getCoe()) << "x^"<< (temp3->getExp());
            }
            
            else if(temp3->getCoe() > 0){
                out<< "+"<< (temp3->getCoe()) << "x^"<< (temp3->getExp());
            }
            else if(temp3->getCoe() < 0){
                out<< (temp3->getCoe()) << "x^"<< (temp3->getExp());
            }
            if( count3 != sum.getSize())
            temp3 = temp3->getNext();
            count3++;
        }
        out<<std::endl;
        
        out<< "Subtraction: ";
        polynomial sub = one-two;
        int count4 = 1;
               node *temp4 = sub.getHead();
               while (count4<=sub.getSize()) {
                   if(count4 ==1 && temp4->getCoe() != 0){
                       out << (temp4->getCoe()) << "x^"<< (temp4->getExp());
                   }
                   
                   else if(temp4->getCoe() > 0){
                       out<< "+"<< (temp4->getCoe()) << "x^"<< (temp4->getExp());
                   }
                   else if(temp4->getCoe() < 0){
                       out<< (temp4->getCoe()) << "x^"<< (temp4->getExp());
                   }
                   if( count4 != sub.getSize())
                   temp4 = temp4->getNext();
                   count4++;
               }
        out<<std::endl;
        
        out<< "Multiplication: ";
        polynomial mul = one*two;
        int count5 = 1;
        node *temp5 = mul.getHead();
        while (count5<=mul.getSize()) {
            if(count5 ==1 && temp5->getCoe() != 0){
                out << (temp5->getCoe()) << "x^"<< (temp5->getExp());
            }
            else if(temp5->getCoe() > 0){
                out<< "+"<< (temp5->getCoe()) << "x^"<< (temp5->getExp());
            }
            else if(temp5->getCoe() < 0){
                out<< (temp5->getCoe()) << "x^"<< (temp5->getExp());
            }
            if( count5 != mul.getSize())
                temp5 = temp5->getNext();
                count5++;
            }
        out<<std::endl;
        
    }

    return 0;
}
