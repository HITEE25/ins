#include <iostream>
using namespace std;

int main() {
    string text = "HELLO", key = "KEY";
    string enc = "", dec = "";

    // Encryption
    for(int i = 0; i < text.length(); i++) {
        int t = text[i] - 'A';
        int k = key[i % key.length()] - 'A';
        enc += char((t + k) % 26 + 'A');
    }

    // Decryption
    for(int i = 0; i < enc.length(); i++) {
        int t = enc[i] - 'A';
        int k = key[i % key.length()] - 'A';
        dec += char((t - k + 26) % 26 + 'A');
    }

    cout << "Encrypted: " << enc << endl;
    cout << "Decrypted: " << dec;
}