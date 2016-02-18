#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main( void ) {
    int T;

    cin >> T;
    while( T-- ) {
        int N;
        string U, S;

        cin >> N >> U >> S;

        vector<string> rings(N);
        for(int i = 0; i < N; i++)
            cin >> rings[i];

        vector<int> pos(N);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < (int)rings[i].size(); j++)
                if(rings[i][j] == U[i])
                    pos[i] = j;
        }

        int offset = 0;
        int index = 0;

        for(int i = 0; i < N; i++)
            if(S[i] != '_')
                index = i;

        for(int i = 0; i < (int)rings[index].size(); i++) {
            int j = (i + pos[index]) % (int)rings[index].size();
            if(rings[index][j] == S[index])
                break;
            offset += 1;
        }

        cout << U << " ";
        for(int i = 0; i < N; i++) {
            int j = (pos[i] + offset) % (int)rings[i].size();
            putchar(rings[i][j]);
        }
        cout << endl;
    }
    return 0;
}
