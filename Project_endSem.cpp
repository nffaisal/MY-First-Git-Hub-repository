#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime> 
#include <string>
#include <cctype>
#include <time.h>
#include <chrono>
#include <iomanip>
#include<thread>
#include<numeric>
#include<vector>
using namespace std;
using namespace std::chrono;
// Function protoTypes
void stop_function(int a);
double words_per_minute(auto start_time,auto stop_time, int total_words);
void levels(vector <string> word_bank, int total_words);
void leveling_System(int error_count);
void levels_with_word_amount(int word_amount);
int choice;
//Global Variables
int unlock_2 = 0;//level 2 not unlocked
int unlock_3 =0;//level 3 not unlocked
bool game_won =false;
//Colors
const std::string COLOR_RED = "\x1b[31m";
const std::string COLOR_GREEN = "\x1b[32m";
const std::string COLOR_RESET = "\x1b[0m";

// function to delay the count down by a second
void stop_function(int a){
    this_thread::sleep_for(std::chrono::seconds(a)); 
}

// function to calculate words per minute
double words_per_minute(auto start_time,auto stop_time, int total_words){
     auto time_elapsed = stop_time - start_time; // calculating time taken
     auto total_time = duration_cast<milliseconds>(time_elapsed).count() / 60000.0;//converting milliseconds to minutes
     double word_per_minute = (total_words / total_time);
     return word_per_minute;
}

// Word bank for level 1 (easy)
vector<string> words_easy = {
    "apple","ball","cat","dog","egg","fish","goat","hat","ice","jam","kite","lion","moon","nest","owl","pen","queen","rat","sun","tree","umbrella","van","wolf","xray","yarn","zebra","book","car","desk","ear","frog","game","hand","ink","jug","key","lamp","milk","net","orange","pig","quill","rope","ship","top","unit","vase","water","yard","zip","ant","bag","cup","door","eye","fan","gum","hill","iron","jar","kid","leaf","map","nose","oil","pan","quiz","ring","sock","tent","use","vote","wind","axe","young","zone","air","bed","coin","dust","elf","fire","gold","home","iceberg","joke","king","lake","man","nut","open","play","quiet","road","sand","time","up","voice","warm","year"
};
// Word bank for level 2 (medium)
vector <string> words_medium = {
    "abstract","balance","capture","decisive","elegant","fiction","generate","harmony","improve","justice","kingdom","language","maintain","neutral","observe","pattern","qualify","recover","significant","tension","upgrade","variety","wisdom","youthful","zealous","complex","deliver","enhance","frequent","glimmer","historic","identify","journey","kinetic","logical","migrate","notable","organize","perceive","quantify","reflect","sustain","transform","utilize","vivid","wonder","yield","zone","adventure","barrier","concept","dynamic","emerge","fluent","govern","heritage","illustrate","judgment","keen","liberty","modify","navigate","option","precise","qualitative","relevant","strategy","theory","ultimate","variable","welfare","analysis","boundary","cherish","dominate","emphasis","framework","gratitude","hypothesis","intense","justify","landscape","mechanism","notion","optimal","persuade","radiate","sequence","transition","versatile","withdraw","approximate","conclude","devote","expand","fortify","genuine","interpret","mediate","persist"
};
// Word bank for level 3 (hard)
vector<string> words_hard = {
    "aberration","abstruse","acquiesce","adjudicate","alacrity","amorphous","anachronistic","antithesis","apocryphal","arboreal","belligerent","cacophony","circumlocution","clandestine","cognizant","conflagration","conundrum","corporeal","credulous","deleterious","demagogue","denigrate","diaphanous","disparate","ebullient","eclectic","egregious","enervate","ephemeral","equanimity","esoteric","evanescent","exacerbate","fastidious","fortuitous","garrulous","grandiloquent","gregarious","hackneyed","iconoclast","idiosyncratic","impecunious","imperious","incontrovertible","indefatigable","ineffable","inexorable","ingratiate","insidious","inveterate","juxtaposition","lachrymose","laconic","lexicon","lugubrious","magnanimous","malevolent","mendacious","meticulous","moribund","nefarious","nonplussed","obfuscate","obsequious","omnipotent","opprobrium","parsimony","pejorative","perfunctory","peripatetic","perspicacious","phlegmatic","precarious","precipitous","predilection","premonition","prevaricate","proclivity","propensity","protuberant","quintessential","recalcitrant","recondite","recrimination","redolent","sagacious","salient","sanguine","solicitous","tenuous","trenchant","ubiquitous","unfathomable","vicissitude","vindicate","vitriolic","vociferous","zeitgeist","zephyr","zealotry"
};
// using vectors instead of arrays as vectors allow the index to be a variable
void levels(vector <string> word_bank, int total_words, int choice =1){
    int error_count = 0; // initializing error count to 0
    vector<string> selected_words; // vector for our randomized words prompt
    for (int i = 0; i < total_words; i++){
        int index = rand() % word_bank.size(); // generating random words
        selected_words.push_back(word_bank[index]); // appending the words to the selected words vector
    }
    for (const auto& w : selected_words){
        cout << w << " "; //displaying the selected words
    }
    cout << endl;
    cout << "------- Start Typing -------" << endl;
    cout << endl;
    cout << "Press Enter to start ... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //this line allows the user to press enter to start, actually it just ignores the input from the user at this line and when we press enter the code continues and the next line is excuted
    // delaying the countdown
    cout << "1...."; stop_function(1);
    cout << "2...."; stop_function(1);
    cout << "3...."; stop_function(1);
    cout << endl;
    string input;
    auto start = steady_clock::now(); // starting the timer after the count down
    for (int i = 0; i < total_words; i++){
        string input; // using a string to get input because vectors dont allow direct input like arrays
        cin >> input;
        if (input != selected_words[i]){
            error_count++; // incrementing error count for each spelling mistake
            cout << COLOR_RED << input<< " X " << COLOR_RESET<<" "; //if word incorrect displayed as red
        }else{
          cout << COLOR_GREEN << input << COLOR_RESET<<" "; // if word correct displayed as green
        }
    }
    auto stop = steady_clock::now(); // stopping the timer when all the input are taken from the user
    cout << fixed << setprecision(2); // setting result to 2 decimal places
    cout << "\nYour Typing speed is " <<  COLOR_GREEN  <<words_per_minute(start, stop, total_words) <<" WPM\n" <<COLOR_RESET; // words per min output
    cout << "\nThe amount of error in your typing are : " << COLOR_RED << error_count << COLOR_RESET << endl; // accuracy errors output
    stop_function(5);
    if(choice ==1){
    leveling_System(error_count); //Call levelling function to decide if player should proceed next level
    }
}
void leveling_System(int error_count){
  if(error_count >=9){
     cout << "Accuracy: *" << endl;
      unlock_2 = 0; // locking level 2
      unlock_3 = 0; // locking level 3
      cout << endl;
  }else{
     switch(error_count){
      case 0:
      cout << "Accuracy: *****" << endl;
        if (unlock_3==1) { 
        game_won = true; 
        return;// return to levels wit word amount to finsih loop. game ends.
    }
        if(unlock_2==1){
          unlock_3 = 1; // unlock only after level 2 is completed
        }
        unlock_2 = 1;
        break;
      case 1:
      case 2:
        cout << "Accuracy: ****" << endl;
         if(unlock_2==1){
          unlock_3 = 1; // unlock only after level 2 is completed
        }
        unlock_2 = 1; // unlocking level 2
        break;
      case 3:
      case 4:
      case 5:
        cout << "Accuracy: ***" << endl;
        unlock_3 = 0; // lock level 3
        cout<<endl;
        break;
      case 6:
      case 7:
      case 8:
        cout << "Accuracy: **" << endl;
        unlock_2 = 0; // lock level 2
        unlock_3 = 0; // lock level 3
        cout << endl;
        break;
        }
  }
}
//function creating levels and upgrading with specific word_amount.
  void levels_with_word_amount(int word_amount){
   while (!game_won){
        if (unlock_3 == 1) { 
            cout << "\n\tLevel 3\t" << endl;
            levels(words_hard, word_amount * 3,1);   //three times word_amount and from difficult level
        } else if (unlock_2 == 1) { 
            cout << "\n\tLevel 2\t" << endl;
            levels(words_medium, word_amount * 2, 1);//two times word_amount and from medium level
            
        } else {
            // Default: Play Level 1.
            cout << "\n\tLevel 1\t" << endl;
            levels(words_easy, word_amount * 1,1);//word_amount and from easy word bank
        }
    }
}
int main(){
    // using srand for a randomized prompt on each attempt
    srand(time(0));
    int option;
    int end_program =0 ;
    int word_amount;
    // Intro to user with playbook
    cout<<"---------------------------------------------------------------------------------------------------------------------";
    cout<<"\t\t\t CODEFLOW!! \n\t\t Type, Type again!";
    cout << "Codeflow aims to help its users become accurate and fast typists, but hold your horses becuase speed is nothing without consistency.\n To be the best typist you can be, it is essential to first focus on your accuracy and then increase your speed from there on. " << endl;
    cout << endl;
    cout << "1. Codeflow has 3 difficulty levels (Noob, Pro, Hacker)." << endl;
    cout << "2. By achieving 4 Stars in accuracy in level 1 you can unlock level 2." << endl;
    cout << "3. By achieving 5 Stars in accuracy in level you can unlock the next levels." << endl;
    cout << "4. Level 3 can only be unlocked by achieveing 5 stars in accuracy." << endl;
    cout << "5. If your accuracy is reduced in later stages you can be DEPORTED back to level 1 or lock higher difficulty levels." << endl;
    cout<<  "6. After improving accuracy you can continue on to improve speed!" << endl;;
    cout << "7. With that said goodluck!" << endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------";
    cout<<"\nPick: \n1. Accuracy\n  2. Speed\n--> \t";
     // Check if option is among 1 or 2
     do{
      cin>>choice;
      if(choice>2 || choice <1){
        cout<<"REENETER:";
      }else{
        break;
      }}while(true);
    switch(choice){
      case 1:// for accuracy  checking. presents two options from accuracy, default word count or customized
         cout<<"\nPick Option:\n 1. Default Word Amount (10,20,30):  \n 2. Customized Word Amount (limit: 1 - 15): \n-->\t"; //Letting player choose amount of words.
         do{
             cin>>option;
               if(option >2 || option<1){
                    cout<< "Enter Valid option 1 or 2\n -->\t";  //if  incorrect option picked
               }else{
                   break;
               }
        }while(true);
        switch(option){
           case 1:
              levels_with_word_amount(10); break;
           case 2:
              cout<<"Enter word Amount:\n";
              do{
                cin>>word_amount; //Enter amount between 0 - 15 to set word amount
                if(word_amount >15 || word_amount <0){
                   cout<< "Enter Valid Amount\n"; 
                }else{
                   break;
               }
             }while(true);
             levels_with_word_amount(word_amount); 
             break ; //call levels to be made with specific word count from player.
          default:
             levels_with_word_amount(10);break;
            }
       cout << "    \tCONGRATULATIONS: YOU WIN!\n     " ;
       cout << "\tYou achieved 5-star accuracy on the HARDEST level!\n";
       break;
   case 2:
    cout<<"For speed you can choose any level and keep trying until wpm increases!\n.  press: 1. easy \n2. hard \n3.difficult \n4. end program\n -->\t";
     int choose;
     while(end_program != 1){
      cout<<"\n Enter an option: \t";
      cin>> choose;
      switch(choose){
        case 1:
          levels(words_easy,10,2); break;
        case 2:
          levels(words_medium,10, 2); break;
        case 3:
          levels(words_hard,10, 2);break;
        case 4:
        default:
            end_program =1; break;
         }
      }
   }

    
    //applying a loop because we need to continue the program until the user doesnt close it else just simple fuction calls and devising levels depending on the word banks
    cout << "  \nEnd of game!\n    ";

    return 0;
}
