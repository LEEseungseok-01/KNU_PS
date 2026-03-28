//10986 - 나머지 합 구하기 -
#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    long long C[1001] = {0};
    long long sum = 0;
    long long answer = 0;

    for(int i =0; i<N; i++){
        int temp;
        cin >> temp;
        sum += temp;

        int remainder = sum% M;
        if(remainder == 0) answer++;

        C[remainder]++;
    }

    //나머지 같은것중 2개 뽑기
    for(int i=0; i<M; i++){
        if(1<C[i]){
            answer = answer + ((C[i]*(C[i]-1))/2);
        }
    }
    cout << answer << "\n";

    return 0;
}