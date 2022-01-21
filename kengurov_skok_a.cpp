#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int dp[2][n+1];
    dp[0][0] = 1;
    for(int i=1; i<=n; i++)
        dp[0][i] = 0;

    for(int i=1; i<=k; i++){
        dp[1][0] = 0;
        for(int j=1; j<=n; j++){ 
            dp[1][j] = dp[1][j-1] + dp[0][j-1];
            if(j > m) dp[1][j] -= dp[0][j-m-1];
        }
        for(int j=0; j<=n; j++)
            dp[0][j] = dp[1][j];
    }

    cout << dp[1][n] << '\n';

    return 0;
}