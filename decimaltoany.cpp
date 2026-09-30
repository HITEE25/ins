#include<iostream>
using namespace std;

string covertion(int num,int base){
    string digits = "0123456789ABCDEF";
    string ans;

    while(num > 0){
        int r = num % base;
        ans = digits[r] + ans;
        num = num / base;
    }

    return ans;
}

int main(){
    int num;
    int base;

    cin >> num;
    cin >> base;

    string converted = covertion(num,base);

    cout << converted;
}