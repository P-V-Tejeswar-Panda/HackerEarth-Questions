#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    int depth;
    int parent;
    int color;
    vector<int> edges;
    node(int value){
        val = value;
        depth = INT_MAX;
        parent = -1;
        color = 0;
    }
    void set(int Sdepth, int Sparent, int Scolor){
        depth = Sdepth;
        parent = Sparent;
        color = Scolor;
    }

};

void BFS(struct node* graph[], int source, int finish){
    graph[source]->color = 1;
    graph[source]->depth = 0;
    graph[source]->parent = -1;
    queue<struct node*> Q;
    Q.push(graph[source]);
    while(!Q.empty()){
        struct node *top = Q.front();
        Q.pop();
        for(auto i : top->edges){
            if(graph[i]->color == 0){
                Q.push(graph[i]);
                graph[i]->set(top->depth+1, top->val, 1);
            }
        }
        top->color = 2;
    }
}

void getPath(struct node *graph[], int finish, int source, stack<int> *path){
    int value = graph[finish]->val;
    path->push(value);
    struct node* curr = graph[finish];
    while(value != source){
        path->push(curr->parent);
        value = curr->parent;
        curr = graph[curr->parent];
    }
}

int main(){
    int N, M, T, C;
    cin >> N >> M >> T >> C;
    
    struct node *graph[N+1];
    for(int i = 0; i <= N; i++){
        graph[i] = new struct node(i);
    }
    for(int i = 0; i < M; i++){
        int x1, x2;
        cin >> x1 >> x2;
        graph[x1]->edges.push_back(x2);
        graph[x2]->edges.push_back(x1);
    }
    int source;
    int finish;
    cin >> source >> finish;
    for(int i = 0; i < N; i++){
        sort(graph[i]->edges.begin(), graph[i]->edges.end());
    }
    BFS(graph, source, finish);

    stack<int> *path = new stack<int>();
    getPath(graph, finish, source, path);
    cout << path->size() << endl;
    while(!path->empty()){
        cout << path->top() << " ";
        path->pop();
    }
    cout << endl;
}