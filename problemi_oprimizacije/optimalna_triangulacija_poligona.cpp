#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

int f(Point p1, Point p2, Point p3){
    return (int) (
        sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y)) +
        sqrt((p1.x-p3.x)*(p1.x-p3.x) + (p1.y-p3.y)*(p1.y-p3.y)) +
        sqrt((p3.x-p2.x)*(p3.x-p2.x) + (p3.y-p2.y)*(p3.y-p2.y))
    );
}

int main()
{
    int n;
    cin >> n;
    Point p[n];
    for(int i=0; i<n; i++)
        cin >> p[i].x >> p[i].y;

    int dp[n][n];
    for(int i=0; i<n; i++){
        for(int j=i; j<i+2 && j<n; j++)
            dp[i][j] = 0;
    }

    for(int l=3; l<=n; l++){
        for(int i=0; i<n-l+1; i++){
            int j = i + l - 1;
            dp[i][j] = INT_MIN;
            for(int k=i+1; k<j; k++){
                int pot = dp[i][k] + dp[k][j] + f(p[i], p[k], p[j]);
                if(pot > dp[i][j])
                    dp[i][j] = pot;
            }
        }
    }

    cout << dp[0][n-1] << '\n';

    return 0;
}