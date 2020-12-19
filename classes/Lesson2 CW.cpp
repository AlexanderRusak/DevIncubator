#include <iostream>
#include <limits>
using namespace std; 
  
  
int main() 
{ 
    int num=12345;
    /*while(num!=0){  
    	cout<<num%10;
    	num/=10;
    }*/
    
    
    
	/*int sum=0;      
    int mult=1;
    while(num!=0){
    	sum+=num%10;
    	mult*=num%10;
    	num/=10;
    }
    cout<<"Summ: "<<sum<<endl;
    cout<<"Mult: "<<mult<<endl;*/ 
    
    
   /* int max=num%10;
    int min=num%10;
  
    while(num!=0){
        
        if (max < num % 10) max = num % 10;
        else if (min > num % 10) min = num % 10;
        else num = num / 10;
    }
    cout<<max<<endl;
    cout<<min<<endl;*/
    
    /*int prev=num%10;  //4
    bool isIncrease=false;
    num/=10; //12345
    
    while(num!=0){  

    	if(prev>num%10){ //4>5
    		isIncrease=true;
    	}
    	else{
    		isIncrease=false;
    		break;
    	}
    	prev=num%10;
    	num/=10;
    }
    cout<<(isIncrease?"Increase":"Non increase");*/
    
    
/*	int prev=num%10; 
    bool isMatched=false;
    num/=10; 
    
    while(num!=0){  

    	if(prev!=num%10){ 
    		isMatched=false;
    	}
    	else{
    		isMatched=true;
    		break;
    	}
    	prev=num%10;
    	num/=10;
    }
    cout<<(isMatched?"Matched":"Non Matched");*/
    bool isMatched=false;
    int prev;
    while(num!=0){
    	prev=num%10; 
    	num/=10; 
    	while(num!=0){  
    		if(prev==num%10){ 
    			isMatched=true;
    			break;
    		}
    		num/=10;
    	}
    }
    cout<<(isMatched?"Matched":"Non Matched");
    return 0; 
} 
