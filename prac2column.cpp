#include <iostream>
using namespace std;

// Encryption
string encrypt(string text, int col) {
    int row = (text.length() + col - 1) / col;
    char matrix[row][col];

    int k = 0;

    // Fill row-wise
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if(k < text.length())
                matrix[i][j] = text[k++];
            else
                matrix[i][j] = 'X';
        }
    }

    // Read column-wise
    string result = "";
    for(int j=0;j<col;j++)
        for(int i=0;i<row;i++)
            result += matrix[i][j];

    return result;
}

// Decryption
string decrypt(string cipher, int col) {
    int row = (cipher.length() + col - 1) / col;
    char matrix[row][col];

    int k = 0;

    // Fill column-wise
    for(int j=0;j<col;j++) {
        for(int i=0;i<row;i++) {
            matrix[i][j] = cipher[k++];
        }
    }

    // Read row-wise
    string result = "";
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            result += matrix[i][j];

    return result;
}

int main() {
    string text = "HELLOWORLD";
    int col = 4;

    string enc = encrypt(text, col);
    string dec = decrypt(enc, col);

    cout << "Encrypted: " << enc << endl;
    cout << "Decrypted: " << dec;
}