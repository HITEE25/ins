#include <iostream>
using namespace std;

int main() {
    int p=3,q=11;
    int n=p*q;
    int phi=(p-1)*(q-1);
    int e=3, d=7;

    int msg=5;

    int c = (int)pow(msg,e)%n;
    int m = (int)pow(c,d)%n;

    cout << "Encrypted: " << c << endl;
    cout << "Decrypted: " << m;
}