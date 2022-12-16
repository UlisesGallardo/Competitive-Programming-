
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	vector<vector<pair<int,ll>>>adj;
	vector<bool>visited;
	
	bool ans = false;
	
	set<ll>x;
	
	void dfs_a(int node, int b, ll current_x){
		visited[node] = true;
		x.insert(current_x);
		for(auto a: adj[node]){
			if(a.first!=b && !visited[a.first]){
				dfs_a(a.first, b, current_x^a.second);
			}
		}
	}
	
	void dfs_b(int node, ll current_x){
		visited[node] = true;
		for(auto a: adj[node]){
			if(!visited[a.first] && !ans){
				ll aux = current_x;
				aux^=a.second;
				
				if(x.count(aux)!=0){
					ans = true;
				}
				dfs_b(a.first, aux);
			}
		}
	}
	
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int t; cin>>t;
		while(t--){
			x.clear();
			ans = false;
			adj.clear();
			
			int n,a,b; cin>>n>>a>>b;
			
			adj.resize(n+10);
			visited.resize(n+10);
			fill(visited.begin(), visited.end(), false);

			for(int i=1; i<=n-1; i++){
				int x,y; ll w; cin>>x>>y>>w;
				adj[x].push_back({y,w});
				adj[y].push_back({x,w});
			}
			
			dfs_a(a,b,0);
			fill(visited.begin(), visited.end(), false);
			dfs_b(b,0);				
			cout<< (ans ? "YES\n" : "NO\n");		
		}
		
		return 0;
	}