//1940 - 주몽의 명령 - O(Nlogn)
//M은 데이터의 갯수가 아니기 떄문에 시간복잡도 상관 없음

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 벡터쓰면은 sort할떄 sort(arr, arr+N) 배열 이름자체가 첫번째 주소 end주소는 N 더한것.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> A(N, 0); //실수 방지

    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int count = 0;
    int i = 0;
    int j = N-1;

    while (i<j){ // i==j 하면은 M이랑 같은경우에 조건확인 하기 전 엇갈릴수도 있음.
        //같은경우
        if(A[i]+A[j] == M){
            count++;
            i++;
            j--;
        }else if(A[i]+A[j] < M){
            i++;
        }else{
            j--;
        }
    }
    
    cout << count << "\n";
    return 0;
}