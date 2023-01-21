#include<bits/stdc++.h>
using namespace std;

void print(int digit){
    switch (digit)
        {
        case 1:
            cout<<"One ";
            break;
        case 2:
            cout<<"Two ";
            break;
        case 3:
            cout<<"Three ";
            break;
        case 4:
            cout<<"Four ";
            break;
        case 5:
            cout<<"Five ";
            break;
        case 6:
            cout<<"Six ";
            break;
        case 7:
            cout<<"Seven ";
            break;
        case 8:
            cout<<"Eight ";
            break;
        case 9:
            cout<<"Nine ";
            break;
        case 0:
            cout<<"Zero ";
            break;
        }
}

void findDigit(int n){
    if(n){
        findDigit(n/10);
        print(n%10);
    }
}

int main(){
    int n = -356;
    // cin>>n;
    if(n==0)
        cout<<"Zero";
    else if(n/1000 == 0){
        if(n<0)
            cout<<"Minus ";
        findDigit(abs(n));
    }
    else
    cout<<"Invalid Number!! Enter 3 digit number";
    return 0;
}