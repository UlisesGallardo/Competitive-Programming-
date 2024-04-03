	#include<bits/stdc++.h>
	using namespace std;
	
	const int N= 1000+1;
	int logN;
	const int size = log2(N);
	//vector<vector<int>>adj(N);
	vector <int> adj[1001];

	int up[N][size];
	int depth[N];
	
	void dfs(int node, int parent){
		up[node][0] = parent;
		depth[node] = depth[parent]+1;
		for(int i=1; i<logN; i++){
			up[node][i] = up[ up[node][i-1] ][i-1]; //?
		}
		for(int i=0; i<adj[node].size(); i++){
			dfs(adj[node][i],node);
		}
	}
	
	int LCA(int a, int b){
		if(depth[b]>depth[a])swap(a,b);
		while(depth[a]!=depth[b])a = up[a][0];
		if(a==b)return a;
		
		while(a!=b){
			a = up[a][0];
			b = up[b][0];
		}
		return a;
	}
	
	int main(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int t; cin>>t;
		int caso = 1;
		while(t--){
			memset(depth,0, sizeof(depth));
			
			int n; cin>>n;
			logN = log2(n);
			for(int i=1; i<=n; i++){
				adj[i].clear();
				int m; cin>>m;
				for(int j=0; j<m; j++){
					int x; cin>>x;
					adj[i].push_back(x);
				}
			}	
			dfs(1,1);
			int q; cin>>q;
			cout<<"Case "<<caso<<":\n";
			while(q--){
				int u,v; cin>>u>>v;
				cout<<LCA(u,v)<<"\n";
			}
			caso++;
		}
	}