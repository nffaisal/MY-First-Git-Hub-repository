#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime> 
using namespace std;
int dice(){
    srand(0);
    int num = rand() %6 +1;

}
int main(){
    int player1_x=9 ;
    int player2_x =9;
    
    char player1, player2;
    cout<<"chooe your character:";
    cin>>player1;
    cout<<"choose you character player 2";
    cin>>player2;
    char grid[10][10] ={{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    };
       for(int i=0;i<10;i++){
         for(int j=0;j<10;j++){
               cout<<grid[i][j];
               if(grid[9][0]){
                 grid[9][0] = player1;
               }
         }
       }
    return 0;
}
