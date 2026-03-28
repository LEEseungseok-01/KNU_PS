//구간합 구하기 1 - 11659
#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int M;
    int sumA[100001];
    //전역변수로 선언시 모든값을 0으로 채워줌.
    sumA[0] = 0;

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        int temp;
        cin >> temp;
        sumA[i] = sumA[i-1]+temp;
    }

    for(int i=0; i<M; i++){
        int start, end;
        cin >> start >> end;
        cout << sumA[end]-sumA[start-1] << "\n";
    }
    
    return 0;
}