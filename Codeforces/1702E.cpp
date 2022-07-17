        #include<bits/stdc++.h>
		using namespace std;
		
		const int N = 2e5+10;
		int color[N];
		
		bool isBipartite(int nodo,vector<vector<int>>adj){
			queue<int>q;
			q.push(nodo);
			color[nodo] = 1;
			while(!q.empty()){
				int u = q.front();
				q.pop();
				for(int i=0; i<adj[u].size(); i++){
					if(color[adj[u][i]] == -1){
						color[adj[u][i]] = 1 - color[u];
						q.push(adj[u][i]);
					}else if(color[adj[u][i]] == color[u]){
						return false;
					}
				}
			}	
			return true;
		}
		
		bool check(int n, vector<vector<int>>adj){
			memset(color,-1,sizeof(color));
			for(int i=1; i<=n; i++){
				if(color[i] == -1){
					if(!isBipartite(i, adj))return false;
				}
			}
			return true;
		}
		
		
		int main(){
			int t; cin>>t;
			while(t--){				
				int n; cin>>n;
				vector<vector<int>>adj(n+5);
				bool flag = false;
				for(int i=0; i<n; i++){
					int x,y; cin>>x>>y;
					adj[x].push_back(y);
					adj[y].push_back(x);
					if(x == y || adj[x].size()>=3 || adj[y].size()>=3 ){
						flag = true;
					}
				}
				//adj = aux;
				if(flag)cout<<"NO\n";
				else check(n, adj) ? cout<<"YES\n": cout<<"NO\n";
				adj.clear();
			}
			
		}