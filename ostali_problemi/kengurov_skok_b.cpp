#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int dp[n+1];
    dp[0] = dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = 2 * dp[i-1];
        if(i > m) dp[i] -= dp[i-m-1];
    }

    cout << dp[n] << '\n';

    return 0;
}