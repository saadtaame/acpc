#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int L;
unsigned int allowed_mask;
long long valid_cnt;
unsigned int between[12][12];

unsigned int init_inbetween( void ) {
    between[0][0] = 0;
    between[0][1] = 0;
    between[0][2] = (1 << 1);
    between[0][3] = 0;
    between[0][4] = 0;
    between[0][5] = 0;
    between[0][6] = (1 << 3);
    between[0][7] = 0;
    between[0][8] = (1 << 4);
    between[0][9] = (1 << 3) | (1 << 6);
    between[0][10] = 0;
    between[0][11] = 0;

    between[1][1] = 0;
    between[1][2] = 0;
    between[1][3] = 0;
    between[1][4] = 0;
    between[1][5] = 0;
    between[1][6] = 0;
    between[1][7] = (1 << 4);
    between[1][8] = 0;
    between[1][9] = 0;
    between[1][10] = (1 << 4) | (1 << 7);
    between[1][11] = 0;

    between[2][2] = 0;
    between[2][3] = 0;
    between[2][4] = 0;
    between[2][5] = 0;
    between[2][6] = (1 << 4);
    between[2][7] = 0;
    between[2][8] = (1 << 5);
    between[2][9] = 0;
    between[2][10] = 0;
    between[2][11] = (1 << 5) | (1 << 8);

    between[3][3] = 0;
    between[3][4] = 0;
    between[3][5] = (1 << 4);
    between[3][6] = 0;
    between[3][7] = 0;
    between[3][8] = 0;
    between[3][9] = (1 << 6);
    between[3][10] = 0;
    between[3][11] = (1 << 7);

    between[4][4] = 0;
    between[4][5] = 0;
    between[4][6] = 0;
    between[4][7] = 0;
    between[4][8] = 0;
    between[4][9] = 0;
    between[4][10] = (1 << 7);
    between[4][11] = 0;

    between[5][5] = 0;
    between[5][6] = 0;
    between[5][7] = 0;
    between[5][8] = 0;
    between[5][9] = (1 << 7);
    between[5][10] = 0;
    between[5][11] = (1 << 8);

    between[6][6] = 0;
    between[6][7] = 0;
    between[6][8] = (1 << 7);
    between[6][9] = 0;
    between[6][10] = 0;
    between[6][11] = 0;

    between[7][7] = 0;
    between[7][8] = 0;
    between[7][9] = 0;
    between[7][10] = 0;
    between[7][11] = 0;

    between[8][8] = 0;
    between[8][9] = 0;
    between[8][10] = 0;
    between[8][11] = 0;

    between[9][9] = 0;
    between[9][10] = 0;
    between[9][11] = (1 << 10);

    between[10][10] = 0;
    between[10][11] = 0;

    between[11][11] = 0;
}

long long dp[1 << 12][12][61];
long long backtrack( unsigned int in_pattern, int tail, int len ) {
    if(len > L)
        return 0;

    if(len == L)
        return 1;

    if(tail != -1 && dp[in_pattern][tail][len] != -1)
        return dp[in_pattern][tail][len];

    long long ans = 0;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            int point = i * 3 + j;
            if((allowed_mask & (1 << point)) == 0) continue; /* point not allowed */
            if(in_pattern & (1 << point)) continue; /* point already in pattern */

            if(tail == -1)
                ans += backtrack(in_pattern | (1 << point), point, len);
            else {
                unsigned int points_inbetween = between[min(tail, point)][max(tail, point)];
                if((points_inbetween & (in_pattern & ~(1 << tail))) == points_inbetween) {
                    int dist = abs(i - (tail / 3)) + abs(j - (tail % 3));
                    ans += backtrack(in_pattern | (1 << point), point, len + dist);
                }
            }
        }
    }

    if(tail != -1)
        dp[in_pattern][tail][len] = ans;

    return ans;
}

int main( void ) {
    init_inbetween();

    int T;
    cin >> T;

    while( T-- ) {
        int n;
        cin >> L >> n;

        allowed_mask = (1 << 12) - 1;

        for(int i = 0; i < n; i++) {
            int x, y;
            int bit;

            cin >> x >> y;
            x--, y--;
            bit = y * 3 + x;
            allowed_mask = allowed_mask & ~(1 << bit);
        }

        memset(dp, -1, sizeof(dp));
        valid_cnt = backtrack(0, -1, 0);

        if(valid_cnt > 0) cout << valid_cnt;
        else cout << "BAD MEMORY";

        cout << endl;
    }

    return 0;
}
