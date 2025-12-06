#include<iostream>
using namespace std;
int getaverageofdigits(int number);
int main(){
      
  return 0;         
}
int getaverageofdigits(int number){
     int digit;
     int sumofdigits =0;
     const int originalnumber = number;
     while(number>0){
         digit = number % 10;
         number =number /10;
         sum += digits;
     }
     return sum/originalnumber;
}
