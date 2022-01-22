#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int arr[m][n], dp[m][n];
    pair<int, int> from[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            dp[i][j] = INT_MIN;
            from[i][j] = make_pair(-1, -1);
        }
    }
        
    dp[0][0] = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i > 0 && dp[i-1][j] > dp[i][j]){
                dp[i][j] = dp[i-1][j];
                from[i][j] = make_pair(i-1, j);
            }
            if(j > 0  && dp[i][j-1] > dp[i][j]){
                dp[i][j] = dp[i][j-1];
                from[i][j] = make_pair(i, j-1);
            }
            dp[i][j] += arr[i][j];
        }
    }

    cout << dp[m-1][n-1] << '\n';
    int i=m-1, j=n-1;
    stack<pair<int,int>> st;
    while(from[i][j].first != -1){
        st.push(from[i][j]);
        int t = i;
        i = from[i][j].first;
        j = from[t][j].second;
    }
    while(!st.empty()){
        cout << st.top().first << ", " << st.top().second << '\n';
        st.pop();
    }
    cout << m-1 << ", " << n-1 << '\n';

    return 0;
}