#include <bits/stdc++.h>
using namespace std;

void printLcs(int i, int j, int dp[101][101], int p[], int q[]){
    if(i>0 && j>0){
        if(p[i-1] == q[j-1]){
            printLcs(i-1, j-1, dp, p, q);
            cout << p[i-1] << ' ';
        } else if(dp[i-1][j] > dp[i][j-1]) {
            printLcs(i-1, j, dp, p, q);
        } else {
            printLcs(i, j-1, dp, p, q);
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    int p[100], q[100];
    for(int i=0; i<m; i++)
        cin >> p[i];
    for(int i=0; i<n; i++)
        cin >> q[i];

    int dp[101][101];
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            } else {
                if(p[i-1] == q[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }

    cout << dp[m][n] << '\n';

    printLcs(m, n, dp, p, q);

    cout << '\n';

    return 0;
}