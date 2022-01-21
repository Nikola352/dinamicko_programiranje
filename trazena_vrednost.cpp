#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.length();

    bool dp[3][n][n];
    for(int i=0; i<n; i++){
        dp[0][i][i] = dp[1][i][i] = dp[2][i][i] = false;
        dp[s[i]-'a'][i][i] = true;
    }

    for(int l=2; l<=n; l++){
        for(int i=0; i<n-l+1; i++){
            int j = i + l - 1;
            dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = false;
            for(int k=i; k<j; k++){
                bool isA = (
                    (dp[2][i][k] && dp[0][k+1][j])
                    || (dp[0][i][k] && dp[2][k+1][j])
                    || (dp[1][i][k] && dp[2][k+1][j])
                );
                dp[0][i][j] = (dp[0][i][j] || isA);

                bool isB = (
                    (dp[0][i][k] && dp[0][k+1][j])
                    || (dp[0][i][k] && dp[1][k+1][j])
                    || (dp[1][i][k] && dp[1][k+1][j])
                );
                dp[1][i][j] = (dp[1][i][j] || isB);

                bool isC = (
                    (dp[1][i][k] && dp[0][k+1][j])
                    || (dp[2][i][k] && dp[1][k+1][j])
                    || (dp[2][i][k] && dp[2][k+1][j])
                );
                dp[2][i][j] = (dp[2][i][j] || isC);
            }
        }
    }

    cout << (dp[0][0][n-1] ? "moze\n" : "ne moze\n");

    return 0;
}