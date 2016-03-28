#include <cstdio>
#include <iostream>

using namespace std;

int main( void ) {
    long long G, T, A, D;
    while(true) {
        cin >> G >> T >> A >> D;
        if(G == -1 && T == -1 && A == -1 && D == -1)
            break;
            
        long long numGames, numTeams;
        
        numGames = 0;
        numTeams = 0;
        
        numGames += G * T * (T - 1) / 2;
        
        long long knockout = A * G + D;
        long long pw = 1;
        while(pw < knockout)
            pw *= 2;
        numTeams = pw - knockout;
        
        while(pw > 0) {
            numGames += (pw / 2);
            pw /= 2;
        }
            
        cout << G << "*" << A << "/" << T << "+" << D << "=" << numGames << "+" << numTeams << endl;
    }
    return 0;
}
