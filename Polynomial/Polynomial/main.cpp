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
    node x = node();
    x.setExp(3);
    x.setCoe(8);
    
    
    node y = node();
    y.setExp(3);
    y.setCoe(4);
    node test = x+y;
    //test.print();
    node z = node();
    z.setExp(4);
    z.setCoe(8);
    
    node a = node();
    a.setExp(2);
    a.setCoe(2);
    
    polynomial one = polynomial();
    one.insert(x);
    one.insert(y);
    
    polynomial two = polynomial();
    two.insert(z);
    two.insert(a);
    //two.insert(x);
    
    one.print();
    two.print();
    
    /*polynomial equal = polynomial();
    equal = two;
    equal.print();*/
    
    
    
    (one+two).print();
    
    polynomial sum = one+one;
    x=a;
    
    polynomial three = polynomial();
    three.insert(x);
    
    //three.print();
    
    //two = one;
    
    //one.print();
    //two.print();
    //sum.print();
    //cout<< sum.getSize()<<endl;
    node hi = node();
    //hi = *(sum.getHead());
    //cout<< hi.getCoe() << "x^"<< hi.getExp()<<endl;
    //one.print();
    return 0;
}
