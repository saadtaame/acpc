#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int n;

int e;
int last_[N], to[N], prev_[N];

void add( int x, int y ) {
    prev_[e] = last_[x];
    last_[x] = e;
    to[e] = y;
    e++;
}

int h[N];
int ans;
void dfs( int x, int p ) {
    h[x] = 0;
    vector<int> A;
    for(int i = last_[x]; i+1; i = prev_[i]) {
        int y = to[i];
        if(y != p) {
            dfs(y, x);
            A.push_back(h[y]);
        }
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    if((int)A.size()) {
        h[x] = 1 + A[0];
        ans = max(ans, h[x]);
    }
    if((int)A.size() > 1)
        ans = max(ans, 2 + A[0] + A[1]);
}

int diam( void ) {
    ans = -100000000;
    dfs(1, -1);
    return ans;
}

int main() {
    int t;
    cin >> t;
    while( t-- ) {
        cin >> n;

        e = 0;
        memset(last_, -1, sizeof(last_));

        for(int i = 0; i < n-1; i++) {
            int x, y;
            cin >> x >> y;
            add(x, y), add(y, x);
        }

        ans = n-1-diam();
        cout << max(ans, 0) << endl;
    }
    return 0;
}
