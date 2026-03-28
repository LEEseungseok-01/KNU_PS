//1546번 문제
#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    cin >> N;
    int grade[1000];

    for(int i=0; i<N; i++){
        cin >> grade[i];
    }

    int sum = 0;
    int max = 0;

    for(int i=0; i<N; i++){
        if(grade[i] > max){
            max = grade[i];
        }
        sum = sum + grade[i]; //결합법칙으로 나중에 적용해도 됌.
    }

    float result = sum * 100.0 / max / N;
    cout << result << "\n";

    return 0;
}