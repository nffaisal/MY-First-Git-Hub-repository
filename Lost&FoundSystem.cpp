#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include<vector>
#include <iomanip>
#include<string> 
using namespace std;
int counter_lost_items =0;
std::vector<std::string> Lost_Items;
std::vector<std::string> lost_phones;
std::vector<std::string> lost_book;
std::vector<std::string> miscellanious_items;
std::vector<std::string> date_lost;
std::vector<std::string> lost_headphones;
std::vector<std::string> location_lost;
std::vector<int> person_to_contact;

std::vector<int> Student_id_card;
 int check_student_Id(std::string Student_ID){
    if(Student_ID.length()== 6){
        int numeric_value= std::stoi(Student_ID);
        Student_id_card.push_back(numeric_value);
    }else{
        return -1;
    }
 }
 void categorize_items(){
    int type; std::string phone_type; char wallet_type; std::string headphone_color;  std::string student_ID; std::string book_name; std::string miscellanious;
    std::string headphone_brand;
        cout<<"Enter object type"<<endl;
        cout<<"1. Phone \n 2. Wallet \n 3.Headphones \n 4. Debit Card\n 5.Student ID card \n6. Book \n7. Miscellanious\n ";
        switch(type){
            case 1:
            cout<<"Type of Phone: ";
            cin>>phone_type; lost_phones.push_back(phone_type); counter_lost_items++;
            case 2:
                cout<<"Male or Female wallet( M /W ): ";counter_lost_items++;
                do{
                cin>>wallet_type;
                tolower(wallet_type);
                if(wallet_type != 'w' || wallet_type != 'm'){ cout<< "Re-enter, incorrect type";}else {break;} } while(true);
            case 4:
                cout<<"Color:  "; counter_lost_items++;
                cin>>headphone_color; 
                cout<<"enter name of brand: \n";
                cin>>headphone_brand;
                lost_headphones.push_back(headphone_color + headphone_brand);
            case 5:
                cout<<"Student Id Card number: "; counter_lost_items++;
            do{
                cin>>student_ID;
              if(check_student_Id(student_ID) ==-1){
                    cout<<"Invalid ID number RE-enter: \n";
              }else{ break; }} while(true);
            case 6:
            cout<<"Book"; counter_lost_items++;
            cin>>book_name; lost_book.push_back(book_name);
            case 7:
            cout<<"Enter Miscellanious Item name\n"; counter_lost_items++;
            cin>>miscellanious; miscellanious_items.push_back(miscellanious);
            default:
            cout<<"Exit \n";
            return;
      } 
 }   
 void date_missing(){
    std::string date, weekday, year; std::string date;
    cout<<" Enter the day of entry of item into registry:\n ";
    cin>>date;
    cout<<"Enter week day lost: ( 1 - jan | 12-sunday)";
    cin>>weekday;
    cout<<"Enter the year: \n";
    cin>>year;
    date = date +"\\ " +weekday+"\\" + year;
    date_lost.push_back(date) ;}
void person_Contact(){
    std::string person_contact;
    
    cout<<"Enter phone number: ";
    do{
    cin>>person_contact;
    if( person_contact.length()!= 11){
        cout<<"Phone Number must be 11 digits: Re-Enter: \t";}
    else{ break;}
    }while(true);
    person_to_contact.push_back(std::stoi(person_contact));

}
void location_Lost(){
    std::string location;
    cout<<"Enter location of findin lost item:\n";
    cin>>location;
    location_lost.push_back(location);
}
 int main(){
    int option;
    cout<<"LOST AND FOUND MANAGEMENT SYSTEM"<<endl;
    cout<<"Menu:"<<endl;
    cout<<"1. Register lost Items:the time of losing it,date of losing it, place of finding lost item";
    cout<<"\n2. Search for lost Item:";
    cout<<"\n 3.Display Count Of Lost Items: ";
    
    do{
        cin>>option;
        if(option>2 || option <1){
            cout<<"Invalid Choice, re-enter:\n";
        }else{ break;}
    }while(true);
    if(option==1){
        categorize_items();
        date_missing();
        person_Contact();
    }else if(option ==2){
      cout<<"choose object lost: ";
      cout<<"1. Phone \n 2. Wallet \n 3.Headphones \n 4. Debit Card\n 5.Student ID card \n6. Book \n7. Miscellanious\n ";\
      switch()

    }


 }

  