#include<iostream>
#include<chrono>
#include<thread>
using namespace std;
using namespace std::chrono;
void stop_program(int a){
    std::this_thread::sleep_for(std::chrono::seconds(a));
}
int main(){
    cout<<"hello"<<endl;
    stop_program(3);
    cout<<"3 secs passed";

    return 0;
}
