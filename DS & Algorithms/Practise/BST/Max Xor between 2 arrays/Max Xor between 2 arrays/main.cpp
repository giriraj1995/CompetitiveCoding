//
//  main.cpp
//  Max Xor between 2 arrays
//
//  Created by Giriraj Saigal on 13/01/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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

struct Node {
    Node* left;
    Node* right;
};

Node* create(int ele, Node* head) {
    
    Node* temp = head;
    
    for(int i = 31; i >= 0; i--) {
        int k = ele>>i;
        if((k & 1) == 0) {
            
            if(temp->left == NULL) {
                temp->left = new Node();
            }
            
            temp = temp->left;

        }else if((k & 1) == 1){
            
            if(temp->right == NULL) {
                temp->right = new Node();
            }
            
            temp = temp->right;
        }
    }
    
    
    return head;
}

int findMaxXor(Node* head, vector<int> arr) {
    
    int maxXor = INT_MIN;
    
    for(int i = 0; i < arr.size(); i++) {
        int ele = arr[i];
        Node* temp = head;
        int curXor = 0;

        for(int i = 31; i >= 0; i--) {
            int k = ele>>i;
            if((k & 1) == 0) {
                if(temp->right) {
                    temp = temp->right;
                    curXor += pow(2, i);
                }else{
                    temp = temp->left;
                }
            }else if((k & 1) == 1){
                if(temp->left) {
                    temp = temp->left;
                    curXor += pow(2, i);
                }else{
                    temp = temp->right;
                }
            }
        }
        
        maxXor = max(maxXor, curXor);
    }
    
    return maxXor;
}

int solve(vector<int> A, vector<int> B) {
    int n = A.size();
    int m = B.size();
    Node* head = new Node();
    if(n > m) {
        for(int i : A)
            head = create(i, head);
        
        return findMaxXor(head, B);
    }else{
        for(int i : B)
            head = create(i, head);
        
        return findMaxXor(head, A);
    }
}

int main(int argc, const char * argv[]) {
    cout<<solve({6335, 26501, 19170, 15725, 11479, 29359, 26963, 24465, 5706, 28146, 23282, 16828, 9962, 492, 2996, 11943, 4828, 5437, 32392, 14605, 3903, 154, 293, 12383, 17422, 18717, 19719, 19896, 5448, 21727, 14772, 11539, 1870, 19913, 25668, 26300, 17036, 9895, 28704, 23812, 31323, 30334, 17674, 4665, 15142, 7712 }, {28254, 6869, 25548, 27645, 32663, 32758, 20038, 12860, 8724, 9742, 27530, 779, 12317, 3036, 22191, 1843, 289, 30107, 9041, 8943, 19265, 22649});
    return 0;
}
