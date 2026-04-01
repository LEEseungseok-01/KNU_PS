#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void DFS(int node);
void BFS(int node);
vector<vector<int>> A;
vector<bool> visited;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, start;
    cin >> N >> M >> start;
    A.resize(N+1);
    visited.assign(N+1, false);

    for(int i=0; i<M; i++){
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }
// 오름차순 정렬.
    for(int i=1; i<N+1; i++){
        sort(A[i].begin(), A[i].end());
    }

    DFS(start);
    cout << "\n";
    visited.assign(N+1, false);
    BFS(start);
    
    return 0;
}

void DFS(int node){
    cout << node << " ";
    visited[node] = true;
    for(int i : A[node]){
        if(!visited[i]){
            DFS(i);
        }
    }
}

void BFS(int node){
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;

    while(!myqueue.empty())
    {
        int now_node = myqueue.front();
        myqueue.pop();
        cout << now_node << " ";
        for(int i : A[now_node]){
            if(!visited[i]){
                visited[i] = true;
                myqueue.push(i);
            }
        }
    }
    
}