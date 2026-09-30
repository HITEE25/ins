#include <iostream>
using namespace std;

string encrypt(string text, int key) {
    string result = "";
    for(char c : text) {
        if(isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += (c - base + key) % 26 + base;
        }
    }
    return result;
}

string decrypt(string text, int key) {
    return encrypt(text, 26 - key);
}

int main() {
    string text = "HELLO";
    int key = 3;

    string enc = encrypt(text, key);
    cout << "Encrypted: " << enc << endl;
    cout << "Decrypted: " << decrypt(enc, key);
}