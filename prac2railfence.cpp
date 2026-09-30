#include <iostream>
using namespace std;

// Encryption
string encrypt(string text, int key) {
    string rail[key];
    int row = 0, dir = 1;

    for(char c : text) {
        rail[row] += c;

        if(row == 0) dir = 1;
        else if(row == key-1) dir = -1;

        row += dir;
    }

    string result = "";
    for(int i=0;i<key;i++)
        result += rail[i];

    return result;
}

// Decryption
string decrypt(string cipher, int key) {
    int n = cipher.length();
    char rail[key][n];

    // Step 1: Fill with '*'
    for(int i=0;i<key;i++)
        for(int j=0;j<n;j++)
            rail[i][j] = '\n';

    // Step 2: Mark zig-zag pattern
    int row = 0, dir = 1;
    for(int i=0;i<n;i++) {
        rail[row][i] = '*';

        if(row == 0) dir = 1;
        else if(row == key-1) dir = -1;

        row += dir;
    }

    // Step 3: Fill cipher text row-wise
    int index = 0;
    for(int i=0;i<key;i++) {
        for(int j=0;j<n;j++) {
            if(rail[i][j] == '*' && index < n) {
                rail[i][j] = cipher[index++];
            }
        }
    }

    // Step 4: Read zig-zag to get original
    string result = "";
    row = 0, dir = 1;

    for(int i=0;i<n;i++) {
        result += rail[row][i];

        if(row == 0) dir = 1;
        else if(row == key-1) dir = -1;

        row += dir;
    }

    return result;
}

int main() {
    string text = "HELLO";
    int key = 3;

    string enc = encrypt(text, key);
    string dec = decrypt(enc, key);

    cout << "Encrypted: " << enc << endl;
    cout << "Decrypted: " << dec;
}