#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int MOD = (int)1e9 + 7;
int t, n;
string s;

int getCount(int i, int j) {
    int cnt = j - i + 2;
    if(i == 0 || j == n - 1)
        cnt = 1;
    return cnt;
}

int main( void ) {
    cin >> t;
    while(t--) {
        cin >> s;
        n = (int)s.size();

        vector<bool> in(26, false);
        vector<int> L(26), R(26);

        for(int i = 0; i < n; i++) {
            if(s[i] == '?') continue;

            if(in[ s[i] - 'a' ] == false) {
                L[ s[i] - 'a' ] = i;
                in[ s[i] - 'a' ] = true;
            }
            R[ s[i] - 'a' ] = i;
        }

        vector< pair<int, int> > intervals;
        for(int i = 0; i < 26; i++)
            if(in[i])
                intervals.push_back({L[i], R[i]});
        sort(intervals.begin(), intervals.end());

        bool flag = false;
        for(int i = 1; !flag && (i < (int)intervals.size()); i++) {
            if(intervals[i].first <= intervals[i - 1].second)
                flag = true;
        }

        if(flag == false) {
            int countUnique = 0;
            for(int i = 0; i < 26; i++)
                countUnique += (in[i] ? 1 : 0);

            for(int i = 0; i < 26; i++) {
                if(in[i]) {
                    for(int j = L[i]; j <= R[i]; j++)
                        s[j] = i + 'a';
                }
            }

            int answer = 1;
            int countMarks = 0;
            int leftMark = -1, rightMark = -1;

            for(int i = 0; i < n; i++) {
                if(s[i] != '?') {
                    if(countMarks > 0)
                        answer = (answer * 1ll * getCount(leftMark, rightMark)) % MOD;
                    countMarks = 0;
                    leftMark = rightMark = -1;
                }
                else {
                    if(leftMark == -1)
                        leftMark = i;
                    rightMark = i;
                    countMarks += 1;
                }
            }

            cout << answer << endl;
        }
        else cout << 0 << endl;
    }
    return 0;
}
