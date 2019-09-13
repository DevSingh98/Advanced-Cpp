//
//  main.cpp
//  variadic templates c++
//
//  Created by Deveshwar Singh on 8/31/19.
//  Copyright © 2019 Deveshwar Singh. All rights reserved.
//

#include <iostream>

template<typename t1> //base case for recursive call
t1 sum(const t1& x){
    return x;
}

template<typename t1, typename ... t2 >//recursive call
t1 sum(const t1& x, const t2& ... y){
    return x+sum(y...);//where the sum happens
}


int main(int argc, const char * argv[]) {
    std::cout<< sum(1,10)<<std::endl; //prints 11
    std::cout<< sum(1,10,100)<<std::endl; //prints 111
    std::cout<< sum(0.5,0.5)<<std::endl; //prints 1
    std::cout<< sum(1.7,10.29,857.002)<<std::endl; //prints 869.992
    return 0;
}
