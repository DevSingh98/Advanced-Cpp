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
    
    ifstream file("input");
    if(file.is_open()){
        string last;
        while(!file.eof()){
            
            file >> last;
        }
    }
    
    ifstream myfileRead;
      
      unsigned int last;
      myfileRead.open("primes.txt");
      while(!myfileRead.eof()){
          myfileRead >> last;
      }
      myfileRead.close();
      cout<<endl<<last<<endl;
    
    node x = node();
    x.setExp(3);
    x.setCoe(8);
    
    
    node y = node();
    y.setExp(3);
    y.setCoe(4);
    
    node z = node();
    z.setExp(4);
    z.setCoe(8);
    
    node a = node();
    a.setExp(2);
    a.setCoe(2);
    
    node b = node();
    b.setExp(6);
    b.setCoe(5);
    
    node e = node();
    e.setExp(3);
    e.setCoe(9);
    
    node j = node();
    j.setExp(5);
    j.setCoe(9);
     
    
    polynomial one = polynomial();
    one.insert(x);
    one.insert(y);
    
    polynomial two = polynomial();
    two.insert(z);
    two.insert(a);
    
    one.print();
    two.print();
    
    polynomial mul = one*two;
    mul.print();
    /*
    two.insert(b);
    //two.print();
    
    two.insert(e);
    //two.print();
    
    two.insert(j);
    //two.print();
    
    two.print();
    */
    
    //polynomial sum = two+one;
    
   // sum.print();
    
    //polynomial sum2 = (two-one);
    
    //sum2.print();
    
    /*
    ofstream myfile("primes.txt");
       if(myfile.is_open()){
           for(unsigned int i =0; i<sizeOfOrder;i++){
               myfile<<orderedPrimes.back();
               myfile<< endl;
               orderedPrimes.pop_back();
           }
           myfile.close();
       }
     */
    return 0;
}
