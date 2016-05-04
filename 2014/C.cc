#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 60;
const int S = 5100;
int n;

long long f[S];

int main( void ) {

    int n, s;
    int t;
    int tt = 1;

    cin >> t;

    while(t--) {

        cout << "Case " << tt++ << ": ";

        cin >> s >> n;
        vector<int> v(n), c(n);

        int mx_c = 0;

        for(int i = 0; i < n; i++) {
            cin >> v[i] >> c[i];
            mx_c = max(c[i], mx_c);
        }

        long long ans = 0;

        for(int k = 1; k <= mx_c; k++) {

            if(s % k != 0)
                continue;

            memset(f, 0, sizeof(f));
            f[0] = 1;

            for(int i = 0; i < n; i++)
                for(int j = s; j >= 0; j--)
                    if(k <= c[i] && j >= k * v[i])
                        f[j] += f[j - k * v[i]];

            ans += f[s];
        }

        cout << ans << endl;
    }

    return 0;
}
