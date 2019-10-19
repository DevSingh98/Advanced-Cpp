//Deveshwar Singh
//Safe Matrix implementation using safearray class
//Advanced oop c++ Dr. Waxman

#include<iostream>
#include<cstdlib>
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
template <typename t>
ostream& operator<<(ostream& os, SA<t> s){ 
	int size=s.high-s.low+1;
	for(int i=0; i<size; i++)
		cout<<s.p[i]<<endl; 
	return os;
};

template<typename t>
class SafeMatrix{

private:
	int low_r;
	int low_c;
	int high_r;
	int high_c;
	SA< SA <t> > *outer;

public:
	//default constructor
	SafeMatrix(){
		low_r=0;
		low_c=0;
		high_r=0;
		high_c=0;
		outer = NULL;
	}	
	
	//4 argument constructor
	SafeMatrix(int a,int b,int c, int d){
		low_r=a;
		high_r=b;
		low_c=c;
		high_c=d;
		outer= new SA< SA<t> >(low_r,high_r);
		for(int i=low_r;i<high_r+1;i++){
			(*outer)[i]=SA<t>(low_c,high_c);
		}
	
	}

	//two argument constructor
	SafeMatrix(int a, int b){
		low_r=a;
		low_c=a;
		high_r=b;
		high_c=b;
		outer= new SA< SA<t> >(low_r,high_r);
		for(int i=low_r;i<high_r+1;i++){
			(*outer)[i]= SA<t>(low_c,high_c);
		}
	}
	
	//copy constructor 
	SafeMatrix(SafeMatrix<t> &temp){
		low_r=temp.low_r;
		low_c=temp.low_c;
		high_r=temp.high_r;
		high_c=temp.high_c;
		outer = new SA< SA<t> >(temp.low_r,temp.high_r); 
		for(int i=temp.low_r; i<temp.high_r+1;i++){
			(*outer)[i]=temp[i];

		}		
	}
	
	//overloading [] operator for SafeMatrix class
	SA<t>& operator[](int x){
		return (*outer)[x];
	}
	
	//overload + operator for safematrix addition
	SafeMatrix<t>& operator+(SafeMatrix &temp){
		int leftrow= high_r - low_r+1;
		int leftcol= high_c - low_c+1;
		int rightrow= temp.high_r - temp.low_r+1;
		int rightcol= temp.high_c - temp.low_c+1;
		

		//checks if both matrix are the same size
		if(leftrow != rightrow && leftcol != rightcol){
			throw "the dimensions of each array dont match";
		}
		
		else{
			//creating result safe matrix
			//calling copy constructor and copying elements from the right hand side safe matrix
			SafeMatrix<t> *result = new SafeMatrix<t>(temp);
			for(int i=0;i<high_r-low_r+1;i++){
				//creating safearray to hold the contents for each row of the left hand side matrix
				SA<t> x = (*outer)[low_r+i];
				for(int j =0; j<high_c-low_c+1;j++){
					//adding each row of the lefthand side to the right hand side matrix
					(*result)[((*result).low_r+i)][((*result).low_c+j)] += x[low_c+j];
				}
			}
			return *result;
		}

	}

	SafeMatrix<t>& operator*(SafeMatrix &temp){
		//checks if the left hand size col matches the right hand side row
		if(high_c-low_c+1 != temp.high_r-temp.low_r+1){
			throw "the column of matrix one does not match the row of matrix 2";
		}
		else{
			//creates result matrix with the dimensions of
			//the row of the left hand side, and the col of the right hand side
			SafeMatrix<t> *result = new SafeMatrix<t>(0,high_r-low_r,0,temp.high_c-temp.low_c);

			//initializing the result array with all 0's for use
			for(int i =0; i<high_r-low_r+1;i++){
				for(int j=0; j<temp.high_c-temp.low_c+1;j++){
					(*result)[i][j]=0;
				}
			}

			//multiplies each element from the left hand sides row to the left hand sides column
			for(int i =0; i<high_r-low_r+1;i++){
				for(int j=0; j<temp.high_c-temp.low_c+1;j++){
					for(int k=0; k<temp.high_r-temp.low_r+1;k++){
						(*result)[i][j] +=(*outer)[low_r+i][low_c+k]* (*temp.outer)[temp.low_r+k][temp.low_c+j];
					}
				}
			}
			return *result;
		}

	}


	//destructor
	~SafeMatrix(){
		low_r=0;
		low_c=0;
		high_r=0;
		high_c=0;
		//deletes pointer to safearray outer and
		//inner safearray deconstructors get automatically called 
		delete outer;
	}
};



int main(){
	
	//declaring safe matrix a and b
	SafeMatrix<int> a(0,1,0,1);
	SafeMatrix<int> b(0,1,0,1);
	int temp =100;	

	//initializing a and b with vales
	for(int i=0; i<2;i++){
		for(int j=0;j<2;j++){
			a[i][j]=temp;
			temp++;
			b[i][j] =temp;
			temp++;	
		}
	}

	//printing the contents of a
	cout<<"A:"<<endl;
	for(int i=0; i<2;i++){
        for(int j=0;j<2;j++){
                cout<< a[i][j]<<" ";
        }
		cout<<endl;
    }
	cout<<endl;

	//printing the contents of b
	cout<<"B:"<<endl;
	for(int i=0; i<2;i++){
        for(int j=0;j<2;j++){
                cout<< b[i][j]<<" ";
        }
		cout<<endl;
    }
	cout<<endl;
	
	//initializing a+b safe matrix
	//calls + operator on a and b
	//calls copy constructor to copy the results into the result matrix
	try{
		SafeMatrix<int> result = a+b;

		cout<<"a+b:"<<endl;
		//printing the results of a+b
		for(int i=0; i<2;i++){
			for(int j=0;j<2;j++){
					cout<< result[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}	
	catch(const char* msg){
		cout<< msg <<endl;
	}

	//initializing a*b safe matrix
	try{
		SafeMatrix<int> mresult = a*b;
	
		cout<<"a*b:"<<endl;
		//printing the results of a*b
		for(int i=0; i<2;i++){
			for(int j=0;j<2;j++){
					cout<< mresult[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}	

	catch(const char* msg){
		cout<< msg <<endl;
	}
	//declaring 2 different size matrixs
	SafeMatrix<double> c(0,3,0,1);
	SafeMatrix<double> d(0,1,0,5);

	double temp2 = 1.8;
	//initializing c
	for(int i=0; i<4;i++){
		for(int j=0;j<2;j++){
			c[i][j]=temp2;
			temp2 +=0.2;
		}
	}
	//initializing d
	for(int i=0; i<2;i++){
		for(int j=0;j<6;j++){
			d[i][j]=temp2;
			temp2 += 0.2;
		}
	}

	cout<<"c:"<<endl;
	//printing c
	for(int i=0; i<4;i++){
		for(int j=0;j<2;j++){
			cout<< c[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"d:"<<endl;
	//printing d
	for(int i=0; i<2;i++){
		for(int j=0;j<6;j++){
			cout<< d[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	//initializes result matrix
	//calls *function on c and d
	//calls copy constructor to copy the results into the result matrix
	try{
		SafeMatrix<double> cdresult = c*d;
		cout<<endl<<"c*d:"<<endl;
		for(int i=0;i<4;i++){
			for(int j=0; j<6;j++){
				cout<<cdresult[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	catch(const char* msg){
		cout<< msg <<endl;
	}


	//test if wrong input is made
	SafeMatrix<int> x(0,1,0,1);
	SafeMatrix<int> y(0,2,0,2);
	try{
		SafeMatrix<int> z = x+y;
	}
	catch(const char* msg){
		cout<<endl<< msg <<endl;
	}

	return 0;
}
