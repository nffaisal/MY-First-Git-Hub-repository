#include <iostream>
#include <chrono>
#include <cctype>
#include <string>
#include <iomanip>
using namespace std::chrono;
using namespace std;

 // Global Variables
    int unlock_2 =0;
    int unlock_3=0;
//Function to create Levels
void words_per_minute();
 void levels(string word_bank[],int total_numbers){
    string words; //represents user input
    string selected_words[100]; //max size
    for(int i=0;i<total_numbers;i++){
        int index = rand()% 100; //generating random index with rand()
        selected_words[i]=word_bank[index]; //adding selected word from word bank
    }
    for(int i =0;i<total_numbers;i++){
         cout<<selected_words[i]<<" ";    //output the selected words to the user
    }
    cout<<endl;

    //Taking input from user
    words_per_minute();
          
    }
 
int main() {
    
    //Intro TO user playbook
    cout<<"-------------------------------------------------------------------------------------------\n";
    cout<<"\tCode FLow aims to help its users become accurate and fast Typists\n but hold your To be a good typist you have to focus on accuracy and speed later:\n";
    cout<<"\tCodeflow has 3 levels (noob,pro,hacker)\n";
    cout<<"\tBy achieveing 5 stars in accuracy in level 2 you can unlock Level 3\n";
    cout<<"\tBy achieving 4 stars or more in accuracy in level 1 you can unlock level 2\n";
    cout<<"\tIf in stage 2 or 3 your accuracy decreases below 2 stars you will be reverted to level 1\n";
    cout<<"---------------------------------------------------------------------------------------------";
    cout<<"\n\t------Let's Begin!------\n";

    //Word Bank
    string word_bank[100]={"apple","banana","cherry","dog","elephant","flower","grape","house","island","jungle",
        "kite","lion","mountain","notebook","orange","pencil","queen","river","sun","tree",
        "umbrella","violin","water","xylophone","yacht","zebra","cloud","dream","energy","forest",
        "garden","happy","idea","journey","kind","light","music","night","ocean","peace",
        "quiet","road","smile","time","unity","victory","world","xenon","youth","zen",
        "anchor","bridge","castle","desert","engine","family","gold","heart","ice","joy",
        "king","lake","mirror","nest","owl","path","quest","rose","star","tower",
        "under","valley","wind","xerox","yellow","zero","alpha","bravo","charlie","delta",
        "echo","foxtrot","golf","hotel","india","juliet","kilo","lima","mango","nectar",
        "olive","plum","quartz","ruby","topaz","uranium","violet","whale","xenon"
        ,"azure"};

        levels(word_bank,20);
        return 0;}


void words_per_minute(){
    int words_amount=0;
         if(unlock_2==0){
            words_amount=20;
         }else{
            words_amount =40;
         }
     string user_text[words_amount];
     cout<<"\t------Start typing!------\t\n";
     auto start =steady_clock::now();
      for(int i=0;i<words_amount;i++){
        cin>>user_text[i];
      }
    auto stop=steady_clock::now();
    auto time_elapsed= stop - start;

    auto total_time = duration_cast<milliseconds>(time_elapsed).count() / 60000.0;; //converting milliseconds to minutes
        //Calculates word per minute
       double words_per_minute = (words_amount/total_time);
       cout<<fixed<<setprecision(2);
       cout<<"Your typing speed is "<<words_per_minute<<" WPM\n";
    }

