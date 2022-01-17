#include <bits/stdc++.h>
using namespace std;

const int N = 100, M = 100;
short mem[N][M];

bool can(int n, int m, const string& x, const string& y){
    if(m == -1) return (n == -1);
    
    if(x[n] == 'A' && y[m] == '1') return false;

    if(mem[n][m] != 2) return mem[n][m];
    
    for(int i=m; i>=0 && y[i]==y[m]; i--){
        if(can(n-1, i-1, x, y)){
            mem[n][m] = 1;
            return true;
        }
    }

    mem[n][m] = 0;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string x, y;
    cin >> x >> y;

    // mem :  0 -> nemoguce, 1 -> moguce, 2 -> nije izracunato
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            mem[i][j] = 2;

    if(can(n-1, m-1, x, y)) cout << "moze\n";
    else cout << "ne moze\n";

    return 0;
}