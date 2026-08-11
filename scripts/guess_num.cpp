#include "bits/extc++.h"

using namespace std;

int main(){
    while(1){
        cout<<"Guess a number 1-100 (positive integers plez)\n";
        cout<<"don't troll with input, program WILL crash\n";
        int n = 1+(rand()%100);
        int num=0;
        int guess=0;
        while(num<6 && guess!=n){
            cout<<"this is your "<<num+1<<" out of 6 guesses (ok, there's no grammar in that but ok)\n";
            cin>>guess;
            if(guess>n){
                cout<<"guess lower!\n";
            }else if(guess<n){
                cout<<"guess higher!\n";
            }else{
                cout<<"SPOT ON!\n";
            }
            num++;
        }
        if(num==6){
            cout<<"you lose!\n";
        }
    }
}
