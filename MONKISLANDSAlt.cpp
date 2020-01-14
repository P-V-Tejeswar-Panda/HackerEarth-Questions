#include <bits/stdc++.h>
using namespace std;

struct node{
    int color;
    int parent;
    int depth;
    vector<int>*edges;

    node(){
        color = 0;
        parent = -1;
        depth = 0;
        edges = new vector<int>();
    }
};

void BFS(struct node* Graph[], int N){
    (*(Graph+1))->color = 1;
    queue<struct node*> Q;
    int dep = 1;

    Q.push(*(Graph+1));
    while(!Q.empty()){
        struct node* top = Q.front();
        Q.pop();
        vector<int> *e = top->edges;
        for(auto i : *e){
            struct node* curr = (*(Graph+i));
            if(curr->color == 0){
                curr->color = 1;
                curr->depth = top->depth+1;
                Q.push(curr);
            }
        }
        top->color = 2;
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int N,E;
        cin >> N >> E;
        struct node* Graph[N+1];
        for(int i = 0; i <= N; i++){
            Graph[i] = new node();
        }
        for(int i = 0; i < E; i++ ){
            int x1, x2;
            cin >> x1 >> x2;
            Graph[x1]->edges->push_back(x2);
            Graph[x2]->edges->push_back(x1);
        }

        BFS(Graph, N);

        cout << Graph[N]->depth << endl;
    }
}