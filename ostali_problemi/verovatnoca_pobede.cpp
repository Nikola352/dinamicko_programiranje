#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double p, q;
    cin >> p;
    q = 1 - p;

    double dp[n+1];

    for(int i=0; i<n; i++)
        dp[i] = 1;
    dp[n] = 0;

    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            dp[j] = p * dp[j] + q * dp[j+1];
        }
    }

    cout << setprecision(3) << dp[0] << '\t' << (1-dp[0]) << '\n';

    return 0;
}