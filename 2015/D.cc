#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long gcd( long long x, long long y ) {
    if(y == 0) return x;
    return gcd(y, x % y);
}

long long lcm( long long x, long long y ) {
    return (x * y) / gcd(x, y);
}

struct Frac {
    long long x, y;
    Frac( long long x_, long long y_ ) {
        x = x_, y = y_;
    }

    void print( void ) {
        long long g = gcd(x, y);
        cout << x/g << "/" << y/g;
    }
};

int main() {
    int t;
    cin >> t;
    while( t-- ) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        long long g, l;

        g = gcd(a, b);
        a /= g, b /= g;

        g = gcd(c, d);
        c /= g, d /= g;

        l = lcm(b, d);
        g = gcd(a, c);
        Frac f1(g, l);

        g = gcd(b, d);
        l = lcm(a, c);

        f1.print(); cout << " ";
        Frac f2(l, g);
        f2.print(); cout << endl;
    }
    return 0;
}
