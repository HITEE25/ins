#include <iostream>
#include <set>
using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}

int primitiveRoot(int p) {
    set<int> s;
    for(int i=1;i<p;i++) s.insert(i);

    for(int g=2;g<p;g++) {
        set<int> res;
        for(int i=1;i<p;i++)
            res.insert((int)pow(g,i)%p);

        if(res == s) return g;
    }
}

int main() {
    int p = 7;
    if(isPrime(p))
        cout << primitiveRoot(p);
}