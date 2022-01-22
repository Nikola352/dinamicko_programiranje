#include <bits/stdc++.h>
using namespace std;

struct Ship{
    int r, d, idx;
};

int main()
{
    ifstream in("brodovi.dat");
    ofstream out("brodovi.res");

    int n;
    while(in >> n){
        vector<Ship> ships(n);
        for(int i=0; i<n; i++){
            in >> ships[i].r >> ships[i].d;
            ships[i].idx = i;
        }

        int m, v;
        in >> m >> v;
        vector<int> mass(m), profit(m);
        for(int i=0; i<m; i++)
            in >> mass[i] >> profit[i];

        vector<int> dp1(v+1, 0), opt(v+1, -1);
        for(int i=1; i<=v; i++){
            for(int j=0; j<m; j++){
                if(i >= mass[j]){
                    int pot = dp1[i-mass[j]] + profit[j];
                    if(pot > dp1[i]){
                        dp1[i] = pot;
                        opt[i] = j;
                    }
                }
            }
        }

        int mp = 0, s = 0;
        for(int i=0; i<=v; i++){
            if(dp1[i] > mp){
                mp = dp1[i];
                s = i;
            }
        }

        vector<int> numTaken(m, 0);
        while(opt[s] != -1){
            numTaken[opt[s]]++;
            s -= mass[opt[s]];
        }


        vector<int> cost(n);
        for(int i=0; i<n; i++){
            cost[i] = ships[i].r;
            ships[i].r = mp - ships[i].r;
        }

        sort(ships.begin(), ships.end(), [](const Ship& a, const Ship& b){ return a.d < b.d; });

        vector<vector<int>> dp(n+1, vector<int>(n, 0));
        vector<vector<bool>> used(n+1, vector<bool>(n, false));
        for(int i=1; i<=n; i++){
            for(int j=0; j<n; j++){
                if(j > 0)
                    dp[i][j] = dp[i][j-1];
                if(i <= ships[j].d){
                    int pot = dp[i-1][j-1] + ships[j].r;
                    if(pot > dp[i][j]){
                        dp[i][j] = pot;
                        used[i][j] = true;
                    }
                }
            }
        }

        int res = 0, revenue = 0, si = 0;
        for(int i=0; i<=n; i++){
            if(dp[i][n-1] > res){
                res = dp[i][n-1];
                revenue = i * mp;
                si = i;
            }
        }

        vector<bool> shipTaken(n, false);
        for(int sj=n-1; sj>=0; sj--){
            if(used[si][sj]){
                shipTaken[ships[sj].idx] = true;
                si--;
            }
        }

        out << "Prihod: " << revenue << '\n';
        out << "Rashod: " << revenue - res << '\n';
        out << "Profit: " << res << '\n';

        out << "Kolicina robe u brodu:\n";
        for(int i=0; i<m; i++)
            out << i+1 << ' ' << numTaken[i] << '\n';

        out << "Iznajmljeni brodovi:\n";
        for(int i=0; i<n; i++)
            if(shipTaken[i]) 
                out << i+1 << " Zakupnina: " << cost[i] << '\n';

        out << '\n';
    }

    return 0;
}