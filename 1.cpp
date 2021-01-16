#include <iostream>
#include <cstdlib>
#define N 13
int rollDice();

using namespace std;


int main()
{

    int i, n=0 ,stat[N]={0};
    for (i=0;i<N ;i++){
    	stat[rollDice()+rollDice()]++;
    }
    for (i=2;i<N ;i++){
    	cout.width(3);
    	cout << i<<": ";
    	cout << stat[i] << " " << endl;
    }
    return 0;
}

int rollDice(){
	
	return 1+rand() % 6;
}
