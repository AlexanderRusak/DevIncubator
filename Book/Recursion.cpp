#include <iostream>

using namespace std;

void countdown(int n);
int factorial(int n);

int main(){
	
	//countdown(3);
	cout<<factorial(5);
	return 0;
}

void countdown(int n){
	cout<<n<<endl;
	if(n!=0){
		countdown(n-1);
	}
}


int factorial(int n){
	if(n==1){
		return 1 ;
	}else{
		return n*factorial(n-1);
	}
}
