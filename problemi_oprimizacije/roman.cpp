#include <bits/stdc++.h>
using namespace std;

void print(int dpi[100][100], int n, int k){
    if(k == 0) return;
    print(dpi, dpi[n][k], k-1);
    cout << n-dpi[n][k] << ' ';
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[100];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int dp[100][100], dpi[100][100];
    for(int i=0; i<=k; i++)
        dp[0][i] = 0;
    
    for(int i=1; i<=n; i++)
        dp[i][1] = dp[i-1][1] + arr[i-1];

    int maxelem = 0;
    for(int i=1; i<=n; i++){
        maxelem = max(maxelem, arr[i-1]);
        dp[i][i] = maxelem;
        for(int j=2; j<=k && j<i; j++){
            dp[i][j] = INT_MAX;
            int br = arr[i-1];
            for(int p=i-1; p>=j-1; p--){
                int pot = max(dp[p][j-1], br);
                if(pot < dp[i][j]){
                    dp[i][j] = pot;
                    dpi[i][j] = p;
                }
                br += arr[p-1];
            }
        }
    }

    cout << dp[n][k] << '\n';
    print(dpi, n, k);
    cout << '\n';
    
    return 0;
}