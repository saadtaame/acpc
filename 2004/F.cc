#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

const int N = 130;

long long dp[N][N];

int main( void ) {
    int n;
    while( (cin >> n) ) {
        if(n < 0) break;

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= i; j++) {
                for(int k = 0; k <= j; k++)
                    dp[i][j] += dp[i-j][k];
            }
        }

        long long num_ways = 0;
        for(int i = 0; i <= n; i++)
            num_ways += dp[n][i];

        cout << n << " => " << num_ways << endl;
    }
    return 0;
}
