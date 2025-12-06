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
double millimeterstoinches(double millimeters);
double inchestomillimeters(double inches);
void  millimetertoinchetable(int millimeters);
double Sumseries(int n);
void tablesumseries(int n);
int main(){
      //cout<<getaverageofdigits(2468);
      //isarmstrong(cubeOfDigits(153), 153);
      // displayevendigits(24567);
      //double investmentrate, amount;
      //cout<<"enter inevstemnet rate"; cin>>investmentrate;
      //cout<<" enter investment amount ";cin>>amount;
      //displayinvestmentrate(amount, investmentrate, 30);
      // millimetertoinchetable(10);
      tablesumseries(4);

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
void  millimetertoinchetable(int millimeters){
   cout<<"Millimeters  Inches ||   Inches Millimeters"<<endl;
   for(int i =0; i<millimeters;i++){
    cout<<i<<" "<<millimeterstoinches(i)<<"  "<<i<<"  "<<inchestomillimeters(i)<<endl;
   }
}
double Sumseries(int n){
   if(n>=0){
    return Sumseries(n-1) + 1.0/(n* ( n +2.0 ));
}else{
  return 0;
}}

void tablesumseries(int n){
  for(int i =1; i<n;i++){
    cout<<i<<" "<<Sumseries(i);
  }
}
