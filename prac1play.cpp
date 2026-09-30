#include <iostream>
using namespace std;

char matrix[5][5] = {
    {'M','O','N','A','R'},
    {'C','H','Y','B','D'},
    {'E','F','G','I','K'},
    {'L','P','Q','S','T'},
    {'U','V','W','X','Z'}
};

void findPos(char ch, int &r, int &c) {
    if(ch=='J') ch='I';
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(matrix[i][j]==ch){ r=i; c=j; }
}

string encrypt(string text) {
    string res="";
    for(int i=0;i<text.length();i+=2) {
        int r1,c1,r2,c2;
        findPos(text[i],r1,c1);
        findPos(text[i+1],r2,c2);

        if(r1==r2)
            res += matrix[r1][(c1+1)%5], res += matrix[r2][(c2+1)%5];
        else if(c1==c2)
            res += matrix[(r1+1)%5][c1], res += matrix[(r2+1)%5][c2];
        else
            res += matrix[r1][c2], res += matrix[r2][c1];
    }
    return res;
}

string decrypt(string text) {
    string res="";
    for(int i=0;i<text.length();i+=2) {
        int r1,c1,r2,c2;
        findPos(text[i],r1,c1);
        findPos(text[i+1],r2,c2);

        if(r1==r2)
            res += matrix[r1][(c1+4)%5], res += matrix[r2][(c2+4)%5];
        else if(c1==c2)
            res += matrix[(r1+4)%5][c1], res += matrix[(r2+4)%5][c2];
        else
            res += matrix[r1][c2], res += matrix[r2][c1];
    }
    return res;
}

int main() {
    string text="HE";
    string enc = encrypt(text);
    string dec = decrypt(enc);

    cout<<"Encrypted: "<<enc<<endl;
    cout<<"Decrypted: "<<dec;
}