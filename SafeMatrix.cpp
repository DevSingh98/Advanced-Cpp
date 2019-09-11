#include<iostream>
#include<cstdlib> 
#include<cassert> 
using namespace std; 

template<typename t>
class SA{

private:
	int low, high;
	t* p;

public:
	// default constructor
	// allows for writing things like SA a;
	SA(){
		low=0; 
		high=-1;
		p=NULL;
	}
	
	// 2 parameter constructor lets us write // SA x(10,20);
	SA(int l, int h){ 
		if((h-l+1)<=0){
			cout<< "constructor error in bounds definition"<<endl; exit(1);
		}
		low=l;
		high=h;
		p=new t[h-l+1];
	}

	// single parameter constructor lets us
	// create a SA almost like a "standard" one by writing // SA x(10); and getting an array x indexed from 0 to 9
	SA(int i){
		low=0;
		high=i-1;
		p=new t[i];
	}

	// copy constructor for pass by value and // initialization
	SA(const SA<t> &s){
		int size=s.high-s.low+1; 
		p=new t[size];
		for(int i=0; i<size; i++)
			p[i]=s.p[i]; 
		low=s.low;
		high=s.high; 
	}

	// destructor
	~SA(){
		delete [] p;
	}

	//overloaded [] lets us write //SA x(10,20); x[15]= 100;
	t& operator[](int i){ 
		if(i<low || i>high){
			cout<< "index "<<i<<" out of range"<<endl;
			exit(1);
		}
		return p[i-low];
	}

	// overloaded assignment lets us assign
	// one SA to another
	SA & operator=(const SA<t> & s){ 
		if(this==&s)
			return *this;
		delete [] p;
		int size=s.high-s.low+1;
		p=new t[size]; 
		for(int i=0; i<size; i++)
			p[i]=s.p[i];
			low=s.low;
		high=s.high; return *this;
	}

	// overloads << so we can directly print SAs
	 friend ostream& operator<<(ostream& os, SA s);
	};

ostream& operator<<(ostream& os, SA<t> s){ 
	int size=s.high-s.low+1;
	for(int i=0; i<size; i++)
		cout<<s.p[i]<<endl; 
	return os;
};