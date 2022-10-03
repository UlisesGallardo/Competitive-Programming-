	
	#include<bits/stdc++.h>
	using namespace std;
	vector<vector<int>>adj;
	vector<int>depth, Subtree;
	bool visited[200001];
	int dfs(int node, int parent){
		visited[node] = true;
		depth[node]= depth[parent]+1;
		Subtree[node] = 1;
		for(auto a:adj[node]){
			if(!visited[a]){
				Subtree[node]+=dfs(a,node);
			}
		}
		return Subtree[node];
	}
	
	int main(){
		int n,k; cin>>n>>k;
		adj.resize(n+1, vector<int>());
		depth.resize(n+1,0);
		Subtree.resize(n+1,0);
		for(int i=0; i<n-1; i++){
			int x,y; cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		dfs(1,0);
		vector<int>res;
		for(int i=1; i<=n; i++){
			res.push_back(depth[i] - Subtree[i]); 
		}
		sort(res.begin(),res.end(),greater<int>());
		long long ans=0;
		
		for(int i=0; i<k; i++){
			ans+=(res[i]);
		}
		cout<<ans;
	}