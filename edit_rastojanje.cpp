#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ins, rem, rep, remall;
    cin >> ins >> rem >> rep >> remall;
    string str1, str2;
    cin >> str1 >> str2;

    int n = str1.length(),
        m = str2.length();

    int dp[n+1][m+1];

    for(int j=0; j<=m; j++){
        int minj = INT_MAX;
        for(int i=0; i<=n; i++){
            if(j==0){
                dp[i][j] = min(j*rem, remall);
                minj = min(minj, dp[i][j]);
            } else if(i==0){
                dp[i][j] = m;
                minj = min(minj, m);
            } else if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = dp[i][j-1] + ins;
                dp[i][j] = min(dp[i][j], dp[i-1][j] + rem);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + rep);
                dp[i][j] = min(dp[i][j], minj + remall);
                if(dp[i][j] < minj)
                    minj = dp[i][j];
            }
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}