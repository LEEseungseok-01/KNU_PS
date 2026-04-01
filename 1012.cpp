//배추 찾기 BFS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void BFS(int y, int x);
int N, M, K;
int map[51][51];
bool visited[51][51];
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //테스트 케이스 수
    int T;
    cin >> T;

    while(T--){
        cin >> M >> N >> K;

        //매 케이스마다 초기화.
        for(int i=0; i<51; i++){
            for(int j=0; j<51; j++){
                map[i][j] = 0;
                visited[i][j] = false;
            }
        }
        for(int i =0; i<K; i++){
            int s, e;
            cin >> s >> e;
            map[e][s] = 1; //배열의 row, col 를 보면 y, x 순임.
        }
        int count =0;
        for(int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                if (map[i][j] ==1 && !visited[i][j]){
                    BFS(i ,j);
                    count++;
                }
            }
        }
        cout << count << "\n";
    }
    return 0;
}

void BFS(int y, int x){
    queue<pair<int, int>> myqueue;
    myqueue.push({y, x});
    visited[y][x] = true;

    while(!myqueue.empty()){
        int now_y = myqueue.front().first;
        int now_x = myqueue.front().second;
        myqueue.pop();

        for (int i=0; i<4; i++){
            int ny = now_y + dy[i];
            int nx = now_x + dx[i];

            //지도 범위 체크 (map 안에 있는지.)
            if(ny >= 0 && ny < N && nx >=0 && nx < M){
                //배추 있고 방문 X 라면
                if(map[ny][nx] == 1 && !visited[ny][nx]){
                    visited[ny][nx] = true;
                    myqueue.push({ny, nx});
                }
            }
        }
    }
}