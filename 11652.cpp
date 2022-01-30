#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n,t; cin >> n;
    vector<int> V;
    while(n--){
        cin >> t;
        V.push_back(t);
    }
    sort(V.begin(), V.end());
    int c=0, mc=0, val;
    bool check = false;
    for(int i=0; i< V.size()-1; i++){
        if(V[i] == V[i+1]){
            c++;
            if(mc < c){
                mc = c;
                val = i;
                check = true;
            }
        }
        if(V[i] != V[i+1])  c=0;
    }
    if(check == false){
        cout << V[0] << '\n'; 
    }
    else{
        cout << val << '\n';
    }

    return 0;
}