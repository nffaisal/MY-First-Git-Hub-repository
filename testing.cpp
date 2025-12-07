#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime> 
using namespace std;
void grades(int arr[], int number);
int generateRandom();
int main(){
  int arr[10];
  const int number =10;
   /* int amount;
    for(int i=0;i<number;i++){
       int repeats =0;
     arr[i] = generateRandom(); 
      for(int j=0;j<number;j++){
         if(arr[i]==arr[j]){
           repeats++;
         }
      }
      cout<<arr[i]<<"  The repeats are: "<<repeats<<endl;
    }*/
    int arr1[100]; const int num2 =100;
    long starttime = time(0);
    for(int i=0;i<num2;i++){
       arr[i] =generateRandom();
       cout<<arr[i]<<" ";
    }
    long endtime =time(0);
    long timeElapsed =(endtime - starttime) /60;
    cout<<"\n The time elapsed is "<<timeElapsed;
}
void grades(int arr[], int number){
  for(int i =0; i<number;i++){
    if(arr[i]>90){ cout<<"The grade is A";}
    else if(arr[i]>80) { cout<<"The grade is B";}
    else if(arr[i]>70){ cout<<"The grade is C";}
    else if(arr[i]>60){  cout<<" The grade is D";}
    else if(arr[i]<60){  cout<<"The grade is Fail";} }
}
int generateRandom(){
   int num;
   num =(rand() %100) +1 ;
  return num;
}