#include <bits/stdc++.h>
using namespace std;

const int N = 7, D = 10;

int main()
{
    vector<vector<int>> adj(D);
    adj[0] = {4, 6};
    adj[1] = {6, 8};
    adj[2] = {7, 9};
    adj[3] = {4, 8};
    adj[4] = {3, 9, 0};
    adj[6] = {1, 7, 0};
    adj[7] = {2, 6};
    adj[8] = {1, 3};
    adj[9] = {2, 4};

    int dp[N][D];
    for(int i=0; i<D; i++)
        dp[0][i] = 1;

    for(int i=1; i<N; i++){
        for(int j=0; j<D; j++){
            dp[i][j] = 0;
            for(int k : adj[j]){
                dp[i][j] += dp[i-1][k];
            }
        }
    }

    int res = 0;
    for(int i=0; i<D; i++){
        if(i != 0 && i != 8)
            res += dp[N-1][i];
    }

    cout << res << '\n';

    return 0;
}