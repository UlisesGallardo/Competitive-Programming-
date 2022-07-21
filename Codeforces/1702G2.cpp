	#include <bits/stdc++.h>
	using namespace std;
	
	const int N = 2e5+10;
	vector<vector<int>>adj;
	const int LOG = ceil(log2(N));
	int up[N][LOG], depth[N], visited[N], entrar[N], salir[N];
	int n, con;

	void dfs(int node, int padre){
		depth[node] = depth[padre]+1;
		up[node][0] = padre;
		visited[node] = true;
		entrar[node] = con;
		con++;
		for(int j=1; j<LOG; j++){
			up[node][j] = up[ up[node][j-1] ][j-1];
		}
		for(auto a:adj[node]){
			if(!visited[a])dfs(a, node);
		}
		salir[node] = con;
		con++;
	}
	
	bool isAncestor(int u, int v){
		return (entrar[u]<=entrar[v]&&salir[u]>=salir[v]);
	}
	
	int LCA(int u, int v){
		if(isAncestor(u,v))return u;
		if(isAncestor(v,u))return v;
		for (int i = LOG-1; i >= 0; i--) {
            if (!isAncestor(up[u][i], v)) {
                u = up[u][i];
            }
        }	
        return up[u][0];
	}
	
	int Distance(int u, int v){
		return (depth[u] + depth[v] - 2*depth[LCA(u,v)]);
	}
	
	bool OnPath(int u, int v, int w, int lca){
		return (isAncestor(lca, w) && (isAncestor(w,u) || (isAncestor(w,v))));
	}
	
	int main(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		con = 0;
		cin>>n;
		adj.resize(n+10,vector<int>());
		for(int i=0; i<n-1; i++){
			int x,y; cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		dfs(1,1);
		
		int q; cin>>q;
		while(q--){
			int m; cin>>m;
			vector<int>v(m);
			int left,right;
			int deepest1=-1, deepest2 =-1;
			for(int i=0; i<m; i++){
				cin>>v[i];
				if(depth[v[i]]>deepest1){
					left = v[i];
					deepest1 = depth[v[i]];
				}
			}
			for(auto node:v){
				int dis = Distance(node,left);
				if(dis>deepest2){
					right = node;
					deepest2 = dis;
				}
			}
			
			bool flag = true;
			int lca = LCA(left, right);
			for(auto node: v){
				if(!(OnPath(left,right,node,lca))){
					flag = false;
					break;
				}
			}
			(flag) ? cout<<"YES\n":cout<<"NO\n";
		}
	}