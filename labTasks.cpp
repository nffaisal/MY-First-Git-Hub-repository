#include<iostream>
#include<cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
double getaverageofdigits(int number);
int cubeOfDigits(int number);
bool isarmstrong(int sum, int number);
void displayevendigits(int number);
bool iseven(int number);
 double futureInvestmentValue( double investmentAmount, double monthlyInterestRate, int years);
void displayinvestmentrate(double investmentAmount, double monthlyInterestRate, int years);
double Sumseries(int n);
void tablesumseries(int n);
void numberOfDaysInFebruary(int startyear, int endyear);
void printMatrix(int n);
int reversenumber(int number);
bool ispalindrome(int number);
int diceroll();
void craps();
int main(){
      //cout<<getaverageofdigits(2468);
      int number;
        /*if(isarmstrong(cubeOfDigits(153), 153)){
               number = reversenumber(153);
               if(isarmstrong(cubeOfDigits(number) ,number)){
                cout<<"reverse and armstrong";
               }else{
                cout<<"is noy revrse armstrong";
               }
        } */
      // displayevendigits(24567);
      //double investmentrate, amount;
      //cout<<"enter inevstemnet rate"; cin>>investmentrate;
      //cout<<" enter investment amount ";cin>>amount;
      //displayinvestmentrate(amount, investmentrate, 30);
      // millimetertoinchetable(10);
        //numberOfDaysInFebruary(2000,2004);
        // printMatrix(4);
        //cout<<ispalindrome(121);
        //craps();
        cout<<"\u2713";
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

bool isarmstrong(int sum,int num){
   if(sum == num){
    return true;
   }else{
     return false;
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

double Sumseries(int n){
   if(n>0){
    return Sumseries(n-1) + 1.0/(n* ( n +2.0 )); } else{
   return 0;}
}
void numberOfDaysInFebruary(int startyear, int endyear){
  for(int i = startyear ;i<endyear;i++)
  if((i%4== 0 && i %100 != 0) || i%400==0){
    cout<<"29"<<endl;
  }else{
    cout<<"28"<<endl;
  }
}
 void printMatrix(int n){
       srand(time(0));
     for(int i =0; i<n;i++){
      for(int j =0;j<n;j++){
         cout<<rand() %2<<" ";
      }
      cout<<endl;
     }
 }
 int reversenumber(int number){
     int digit;
     const int original = number;
     int reversed =0;
     while(number>0){
       digit = number % 10;
         int reversed =(reversed *10 ) + digit;
         number = number /10;
     }
     return reversed;
 }
bool ispalindrome(int number){
   if(reversenumber(number) == number){ return true;}
   else{ return false;}
}
int diceroll(){
  srand(time(0));
  return ( rand() % 6) +1;
}
void craps(){
     int sum;
      int gameover =false;
       int point =0;
    
    int first =diceroll(); int second =diceroll();
    cout<<"\n Your First Roll:  "<<first;
    cout<<"\n Your second Roll: "<<second;
     sum = first +second;
    while(!gameover){
      switch(sum){
        case 4:
        case 5:
        case 6:
        case 8:
        case 9:
        case 10: 
               cout<<"\n Point "<<sum; break;
       case 2:
       case 3:
       case 12:
       cout<<"\nYou lose"; gameover =true ; break;
       case 7:
       case 11:
       cout<<"\n You WIN!"; break;}
      }
}
