#include <bits/stdc++.h>
using namespace std;

const int N = 150;
int arr[N];

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<n; i++)
        cin >> arr[i];

    int dp[N][10*N];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=10*n; j++)
            dp[i][j] = -1;
    }

    for(int i=n-1; i>=0; i--){
        for(int j=1; j<10*n; j++){
            if(j >= (n-i)*10) break; // sprat je izgorio

            if(j >= i + 15) dp[i][j] = arr[i]; // sa prizemlja

            if(dp[i+1][j-1] != -1) // sa sprata iznad, ne uzima novac
                dp[i][j] = max(dp[i][j], dp[i+1][j-1]);

            if(j > 15 && dp[i+1][j-16] != -1) // sa sprata iznad, uzima novac
                dp[i][j] = max(dp[i][j], dp[i+1][j-16] + arr[i]);
        }
    }

    int res = 0;
    for(int i=0; i<10*n; i++)
        res = max(res, dp[0][i]);

    cout << res << '\n';

    return 0;
}