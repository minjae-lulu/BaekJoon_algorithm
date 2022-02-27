#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// mst 알고리즘은 프림 알고리즘으로 구현
vector<pair<int, int> > adj[10005];
bool chk[10005];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int v,e; cin >> v >> e;
    for(int i=0; i<e; i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({make_pair(c,b)}); // cont 기준으로 우선순위큐
        adj[b].push_back(make_pair(c,a));
    }
    
    priority_queue< tuple<int,int,int>, vector<tuple<int,int,int> >, greater<tuple<int,int,int> > > pq; // 비용,정점1,정점2
    chk[1]=1;
    for(auto nxt : adj[1])  pq.push({nxt.first, 1, nxt.second}); // 일단 pq에 1번간선과 연결된 모든 정보(비용,정점1,정점2) 추가
    int cnt=0,ans=0;

    while(cnt<v-1){ // vertex 가 n-1인경우 알고리즘 종료
        int cost,a1,b1;
        tie(cost,a1,b1) = pq.top(); pq.pop();
        if(chk[b1])  continue; // 이미 연결돼있으면 pass, 아니면 추가 
        ans += cost; // 연결아니니 추가해주고,
        chk[b1]=1; // b1은 연결돼었다고 바꿔줌
        cnt++;
        for(auto nxt : adj[b1]){ // b1과 연결된 간선 탐색
            if(!chk[nxt.second]) // 그다음것이, 색칠안되어 있다면
                pq.push({nxt.first,b1,nxt.second}); // pq에 추가
        }
    }
    cout << ans;

}