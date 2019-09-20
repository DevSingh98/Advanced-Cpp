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
	node(int x, int y,const  node &p);//3 argument constructor
	node(const node &x);//copy constructor	
	~node();//destructor

        //Mutators
	void setCoe(int x);
	void setExp(int x);
	void setNext(const node &x);
	
	//Accessors 
	int getCoe();
	int getExp();
	*node getNext();
	
	//overloading operators
	node& operator=(const node &x);//overload = operator
	bool operator<(const node &x);//overload < operator
	bool operator>(const node &x);//overload > operator
	node operator+(const node &x)const;//overload + operator	
};
#endif
