#include <iostream>
#include <math.h>
#include <cstdlib>
#include <math.h>  
#define CASHBOX 12

using namespace std;
double getAverageCash(double cash);
void createCashBox(double box[]);
void showCashBox(double arrayOfCashBox[]);
double getCash( double arrayOfCashBox[]);
void showMaxProfit(double box[]);
void showAverageBox(double box[]);
int main(){
  
    double cb[CASHBOX] = {0};
    double aCash=0.0;
    double allCash=0.0;
	
	createCashBox(cb);
    showCashBox(cb);
    allCash=getCash(cb);
	aCash=getAverageCash(allCash);
	cout <<endl <<"Cash: " << allCash << " BYN";
	cout <<endl <<"Average Cash: " << aCash << " BYN";
	showMaxProfit(cb);
	showAverageBox(cb);
	return 0;
}

void createCashBox(double box[]){
	 
	 for(int i = 0; i < CASHBOX; i++){
	 	box[i] = rand() % 100;
	 }
	 	
}

void showCashBox(double arrayOfCashBox[]){
	
	for(int i = 0; i < CASHBOX; i++){
	 	cout << arrayOfCashBox[i] << ' ' ;
	 }
}

double getCash( double arrayOfCashBox[]){

	double cash=0;
	
	for(int i=0; i < CASHBOX; i++){
		cash += arrayOfCashBox[i];
	}
	
	return cash;
}
double getAverageCash(double cash){
	double acash=cash/CASHBOX;
	return acash;
}
void showMaxProfit(double box[]){
	double max=box[0];
	int index=0;
	for(int i=1; i < CASHBOX ; i++){
	if(	box[i]>max){
		max=box[i];
		index=i;
	 }
	}
	cout <<"Max profit box :"<< index+1;
}
void showAverageBox(double box[]){
	double ac=round(getAverageCash(getCash(box)));
	double restArray[CASHBOX]={0};
	
	for(int i=0 ; i < CASHBOX; i++){
		restArray[i]=abs(box[i]-ac);
	}
	
	for(int i=0 ; i < CASHBOX; i++){
		cout<<endl<< restArray[i];
	}
	
}
