#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

long long gcd( long long x, long long y) {
    if(y == 0)
        return x;

    return gcd(y, x % y);
}

int main( void ) {

    int t;
    int tt = 1;

    cin >> t;
    while(t--) {

        cout << "Case " << tt++ << ": ";

        long long x, y, n, m;
        long long A, B;

        cin >> x >> n >> y >> m;
        A = 0, B = x;

        while(n--) {
            long long tmp = A;
            A = B;
            B += tmp;

            if(A > B) swap(A, B);
        }

        B += y;
        cout << gcd(A, B) << endl;
    }

    return 0;
}
