#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int dp[n+1];
    dp[0] = 0;
    dp[1] = max(0, arr[0]);
    for(int i=2; i<=n; i++){
        dp[i] = max(dp[i-1], dp[i-2]+arr[i-1]);
    }

    cout << dp[n] << '\n';

    return 0;
}