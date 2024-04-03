#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
vector<set<int>>adj(N);
bool visited[N];

void bfs(vector<int>seq){
    queue<int>q;
    q.push(seq[0]);
    visited[seq[0]] = true;

    int iter = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        while(iter<seq.size() && adj[u].count(seq[iter]) != 0){
            int v = seq[iter];
            visited[v] = true;
            q.push(v);
            iter++;
        }
    }
}

int main(){
    int n;
    cin>>n;
    memset(visited, false, sizeof(visited));
    for(int i=0; i<n-1; i++){
        int x, y; cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    vector<int>seq(n);
    for(int i=0; i<n; i++)cin>>seq[i];
    bfs(seq);
    bool ans = true;
    for(int i=0; i<n; i++)if(!visited[i+1])ans=false;
    if(ans && seq[0]==1)cout<<"YES";
    else cout<<"NO";
}
