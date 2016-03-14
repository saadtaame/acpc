#include <cstdio>
#include <cassert>
#include <string>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

int main( void ) {
    int t = 1;
    string exp;
    
    while(cin >> exp) {
        if("()" == exp)
            break;
            
        cout << t << ". ";
        t += 1;
        
        /* Find max depth */
        int maxDepth = 0;
        stack<char> S;
        for(int i = 0; i < (int)exp.size(); i++) {
        	char c = exp[i];
        	
            if(c == ')') {
                maxDepth = max(maxDepth, (int)S.size());
                S.pop();
            }
            else if(c == '(')
                S.push('(');
        }
        maxDepth %= 2;
        
        /* Eval */
        assert(S.empty());
        
        int open = 0;
        
        for(int i = 0; i < (int)exp.size(); i++) {
        	char c = exp[i];
            if(c == ')') {
                int depth = open % 2;
                int value;
                if(depth == maxDepth) {
                    value = 1;
                    while(S.top() != '(') {
                        value &= ((S.top() == 'T') ? 1 : 0);
                        S.pop();
                    }
                }
                else {
                    value = 0;
                    while(S.top() != '(') {
                        value |= ((S.top() == 'T') ? 1 : 0);
                        S.pop();
                    }
                }
                S.pop();
                S.push(value ? 'T' : 'F');
                open -= 1;
            }
            else {
				S.push(c);
				if(c == '(')
					open += 1;
            }
        }
        
        cout << ((S.top() == 'T') ? "true" : "false") << endl;
    }
    return 0;
}
