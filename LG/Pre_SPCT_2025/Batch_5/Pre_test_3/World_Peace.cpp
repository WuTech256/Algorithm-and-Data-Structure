#include <bits/stdc++.h>
using namespace std;

const long long INFLL = (1LL<<60);

long long dijkstra(int N, const vector<vector<int>> &to, const vector<vector<int>> &ww, const vector<vector<int>> &id, int s, int t, int skipId=-1){
    vector<long long> dist(N+1, INFLL);
    using P=pair<long long,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[s]=0; pq.push({0,s});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d!=dist[u]) continue;
        if(u==t) break;
        for(size_t k=0;k<to[u].size();++k){
            if(id[u][k]==skipId) continue;
            int v=to[u][k]; long long nd=d+ww[u][k];
            if(nd<dist[v]){ dist[v]=nd; pq.push({nd,v}); }
        }
    }
    return dist[t];
}

vector<long long> allDij(int N, const vector<vector<int>> &to, const vector<vector<int>> &ww, const vector<vector<int>> &id, int s){
    vector<long long> dist(N+1, INFLL);
    using P=pair<long long,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[s]=0; pq.push({0,s});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d!=dist[u]) continue;
        for(size_t k=0;k<to[u].size();++k){
            int v=to[u][k]; long long nd=d+ww[u][k];
            if(nd<dist[v]){ dist[v]=nd; pq.push({nd,v}); }
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M; 
    if(!(cin>>N>>M)) return 0;
    vector<int> U(M), V(M), W(M);
    vector<vector<int>> to(N+1), ww(N+1), id(N+1);
    for(int i=0;i<M;++i){
        cin>>U[i]>>V[i]>>W[i];
        to[U[i]].push_back(V[i]); ww[U[i]].push_back(W[i]); id[U[i]].push_back(i);
        to[V[i]].push_back(U[i]); ww[V[i]].push_back(W[i]); id[V[i]].push_back(i);
    }
    auto dist1 = allDij(N,to,ww,id,1);
    if(dist1[N]>=INFLL){ cout<<"INF\n"; return 0; }
    auto distN = allDij(N,to,ww,id,N);
    long long base = dist1[N];
    vector<int> cand;
    for(int i=0;i<M;++i){
        if(dist1[U[i]]+W[i]+distN[V[i]]==base || dist1[V[i]]+W[i]+distN[U[i]]==base)
            cand.push_back(i);
    }
    if(cand.empty()){ cout<<base<<"\n"; return 0; }
    long long best=base; bool canINF=false;
    for(int eid: cand){
        long long d = dijkstra(N,to,ww,id,1,N,eid);
        if(d>=INFLL){ canINF=true; break; }
        best = max(best,d);
    }
    if(canINF) cout<<"INF\n"; else cout<<best<<"\n";
    return 0;
}
