#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
    char label;
    TreeNode *left, *right;
    bool doneLeft, doneRight;

    TreeNode(char label_): label(label_), left(NULL), right(NULL),
        doneLeft(false), doneRight(false) {}
};

TreeNode *mk_tree(vector<char> &post) {
    int n = (int)post.size();

    if(n == 0)
        return NULL;

    if(post.back() == '#')
        return NULL;

    TreeNode *root;
    TreeNode *node;

    root = node = new TreeNode(post.back());
    post.pop_back();

    stack<TreeNode *> S;
    S.push(node);

    while(!S.empty()) {
        TreeNode *cur = S.top();

        if(cur->doneLeft && cur->doneRight) {
            S.pop();
            continue;
        }

        if(post.back() != '#') {
            node = new TreeNode(post.back());
            post.pop_back();

            if(!cur->doneRight) {
                cur->right = node;
                S.push(node);
                cur->doneRight = true;
            }
            else {
                cur->left = node;
                S.push(node);
                cur->doneLeft = true;
            }
        }
        else {
            post.pop_back();
            if(!cur->doneRight)
                cur->doneRight = true;
            else if(!cur->doneLeft)
                cur->doneLeft = true;
        }
    }

    return root;
}

TreeNode *mk_tree(string &s) {
    vector<char> tree;
    string curNode;

    int n = (int)s.size();

    for(int i = 0; i < n; i++) {
        if(s[i] == ' ') {
            if(curNode != "") {
                if(curNode == "nil")
                    tree.push_back('#');
                else
                    tree.push_back(curNode[0]);
            }
            curNode = "";
        }
        else {
            curNode.push_back(s[i]);
        }
    }

    if(curNode != "end")
        cout << "Parsing error" << endl;

    return mk_tree(tree);
}

bool equivalent(TreeNode *s, TreeNode *t) {
    if(s == NULL)
        return (t == NULL);

    if(t == NULL)
        return (s == NULL);

    if(s->label != t->label)
        return false;

    if(equivalent(s->left, t->left) && equivalent(s->right, t->right))
        return true;

    if(equivalent(s->left, t->right) && equivalent(s->right, t->left))
        return true;

    return false;
}

int main( void ) {
    int T;
    cin >> T;

    string tmpLine;
    getline(cin, tmpLine);

    while( T-- ) {
        string s, t;

        getline(cin, s);
        getline(cin, t);

        TreeNode *treeS, *treeT;

        treeS = mk_tree(s);
        treeT = mk_tree(t);

        if(equivalent(treeS, treeT))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}

