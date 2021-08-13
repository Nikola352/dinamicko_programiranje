/* 
Iz datog niza prirodnih brojeva izdvojiti 
podniz ciji je zbir elemenata dati broj m 
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int m;
    cin >> m;

    bool dp[m+1];
    int le[m+1];
    for(int i=0; i<=n; i++){
        for(int j=m; j>=0; j--){
            if(j == 0){
                dp[j] = 1;
                le[j] = 0;
            } else if(i == 0){
                dp[j] = 0;
                le[j] = 0;
            } else if(j >= arr[i-1] && dp[j-arr[i-1]]){
                dp[j] = 1;
                le[j] = i;
            }
        }
    }

    if(dp[m]){
        stack<int> st;
        int s = m;
        while(le[s] > 0){
            st.push(arr[le[s]-1]);
            s -= arr[le[s]-1];
        }    
        cout << st.top();
        st.pop();
        while(!st.empty()){
            cout << " + " << st.top();
            st.pop();
        }
        cout << " = " << m << '\n';
    } else {
        cout << "ne postoji podniz sume " << m << '\n';
    }

    return 0;
}