#include <bits/stdc++.h>
using namespace std;

void print(int dpi[100][100], int m, int n){
    if(m < 0) return;
    print(dpi, m-1, n-dpi[m][n]);
    cout << dpi[m][n] << ' ';
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[m][n+1];
    for(int i=0; i<m; i++){
        a[i][0] = 0;
        for(int j=1; j<=n; j++)
            cin >> a[i][j];
    }  

    int dp[n+1], dpi[100][100];

    for(int i=0; i<=n; i++){
        dp[i] = a[0][i];
        dpi[0][i] = i;
    }

    for(int i=1; i<m; i++){
        for(int j=n; j>0; j--){
            dp[j] = 0;
            for(int k=0; k<=j; k++){
                int pot = dp[j-k] + a[i][k];
                if(pot > dp[j]){
                    dp[j] = pot;
                    dpi[i][j] = k;
                }   
            }
        }
    }
    
    cout << dp[n] << '\n';
    print(dpi, m-1, n);
    cout << '\n';

    return 0;
}