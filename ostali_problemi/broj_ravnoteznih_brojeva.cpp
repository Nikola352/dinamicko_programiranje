#include <bits/stdc++.h>
using namespace std;

const int N = 6;
const int S = 9 * N;

int main()
{
    int dp[N+1][S+1];
    for(int i=0; i<=S; i++)
        dp[0][i] = 0;
    dp[0][0] = 1;
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<=S; j++){
            dp[i][j] = 0;
            for(int k=0; k<=min(j,9); k++){
                dp[i][j] += dp[i-1][j-k];
            }
        }
    }

    long long res = 0;
    for(int i=1; i<=S; i++)
        res += (long long)dp[N][i] * (dp[N][i] - dp[N-1][i]);
    
    cout << res << '\n';

    return 0;
}