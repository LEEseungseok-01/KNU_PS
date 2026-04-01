#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//compare 잘 기억하자.
bool compare(string a, string b){
    if (a.length() == b.length()){
        return a<b; //사전순
    }
    return a.length()<b.length();
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<string> v(N);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end(), compare);
    cout << v[0] << "\n";
    for(int i=1; i<N; i++){
        if(v[i] == v[i-1]){
            continue;
        }
        cout << v[i] << "\n";
    }
    return 0;
}