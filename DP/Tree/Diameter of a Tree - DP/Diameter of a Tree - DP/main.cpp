#include <iostream>
using namespace std;

struct Node{
    int data = 20;
    struct Node* left;
    struct Node* right;
}*root;

Node* insert_BST(int x, Node* p)
{
    if(p == NULL){
        p = new Node;
        p->data = x;
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    
    if(x < p->data) {
        p->left = insert_BST(x, p->left);
    } else if(x > p->data) {
        p->right = insert_BST(x, p->right);
    }
    
    return p;
}

void print_inorder(Node* p){
    if(p == NULL){
        return;
    } else {
        print_inorder(p->left);
        cout<<p->data<<"\t";
        print_inorder(p->right);
    }
}

int max(int i, int j){return i>j?i:j;}
int calls = 0;
int diameter(Node* p, int &res){
    
    calls++;
    if(p == NULL)
        return 0;
    
    int l = diameter(p->left, res);
    int r = diameter(p->right, res);
    
    int temp = 1 + max(l,r);
    int ans = max(temp, 1+l+r);
    res = max(res, ans);
    
    return temp;
}

int main(int argc, const char * argv[]) {
    
    int res = INT_MIN;
    
    root = new Node;
    root->data = 10;
    root->left = NULL;
    root->right = NULL;
    
    insert_BST(5, root);
    insert_BST(20, root);
    insert_BST(40, root);
    insert_BST(2, root);
    insert_BST(7, root);
    insert_BST(12, root);
    insert_BST(1, root);
    insert_BST(9, root);
    insert_BST(50, root);
    insert_BST(33, root);
    
    cout<<"Inorder : ";
    print_inorder(root);
    cout<<endl;
    
    diameter(root, res);
    
    cout<<"Diameter of Tree : "<<res<<endl;
    cout<<"Calls : "<<calls<<endl;
    
    return 0;
}
