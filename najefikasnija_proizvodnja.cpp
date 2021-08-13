// TODO: ispisi vrijednosti p
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, q;
    cin >> m >> n >> q;
    int t[q+1][m+1];
    for(int i=1; i<=q; i++)
        for(int j=1; j<=m; j++)
            cin >> t[i][j];

    for(int i=0; i<=m; i++)
        t[0][i] = 0;
    for(int i=0; i<=q; i++)
        t[i][0] = 0;
    
    int dp[m+1][n+1];
    for(int i=0; i<=n; i++){
        if(i <= q)
            dp[1][i] = t[i][1];
        else 
            dp[1][i] = INT_MAX;
    }

    for(int i=2; i<=m; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = INT_MAX;
            for(int k=1; k<=q && k<=j; k++)
                if(dp[i-1][j-k] != INT_MAX)
                    dp[i][j] = min(dp[i][j], dp[i-1][j-k] + t[k][i]);
        }
    }

    cout << dp[m][n] << endl;

    return 0;
}