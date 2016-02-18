#include <cstdio>
#include <cctype>
#include <string>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void skip_whitespace(string &s, int &pos) {
    while(isspace(s[pos]))
        pos += 1;
}

int main( void ) {
    string line;
    char  next_char;
    int pos;

    while(true) {
        getline(cin, line);

        pos = 0;
        skip_whitespace(line, pos);
        next_char = line[pos++];

        if(next_char == '$')
            break;

        stack<string> S;
        while(true) {
            if(next_char == '$')
                break;

            if(next_char == ')') {
                skip_whitespace(line, pos);
                next_char = line[pos++];
            }
            else if(next_char == '(') {
                S.push("(");
                skip_whitespace(line, pos);
                next_char = line[pos++];
            }
            else if(isdigit(next_char)) {
                int repeat = 0;
                while(isdigit(next_char)) {
                    repeat = repeat * 10 + (next_char - '0');
                    skip_whitespace(line, pos);
                    next_char = line[pos++];
                }

                vector<string> A;
                while(S.top() != "(") {
                    A.push_back(S.top());
                    S.pop();
                }
                S.pop();

                reverse(A.begin(), A.end());

                string t;
                for(auto e: A)
                    t += e;

                string flat;
                while(repeat--)
                    flat += t;

                S.push(flat);
            }
            else {
                char ss[2];
                ss[0] = next_char;
                ss[1] = '\0';

                S.push(string(ss));
                skip_whitespace(line, pos);
                next_char = line[pos++];
            }
        }
        cout << S.top() << endl;
    }
    return 0;
}
