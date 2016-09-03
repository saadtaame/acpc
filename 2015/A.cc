#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

const int N = 100010;
const int M = 100010;

int t;
int n, m;
int x, y;

int last_[N], to[M+M], prev_[M+M];
int euler[N+N];
int depth[N+N];
int st[N];
int e;
int euler_i;

int tree[8 * N];

void add( int u, int v ) {
    prev_[e] = last_[u];
    last_[u] = e;
    to[e] = v;
    e += 1;
}

void dfs( int x = 0, int p = -1, int d = 0 )  {
    depth[euler_i] = d;
    euler[euler_i++] = x;
    for(int i = last_[x]; i+1; i = prev_[i]) {
        int y = to[i];
        if(y != p) {
            dfs(y, x, d+1);
            depth[euler_i] = d;
            euler[euler_i++] = x;
        }
    }
}

void build( int p = 1, int L = 0, int R = n+n-1 ) {
    if(L == R) tree[p] = L;
    else {
        int M = (L + R) / 2;
        build(p+p, L, M);
        build(p+p+1, M+1, R);
        if(depth[ tree[p+p] ] < depth[ tree[p+p+1] ])
            tree[p] = tree[p+p];
        else
            tree[p] = tree[p+p+1];
    }
}

int get( int i, int j, int p = 1, int L = 0, int R = n+n-1 ) {
    if(j < L || i > R) return (int)1e9;
    if(L >= i && R <= j) return tree[p];
    int M = (L + R) / 2;

    int a, b;
    a = get(i, j, p+p, L, M);
    b = get(i, j, p+p+1, M+1, R);

    if(a == (int)1e9) return b;
    if(b == (int)1e9) return a;

    if(depth[a] < depth[b])
        return a;
    return b;
}

int main( void ) {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &t);
    while( t-- ) {
        scanf("%d", &n);

        e = 0;
        memset(last_, -1, sizeof(last_));
        memset(st, -1, sizeof(st));

        for(int i = 0; i < n-1; i++) {
            scanf("%d %d", &x, &y);
            add(x, y);
            add(y, x);
        }

        euler_i = 0;
        dfs();
        for(int i = 0; i < n+n-1; i++)
            if(st[ euler[i] ] == -1)
                st[ euler[i] ] = i;

        build();
        set<int> S;

        scanf("%d", &m);
        while( m-- ) {
            char ch[2];
            scanf("%1s %d", ch, &x);
            if(ch[0] == '+') S.insert(st[x]);
            else S.erase( S.find(st[x]) );

            if(S.empty()) {
                puts("-1");
                continue;
            }

            int L, R;
            L = *S.begin();
            R = *S.rbegin();
            printf("%d\n", euler[ get(L, R) ]);
        }
    }
    return 0;
}
