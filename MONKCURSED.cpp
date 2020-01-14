#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
    ll val;
    struct node* left;
    struct node* right;

    node(ll value){
        val = value;
        left = right = NULL;
    }
};

struct node* insert(struct node* root, ll value){
    if(root == NULL) return new struct node(value);
    if(value <= root->val){
        root->left = insert(root->left, value);
    }
    else root->right = insert(root->right, value);

    return root;
}

ll findOneMax(struct node* root, ll r){
    if(r <= root->val ) return root->val;
    return findOneMax(root->right, r);
}

ll findMax(struct node* root, ll l, ll r){
    if(r == root->val) return r;
    if(r < root->val){
        return findMax(root->left, l, r);
    }
    if(l > root->val){
        return findMax(root->right, l, r);
    }

    return findOneMax(root->right, r);
}

int main(){
    ll N;
    cin >> N;

    struct node* root = NULL;

    for(ll n = 0; n < N; n++){
        ll temp;
        cin >> temp;
        root = insert(root, temp);
    }

    ll l, r;
    cin >> l >> r;
    if(l <= r){
        cout << findMax(root, l, r) << endl;
    }
    else cout << findMax(root, r, l) << endl;


}