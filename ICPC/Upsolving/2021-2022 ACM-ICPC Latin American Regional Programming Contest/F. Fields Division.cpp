
	#include <bits/stdc++.h>	
	using namespace std;
	
	const int MAXN  =  300009;
	vector<vector<int>>adj(MAXN);
	
	int ans[MAXN];
	void dfs(int node, int sibling){ //1 Ana, 0 Bob
		ans[node] = sibling;
		for(auto u:adj[node]){
			if(ans[u] == -1){
				dfs(u, sibling);
			}
		}
	}
	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		int n,m; cin>>n>>m;
		memset(ans, -1, sizeof(ans));
		for(int i=0; i<m; i++){
			int u,v; cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		ans[n] = 1;
		dfs(n-1,0);
		dfs(n,1);
		
		for(int i=1; i<=n; i++){
			if(ans[i]==1)cout<<"A";
			else cout<<"B";
		}
		
		return 0;
	}