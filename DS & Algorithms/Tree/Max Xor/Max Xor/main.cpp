//
//  main.cpp
//  Max Xor
//
//  Created by Giriraj Saigal on 06/06/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

struct Node{
    Node* left;
    Node* right;
};

Node* createNode(){
    Node* t = new Node;
    t->left = NULL;
    t->right = NULL;
    return t;
}

Node* createTree(Node* root, vector<int> &x) {
    Node* p = root;
    
    for(int i = 0; i < x.size(); i++) {
        int ele = x[i];
        p = root;
        
        for(int j = 31; j >= 0; j--) {
            if(1<<j & ele) {
                if(p->right == NULL)
                    p->right = createNode();
                p = p->right;
            }else{
                if(p->left == NULL)
                    p->left = createNode();
                p = p->left;
            }
        }
    }
    
    return root;
}
int findmax(int ele, Node* root) {
    Node* p = root;
    int ans = 0;
    
    for(int j = 31; j >= 0; j--) {
        if(1<<j & ele) {
            if(p->left){
                p = p->left;
                ans += pow(2,j);
            }else
                p = p->right;
        }else{
            if(p->right){
                p = p->right;
                ans += pow(2,j);
            }else
                p = p->left;
        }
    }
    return ans;
}

int solve(vector<int> A, vector<int> B) {
    
    if(A.size() > B.size()) {
        vector<int> C = A;
        A = B;
        B = C;
    }
    
    Node* root = createNode();
    root = createTree(root,A);
    int ans = 0;
    
    for(int i : B) {
        ans = max(ans, findmax(i,root));
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    cout<<solve({6335, 26501, 19170, 15725, 11479, 29359, 26963, 24465, 5706, 28146, 23282, 16828, 9962, 492, 2996, 11943, 4828, 5437, 32392, 14605, 3903, 154, 293, 12383, 17422, 18717, 19719, 19896, 5448, 21727, 14772, 11539, 1870, 19913, 25668, 26300, 17036, 9895, 28704, 23812, 31323, 30334, 17674, 4665, 15142, 7712},{28254, 6869, 25548, 27645, 32663, 32758, 20038, 12860, 8724, 9742, 27530, 779, 12317, 3036, 22191, 1843, 289, 30107, 9041, 8943, 19265, 22649})<<endl;
    return 0;
}
