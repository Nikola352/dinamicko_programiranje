#include <bits/stdc++.h>
using namespace std;

void fillRect(int rect[100][100], int r, int c, int n, int m, bool vh[100][100], int dpi[100][100]){
    static int col = 0;
    if(n == m){
        col++;
        for(int i=r; i<r+n; i++)
            for(int j=c; j<c+m; j++)
                rect[i][j] = col;
    } else if(vh[n][m]){
        fillRect(rect, r, c, n, dpi[n][m], vh, dpi);
        fillRect(rect, r, c+dpi[n][m], n, m-dpi[n][m], vh, dpi);
    } else {
        fillRect(rect, r, c, dpi[n][m], m, vh, dpi);
        fillRect(rect, r+dpi[n][m], c, n-dpi[n][m], m, vh, dpi);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int dp[100][100], dpi[100][100];
    bool vh[100][100];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i == j)
                dp[i][j] = 1;
            else {
                dp[i][j] = INT_MAX;
                for(int k=1; k<i; k++){
                    if(dp[k][j] + dp[i-k][j] < dp[i][j]){
                        dp[i][j] = dp[k][j] + dp[i-k][j];
                        vh[i][j] = 0;
                        dpi[i][j] = k;
                    }
                }
                for(int k=1; k<j; k++){
                    if(dp[i][k] + dp[i][j-k] < dp[i][j]){
                        dp[i][j] = dp[i][k] + dp[i][j-k];
                        vh[i][j] = 1;
                        dpi[i][j] = k;
                    }
                }
            }
        }
    }

    cout << dp[n][m] << '\n';

    int rect[100][100];
    fillRect(rect, 0, 0, n, m, vh, dpi);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout << rect[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}