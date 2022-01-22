#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int t[n], p[n-1];
    for(int i=0; i<n; i++)
        cin >> t[i];
    for(int i=0; i<n-1; i++)
        cin >> p[i];

    int dp[n+1];
    dp[0] = 0;
    dp[1] = t[0];

    bool dpi[n+1] = {0};

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + t[i-1];
        if(dp[i-2] + p[i-2] < dp[i]){
            dp[i] = dp[i-2]+p[i-2];
            dpi[i] = 1;
        }
        
    }

    cout << dp[n] << '\n';

    stack<int> st;
    for(int i=n; i>0; i--){
        if(dpi[i]){
            st.push(i-1);
            i--;
        }
    }

    while(!st.empty()){
        cout << st.top() << ' ';
        st.pop();
    }

    cout << '\n';

    return 0;
}