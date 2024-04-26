#include <bits/stdc++.h>
using namespace std;

const int N = 1000+1;
vector<vector<int>>adj(N);
int color[N];
bool visited[N];

bool bfs_color(int i){
    queue<int>q;
    q.push(i);
    color[i] = 0;
    visited[i] = true;

    while(!q.empty()){
        int v = q.front();
        int c = color[v];
        q.pop();
        for(auto u:adj[v]){
            if(!visited[u]){
                q.push(u);
                visited[u] = true;
                color[u] = (c+1)%2;
            }else if(c == color[u]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n; cin>>n;
    int offset = 1000;
    vector<int>v(10*offset);
    for(int i=0; i<2*n; i++){
        int x; cin>>x;
        if(x>0)v[x] = i;
        else v[abs(x)+offset] = i;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(v[i] < v[j] && v[i+offset] < v[j+offset] && v[i+offset] > v[j]){
                //cout<<i<<" "<<j<<"\n";
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    bool ans = true;
    for(int i=1; i<=n; i++)
        if(!visited[i])
            ans &= bfs_color(i);

    if(!ans)cout<<"*";
    else{
        for(int i=1; i<=n; i++){
            if(color[i]==0)cout<<"G";
            else cout<<"S";
        }
    }
    return 0;
}
