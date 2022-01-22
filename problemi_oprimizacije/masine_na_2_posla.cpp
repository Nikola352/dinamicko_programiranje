// ???
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int d1[n+1], r1[n+1], d2[n+1], r2[n+1];
    d1[0] = d2[0] = r1[0] = r2[0] = 0;
    for(int i=1; i<=n; i++)
        cin >> d1[i];
    for(int i=1; i<=n; i++)
        cin >> r1[i];
    for(int i=1; i<=n; i++)
        cin >> d2[i];
    for(int i=1; i<=n; i++)
        cin >> r2[i];

    int dp[n+1];
    for(int i=0; i<=n; i++)
        dp[i] = 0;

    for(int i=1; i<=m; i++){
        for(int j=n; j>0; j--){
            dp[j] = 0;
            for(int k=0; k<=j; k++){
                int pot = dp[r1[k]+r2[j-k]] + d1[k] + d2[j-k];
                if(pot > dp[j]){
                    dp[j] = pot;
                }
            }
        }
    }

    cout << dp[n] << '\n';

    return 0;
}