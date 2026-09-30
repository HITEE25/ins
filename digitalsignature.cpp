#include <iostream>
using namespace std;

// simple power mod
long long modExp(long long base, long long exp, long long mod) {
    long long res = 1;
    while(exp) {
        if(exp % 2) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    long long p = 3, q = 11;
    long long n = p * q;
    long long phi = (p-1)*(q-1);

    long long e = 3;  // public key
    long long d = 7;  // private key

    long long message = 9;

    // Signing
    long long signature = modExp(message, d, n);

    // Verification
    long long verify = modExp(signature, e, n);

    cout << "Message: " << message << endl;
    cout << "Signature: " << signature << endl;
    cout << "Verified Message: " << verify << endl;
}