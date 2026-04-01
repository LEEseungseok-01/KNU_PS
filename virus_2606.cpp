//DFS & bfs
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//void DFS(int node);
void BFS(int node);
vector<bool> visited;
vector<vector<int>> A;
static int count = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    A.resize(N+1);
    visited.assign(N+1, false);

    for(int i=0; i<M; i++){
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

//  DFS(1);
    BFS(1);
    cout << count << "\n";
    return 0;
}
/*
void DFS(int node){
    visited[node] = true;
    for(int i : A[node]){
        if(!visited[i]){
            count++;
            DFS(i);
        }
    }
}
    */

void BFS(int node){
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        myqueue.pop();
        for(int i : A[now_node]){
            if(!visited[i]){
                visited[i] = true;
                myqueue.push(i);
                count++;
            }
        }
    }
}