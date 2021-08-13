#include <bits/stdc++.h>
using namespace std;

void print(int n, int dpi[]){
    if(n==1){
        cout << "K";
    }else if(dpi[n] == n-1){
        print(n-1, dpi);
        cout << "*K";
    } else {
        if(dpi[n] != 1)
            cout << "(";
        print(dpi[n], dpi);
        if(dpi[n] != 1)
            cout << ")";
        cout << "**" << n/dpi[n];
    }
}

int main()
{
    int n;
    cin >> n;

    int dp[n+1];
    dp[0] = dp[1] = 0;

    int dpi[n+1];

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + 1;
        dpi[i] = i-1;
        for(int j=1; j<i; j++){
            if(i%j==0 && dp[j]+i/j-1 < dp[i]){
                dp[i] = dp[j]+i/j-1;
                dpi[i] = j;
            }
        }
    }

    cout << dp[n] << '\n';

    print(n, dpi);

    cout << '\n';

    return 0;
}