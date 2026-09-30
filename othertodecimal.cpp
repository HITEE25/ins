#include<iostream>
using namespace std;

int main(){
    string num;
    int base;

    cin >> num;
    cin >> base;

    int ans = 0;

    for(int i=0;i<num.size();i++){
        int digit;

        if(num[i] >= '0' && num[i] <= '9'){
            digit = num[i] - '0';
        }
        else{
            digit = num[i] - 'A' + 10;
        }

        ans = ans * base + digit;
    }
    cout << ans << " ";
}