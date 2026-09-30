#include <iostream>
#include <cmath>
using namespace std;

// power mod function
long long power(long long a, long long b, long long mod) {
    long long res = 1;
    while(b > 0) {
        if(b % 2 == 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

int main() {
    long long p = 23;  // prime
    long long g = 5;   // primitive root

    long long a = 6; // private key of A
    long long b = 15; // private key of B

    // public keys
    long long A = power(g, a, p);
    long long B = power(g, b, p);

    // shared keys
    long long keyA = power(B, a, p);
    long long keyB = power(A, b, p);

    cout << "Public Key A: " << A << endl;
    cout << "Public Key B: " << B << endl;

    cout << "Shared Key (A): " << keyA << endl;
    cout << "Shared Key (B): " << keyB << endl;
}