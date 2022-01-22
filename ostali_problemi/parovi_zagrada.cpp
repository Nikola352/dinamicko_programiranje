// isti kod radi i za zadatak "Broj binarnih drveta"
// (racunanje n-tog Katalanovog broja)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int dp[n+1];
    dp[0] = 1;

    for(int i=1; i<=n; i++){
        dp[i] = 0;
        for(int j=0; j<i; j++)
            dp[i] += dp[j] * dp[i-j-1];
    }

    cout << dp[n] << '\n';

    return 0;
}