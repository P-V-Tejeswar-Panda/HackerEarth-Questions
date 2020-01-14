#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
    ll val;
    struct node *left;
    struct node *right;

    node(ll value){
        val = value;
        left = right = NULL;
    }
};



struct node* insert( struct node* root, ll value){
    if(root == NULL) return new struct node(value);
    if(value <= root->val){
        root->left = insert(root->left, value);
    }
    else{
        root->right = insert(root->right, value);
    }
    return root;
}

bool find(struct node* root, ll value){
    if(root == NULL) return false;
    if(root->val == value) return true;
    else if(value < root->val) return find(root->left, value);
    else return find(root->right, value);
    return false;
}

int main(){
    ll T;
    cin >> T;
    while(T--){
        ll N, M;
        cin >> N >> M;
        struct node *root = NULL;
        for(ll i = 0; i < N; i++){
            ll temp;
            cin >> temp;
            root = insert(root, temp);
        }
        for(int i = 0; i < M; i++){
            ll temp;
            cin >> temp;
            bool ans = find(root, temp);
            if(ans == true){
                cout << "YES" << endl;
            }
            else {cout << "NO" << endl; root = insert(root, temp);}
        }

    }
}