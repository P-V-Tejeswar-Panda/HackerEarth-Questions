#include <bits/stdc++.h>
#define ll long long
using namespace std;

void buildTree(ll* input, ll *tree, ll start, ll end, ll index){
    if(start == end){
        tree[index] = input[start];
        return;
    }
    ll mid = (start+end)/2;
    buildTree(input, tree, start, mid, 2*index);
    buildTree(input, tree, mid+1, end, 2*index+1);

    tree[index] = (tree[2*index] > tree[2*index+1]) ? tree[2*index+1] : tree[2*index];
}

void update(ll *tree, ll start, ll end, ll val, ll index, ll node ){
    if(start == end){
        tree[node] = val;
        return;
    }
    ll mid = (start+end)/2;
    if(index <= mid)
        update(tree, start, mid, val, index, 2*node);
    else
        update(tree, mid+1, end, val, index, 2*node + 1);

    tree[node] = (tree[2*index] > tree[2*index+1]) ? tree[2*index+1] : tree[2*index];
}

ll query(ll *tree, ll start, ll end, ll begin, ll finish, ll index ){
    if(start >= begin && end <= finish) return tree[index];
    if(end < begin || start > finish) return LONG_MAX;

    ll mid = (start+end)/2;
    ll p1 = query(tree, start, mid, begin, finish, 2*index);
    ll p2 = query(tree, mid+1, end, begin, finish, 2*index+1);

    return (p1<p2)?p1:p2;

}

int main(){
    ll N, Q;
    cin >> N >> Q;
    ll *input = new ll[N+1];
    ll *tree = new ll[2*N];
    for(int i = 1; i <= N; i++){
        cin >> input[i];
    }
    getchar();
    buildTree(input, tree, 1, N, 1);
    /*for(int i = 0; i < 2*N; i++){
        cout << tree[i] << " ";
    }
    cout << endl;*/

    for(int i = 0; i < Q; i++){
        char ch;
        ch = getchar();
        
        ll x1, x2, x3;
        cin >> x2 >> x3;
        getchar();
        if(ch == 'q'){
            cout << query(tree, 1, N, x2, x3, 1) << endl;
        }
        else{
            update(tree, 1, N, x3, x2, 1);
            
        }
    }
}