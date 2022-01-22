// staviti zagrade tako da izraz a0-a1-...-an bude maksimalan
// (u zbirci pise minimalan, al boze moj...)
#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int dp[100][100], int dpm[100][100], int i, int j, bool m){
    if(i == j){
        cout << arr[i];
    } else if(m){
        if(dpm[j][i] == j){
            cout << arr[i];
            for(int k=i+1; k<=j; k++)
                cout << '-' << arr[k];
        } else {
            print(arr, dp, dpm, i, dpm[j][i], 1);
            cout << "-(";
            print(arr, dp, dpm, dpm[j][i]+1, j, 0);
            cout << ')';
        }
    } else {
        if(dp[j][i] == j){
            cout << arr[i];
            for(int k=i+1; k<=j; k++)
                cout << '-' << arr[k];
        } else {
            print(arr, dp, dpm, i, dp[j][i], 0);
            cout << "-(";
            print(arr, dp, dpm, dp[j][i]+1, j, 1);
            cout << ')';
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int dp[100][100], dpm[100][100], sum[100][100];
    for(int i=0; i<n; i++)
        dp[i][i] = dpm[i][i] = sum[i][i] = arr[i];

    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            sum[i][j] = sum[i][j-1] + arr[j];

    for(int l=2; l<=n; l++){
        for(int i=0; i<n-l+1; i++){
            int j = i+l-1;
            dp[i][j] = dpm[i][j] = arr[i] - sum[i+1][j];
            dp[j][i] = dpm[j][i] = j;
            for(int k=i; k<j; k++){
                int pot = dp[i][k] - dpm[k+1][j];
                if(pot > dp[i][j]){
                    dp[i][j] = pot;
                    dp[j][i] = k;
                }
                pot = dpm[i][k] - dp[k+1][j];
                if(pot < dpm[i][j]){
                    dpm[i][j] = pot;
                    dpm[j][i] = k;
                }
            }
        }
    }

    print(arr, dp, dpm, 0, n-1, 0);
    cout << '=' << dp[0][n-1] << '\n';
    
    return 0;
}