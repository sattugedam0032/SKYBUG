#include<iostream>
using namespace std;



int main(){
    int a,b;
    char c ;
    
    cout << "Enter first number : "<< endl;
    cin >> a;
    cout << "Enter second number : "<< endl;
    cin >> b;
    cout << "Enter operator : "<< endl;
    cin >> c;
    
    if(c == '+'){
        cout << "your answer is "<< (a+b)<< endl;
    }else if(c == '-'){
        cout << "your answer is "<< (a-b)<< endl;
    }else if(c == '*'){
        cout << "your answer is " << (a*b)<< endl;
    }else if(c == '/'){
        if(b==0){
            cout << "Error"<< endl;
        }else{
            cout << "your answer is "<< float(a/b)<< endl;
        }
        
    }
    
    
}