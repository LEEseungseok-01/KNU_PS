//2018 - 연속된 자연수의 합 구하기. - O(N)
#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int start_index = 1;
    int end_index = 1;
    int sum = 1;
    int count = 1;
    int N;
    cin >> N;

    while(end_index != N){
        if(sum == N){
            count++;
            end_index++;
            sum += end_index;
        }else if(N < sum){ // 초과
            sum -= start_index;
            start_index++;
        }else{ // 부족
            end_index++;
            sum += end_index;
        }
    }
    cout << count << "\n";

    return 0;
}