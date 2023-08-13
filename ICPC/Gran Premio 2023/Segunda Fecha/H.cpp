
	#include <bits/stdc++.h>	
	using namespace std;
	
	const int N = 1e6+10;
	 
	vector<int>groups(N, 0);
	vector<int>checked(N, 0);
	vector<int>ans(N,0);
	vector<vector<int>>adj(N);
	
	void dfs(int node, unordered_set<int> &s){
		s.insert(groups[node]);
		checked[groups[node]]++;
		ans[node] = s.size();
		for(auto u:adj[node]){
			dfs(u, s);
		}
		checked[groups[node]]--;
		if(checked[groups[node]] == 0)s.erase(groups[node]);
	}
	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		int n; cin>>n;
		int node;
		for(int i=1; i<=n; i++){
			int v; cin>>v;
			if(v == 0)node = i;
			else adj[v].push_back(i); 
		}
		
		for(int i=1; i<=n; i++){
			int g; cin>>g;
			groups[i] = g;
		}
		
		unordered_set<int>s;
		dfs(node, s);
		
		for(int i=1; i<=n; i++){
			cout<<ans[i]<<" ";
		}
		
		return 0;
	}