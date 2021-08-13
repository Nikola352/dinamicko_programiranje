#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = numeric_limits<int>::max();

void floydWarshall(int n, vvi& dp, vvi& dpi){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dp[i][k] != INF && dp[k][j] != INF 
                && dp[i][k]+dp[k][j] < dp[i][j]){
                    dp[i][j] = dp[i][k]+dp[k][j];
                    dpi[i][j] = k;
                }
            }
        }
    }
}

void print(int i, int j, const vvi& p){
    int k = p[i][j];
    if(k != -1){
        print(i, k, p);
        cout << k << ' ';
        print(k, j, p);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vvi adj(n, vi(n, INF));
    for(int i=0; i<n; i++)
        adj[i][i] = 0;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }

    vvi d = adj, p(n, vi(n, -1));
    floydWarshall(n, d, p);

    int src, dest;
    cin >> src >> dest;
    cout << d[src][dest] << '\n';

    cout << src << ' ';
    print(src, dest, p);
    cout << dest << '\n';

    return 0;
}