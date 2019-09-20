#include "node.h"

node::node(){//default constructor
	coe = 1;
	exp = 1;
	next = NULL;
}

node::node(int x){//one argument constructor
	coe = x;
	exp = 1;
	next = NULL;
}

node::node(int x, int y){//two argument constructor
	coe = x;
	exp = y;
	next = NULL;
}

node::node(int x, int y,const  node &p){//three argument constructor
	coe = x;
	exp = y;
	next = &p;
}

node::node(const node &x){//copy constructor
	this.coe = x.coe;
	this.exp = x.exp;
	this.next = x.next;
}

node::~node(){//deconstructor
	delete next;
}

//mutators
node::void setCoe(int x){
	coe = x;
}

node::void setExp(int x){
	exp=x;	
}

node::void setNext(const node &x){
	next=&x;
}


//accessors
node::int getCoe(){
	return coe;
}

node::int getExp(){
	return exp;
}

node::node* getNext(){
	return next;
}


//operator overloads
node:: node& operator=(const node &x){
	if( this !=x){
		delete next
		coe = x.coe;
		exp = x.exp;
		next = x.next;
	}
	return *this;
}

node::
