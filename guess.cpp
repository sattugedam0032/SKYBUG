#include<iostream>
#include<cstdlib>
using namespace std;


int main(){
    int a = rand() % 100;
    int b;
    cout << "enter number: "<< endl;
    cin >> b;
    
    while(b != a ){
        if(b > a){
            cout << "too high, guess again"<< endl;
            cin >> b;
        }else{
            cout << "too low, guess again"<< endl;
            cin >> b;
        }
    }
    
    cout << "Hola! you guessed it correct."<< endl;
    
}