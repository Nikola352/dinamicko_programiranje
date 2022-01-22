#include <bits/stdc++.h>
using namespace std;

const int N = 105, P = 105;
short mem[N][P];

// rekurzivna funkcija racuna oko 30% potproplema koji bi bili izracunati iterativno
bool canWin(int n, int t, int p, int q){
    if(n == 0) return false;

    if(mem[n][t] != -1) return mem[n][1];

    for(int i=1; i<=min(p, t+q); i++){
        if(!canWin(n-i, i, p, q)){
            mem[n][t] = 1;
            return true;
        }
    }

    mem[n][t] = 0;
    return false;
}

int main()
{
    int n, p, q;
    cin >> n >> p >> q;

    // ova inicijalizacija je n*p operacija
    for(int i=0; i<=n; i++)
        for(int j=0; j<=p; j++)
            mem[i][j] = -1;

    bool res = false;
    for(int i=1; i<=p; i++)
        res = (res || canWin(n, i, p, q));
    cout << (res ? "pobeda\n" : "poraz\n");

    return 0;
}