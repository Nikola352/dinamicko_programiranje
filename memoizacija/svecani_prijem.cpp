#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int maxT(int v, vvi& mem, const vvi& adj, const vi& t){
    if(mem[0][v] != -1) return max(mem[0][v], mem[1][v]);

    mem[0][v] = 0;
    for(int u : adj[v])
        mem[0][v] += maxT(u, mem, adj, t);

    mem[1][v] = t[v];
    for(int u : adj[v])
        mem[1][v] += mem[0][u];

    return max(mem[0][v], mem[1][v]);
}

int main()
{
    int n;
    cin >> n;
    vi t(n);
    vvi adj(n);
    for(int i=0; i<n; i++){
        int p;
        cin >> p >> t[i];
        if(i > 0)
            adj[p].push_back(i);
    }

    vvi mem(2, vi(n, -1));
    cout << maxT(0, mem, adj, t) << '\n';

    return 0;
}