#include <iostream>

using namespace std;

int getPositiveNumber(int number);
int getYear(int year);
int getMounth(int mounth);
int getCorrectDay(int number,int mounth,int year);
int getMagicSum(int summedDate);
bool isLeapYear(int year);
int countOfDaysInAMounth(int mounth,int year);

int main()
{
    int year, mounth, day;
    
    year = getYear(year);
    mounth = getMounth(mounth);
    day = getCorrectDay(day,mounth,year);
    getMagicSum(year+mounth+day);
    
    cout << year << "/" << mounth << "/" << day<<" Magic sum: "<<getMagicSum(year+mounth+day);
    return 0;
}

int getPositiveNumber(int number)
{

    cin >> number;

    while (!cin >> number || number <= 0)
    {
        cout << "Error!" << endl;
        cout << "Input correct value: ";
        cin >> number;
        cin.clear();
        fflush(stdin);
    }

    return number;
}

int getYear(int year)
{
    cout << "Input year: ";
    year = getPositiveNumber(year);
    while (year > 2020)
    {
        cout << "Input year > 2021: ";
        year = getPositiveNumber(year);
    }
    return year;
}
int getMounth(int mounth)
{
    cout << "Input mounth: ";
    mounth = getPositiveNumber(mounth);
    while (mounth > 12)
    {
        cout << "Error! There are 12 mounth!" << endl;
        cout << "Input mounth from 1 to 12: ";
        mounth = getPositiveNumber(mounth);
    }
    return mounth;
}
int getCorrectDay(int day,int mounth,int year)
{
	int daysInAMounth=countOfDaysInAMounth(mounth,year);
    cout << "Input day: ";
    day = getPositiveNumber(day);
    while (day > daysInAMounth)
    {
        cout << "Error!" << endl;
        cout << "Input day from 1 to "<<daysInAMounth<<":";
        day = getPositiveNumber(day);
    }
    return day;
}
bool isLeapYear(int year){
	
	return (year%4==0)?true:false;
}
int countOfDaysInAMounth(int mounth,int year){
	
	if(mounth == 1 || mounth ==4 || mounth ==6 || mounth ==9 || mounth ==11){
		return 30;
	}else if(mounth == 3 || mounth ==5 || mounth ==7 || mounth ==8 || mounth ==10 || mounth ==12){
		return 31;
	}else if (mounth == 2){
		if(isLeapYear(year)){
		   return 29;	
		}else{
			return 28;
		}
    }
}
int getMagicSum(int summedDate){
	int magicSum=0;
	int magic=0;
	while(summedDate!=0 ){
		magicSum+=summedDate%10;
		summedDate/=10;
	}
    while(magicSum!=0){
    	magic+=magicSum%10;
    	magicSum/=10;
    }
	
	return magic;
}


