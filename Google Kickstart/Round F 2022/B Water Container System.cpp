
	
	#include <bits/stdc++.h>
	using namespace std;


	void bfs(int n, vector<vector<int>>adj, vector<int>levels,int water){
	
		bool visited[n+10];
		memset(visited, false, sizeof(visited));
		
		queue<int>q;
		q.push(1);
		q.push(1); //level
		
		while(!q.empty()){
			int u = q.front();
			q.pop();
			int level = q.front();
			q.pop();			
			levels[level]++;
			visited[u] = true;
			for(auto a:adj[u]){
				if(!visited[a]){
					q.push(a);
					q.push(level+1);
				}
			}
		}
		
		int res = 0;	
		for(int i=1; i<=n; i++){
			if(levels[i]>0){
				if(water/levels[i] > 0){
					res+=levels[i];
					water-=levels[i];
				}else{
					break;
				}
			}else{
				break;
			}
		}
		cout<<res;
		
	}
	
	void solve(){
		int n, q; cin>>n>>q;
		vector<vector<int>>adj(n+10);
		vector<int>levels(n+10,0);
		
		for(int i=0; i<n-1; i++){
			int u,v; cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		int water = 0;
		while(q--){
			int x; cin>>x;
			water++;
		}
		bfs(n, adj, levels, water);
	}
	
	int main(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int t; cin>>t;
		int t_case = 1;
		while(t--){
			cout<<"Case #"<<t_case<<": ";
			solve();
			cout<<"\n";
			t_case++;
		}
	}