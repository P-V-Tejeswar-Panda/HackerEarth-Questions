#include <bits/stdc++.h>
#define ll int
#define ll_MAX INT_MAX
using namespace std;

struct node{
    ll val;
    ll color = 0;
    ll parent = -1;
    ll depth = ll_MAX ;
    vector<ll> edges;

    node(ll value){
        val = value;
    }
    void clear(){
        color = 0;
        parent = -1;
        depth = ll_MAX;
    }
};

void clearGraph(struct node *graph[], ll N){
    for(ll i = 0; i < N; i++ ){
        graph[i]->clear();
    }
}

ll BFS(struct node *graph[], ll source, ll radius){
    graph[source]->color = 1;
    graph[source]->depth = 0;

    queue<struct node*> Q;
    Q.push(graph[source]);
    ll dep = 0;
    while(!Q.empty()){
        struct node * top = Q.front();
        if(top->depth == radius) break;
        Q.pop();
        
        for(auto i : top->edges){
            if(graph[i]->color == 0){
                Q.push(graph[i]);
                graph[i]->color = 1;
                graph[i]->depth = top->depth+1;
            }
        }
        top->color = 2;
    }
    return Q.size();
}

int main(){
    ll N, E;
    cin >> N >> E;
    struct node *graph[N];
    for(ll i = 0; i < N; i++){
        graph[i] = new struct node(i);
    }

    for(ll i = 0; i < E; i++){
        ll x1, x2;
        cin >> x1 >> x2;
        graph[x1]->edges.push_back(x2);
        graph[x2]->edges.push_back(x1);
    }

    ll Q;
    cin >> Q;

    for(ll i = 0; i < Q; i++){
        ll x1, x2;
        cin >> x1 >> x2;
        ll ans = BFS(graph, x1, x2);
        clearGraph(graph, N);
        cout << ans << endl;
    }

}