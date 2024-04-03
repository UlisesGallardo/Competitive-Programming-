#include <bits/stdc++.h>
using namespace std;

int n,k;
map<int,stack<int>>m;
const int N = 1e5+10;
vector<vector<int>>adj(N);
bool visited[N];

struct Nodo{
    int u, d;
    Nodo(int u_, int d_){
        u = u_;
        d = d_;
    }
};

int bfs(int init){
    queue<Nodo>q;
    q.push(Nodo(init,0));
    visited[init] = true;
    int total = 0;
    while(!q.empty()){
        Nodo v = q.front();
        int dis = v.d +1;
        q.pop();
        int edges = 1;
        if(total == 0)edges = 0;
        if(m.find(dis) == m.end()) continue;
        while(edges + 1 <= k && !m[dis].empty()){
            total++;
            int next = m[dis].top();
            q.push(Nodo(next,dis));
            m[dis].pop();
            visited[next] = true;
            adj[v.u].push_back(next);
            edges++;
        }
    }
    return total;
}

int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        int d; cin>>d;
        m[d].push(i);
    }

    if(m.find(0) == m.end() || m[0].size() > 1){
        cout<<-1;
        return 0;
    }
    int total = bfs(m[0].top());
    bool entrar = true;
    for(int i=1; i<=n; i++)entrar &= visited[i];
    if(!entrar){
        cout<<-1;
        return 0;
    }
    cout<<total<<"\n";
    for(int u=1; u<=n; u++){
        for(auto v: adj[u]){
            cout<<u<<" "<<v<<"\n";
        }
    }
    return 0;
}
