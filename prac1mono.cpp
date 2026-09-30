#include <iostream>
using namespace std;

string key = "QWERTYUIOPASDFGHJKLZXCVBNM";

int main() {
    string text = "HELLO";
    string enc = "", dec = "";

    // Encryption
    for(char c : text)
        enc += key[c - 'A'];

    // Decryption
    for(char c : enc) {
        for(int i = 0; i < 26; i++) {
            if(key[i] == c) {
                dec += char('A' + i);
                break;
            }
        }
    }

    cout << "Encrypted: " << enc << endl;
    cout << "Decrypted: " << dec;
}