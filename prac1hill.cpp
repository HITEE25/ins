#include <iostream>
using namespace std;

int modInverse(int a) {
    for(int i=1;i<26;i++)
        if((a*i)%26==1) return i;
    return -1;
}

int main() {
    int key[2][2]={{3,3},{2,5}};
    int msg[2]={7,4}; // HE

    int enc[2]={0};

    // Encryption
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            enc[i]+=key[i][j]*msg[j];

    enc[0]%=26; enc[1]%=26;

    cout<<"Encrypted: "<<char(enc[0]+'A')<<char(enc[1]+'A')<<endl;

    // Decryption
    int det = (3*5 - 3*2)%26;
    if(det<0) det+=26;

    int invDet = modInverse(det);

    int invKey[2][2]={{15,17},{20,9}}; // precomputed

    int dec[2]={0};
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            dec[i]+=invKey[i][j]*enc[j];

    dec[0]%=26; dec[1]%=26;

    cout<<"Decrypted: "<<char(dec[0]+'A')<<char(dec[1]+'A');
}