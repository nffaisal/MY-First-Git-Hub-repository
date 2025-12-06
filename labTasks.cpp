#include<iostream>
#include<cmath>
using namespace std;
double getaverageofdigits(int number);
int cubeOfDigits(int number);
void isarmstrong(int sum, int number);
void displayevendigits(int number);
bool iseven(int number);
 double futureInvestmentValue( double investmentAmount, double monthlyInterestRate, int years);
void displayinvestmentrate(double investmentAmount, double monthlyInterestRate, int years);
int main(){
      //cout<<getaverageofdigits(2468);
      //isarmstrong(cubeOfDigits(153), 153);
      // displayevendigits(24567);
      //double investmentrate, amount;
      //cout<<"enter inevstemnet rate"; cin>>investmentrate;
      //cout<<" enter investment amount ";cin>>amount;
      //displayinvestmentrate(amount, investmentrate, 30);
      

  return 0;         
}
double getaverageofdigits(int number){
     int digit;
     int sumofdigits =0;
     const int originalnumber = number;
     int count=0;
     while(number>0){
         digit = number % 10;
         number =number /10;
         sumofdigits += digit;
         count++;
     }
     return sumofdigits/count; 
}
int cubeOfDigits(int number){
      const int original =number;
      int digit;
      int sumofdigits =0;
     while(number >0){
      digit = number %10;
      sumofdigits += pow(digit, 3);
      number = number /10;
     }
     return sumofdigits;
}

void isarmstrong(int sum,int num){
   if(sum == num){
    cout<<"It is armstrong number";
   }else{
     cout<<"It is not";
   }
}
void displayevendigits(int number){
  const int original =number;
  int digit;
  while(number > 0){
      digit =number %10;
      if( iseven( number) ){
        cout<<digit<<" "  ;
      }
      number = number /10;
  }
}
bool iseven(int number){
   if(number %2 == 0) { return true;}
   else{ return false;}
}
double futureInvestmentValue( double investmentAmount, double monthlyInterestRate, int years){
   int futureinvestment = investmentAmount * pow((1 + monthlyInterestRate/100), years);
   return futureinvestment;
}
void displayinvestmentrate(double investmentAmount, double monthlyInterestRate, int years){
  cout<<"Year    FutureInvestment";
  for(int i =1;i<years; i++ ){
    cout<<i<<" "<<futureInvestmentValue(investmentAmount, monthlyInterestRate, i)<<endl;
  }
}