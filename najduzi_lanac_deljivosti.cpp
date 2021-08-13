#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int dpi[], int i){
    if(dpi[i] != -1)
        print(arr, dpi, dpi[i]);
    cout << arr[i] << ' ';
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    int dp[n], dpi[n];
    dp[0] = 1;
    dpi[0] = -1;
    for(int i=1; i<n; i++){
        dp[i] = 1;
        dpi[i] = -1;
        for(int j=0; j<i; j++){
            if(arr[i] % arr[j] == 0 && dp[j]+1 > dp[i]){
                dp[i] = dp[j] + 1;
                dpi[i] = j;
            }
        }
    }

    int maxdp = 0;
    for(int i=1; i<n; i++){
        if(dp[i] > dp[maxdp])
            maxdp = i;
    }

    cout << dp[maxdp] << '\n';
    print(arr, dpi, maxdp);
    cout << '\n';
    
    return 0;
}