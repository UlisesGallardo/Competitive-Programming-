
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	const int N = 100000 + 10;
	vector<vector<pair<int,int>>>adj(N);
	
	void dijkstra(int n, ll candy, int start, int home){
		vector<bool>visited(n+10,false);
		vector<ll>amount(n+10,0);
		amount[start] = candy;
		
		for(int i=1; i<=n; i++){
			int v = -1;
			for(int j=1; j<=n; j++){
				if(!visited[j] && (v==-1 || amount[j]>amount[v])){
					v = j;
				}
			}
			if(amount[v] == 0)break;
			visited[v] = true;
			
			for(auto edje : adj[v]){
				int u = edje.first;
				double menos = amount[v] * double(edje.second/100.0);
				ll cc = amount[v] - ceil(menos);
				
				if(cc > amount[u]){
					amount[u] = cc;
				}
			}
		}
		cout<<amount[home];
	}
	
	int main(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		
		int n,m; cin>>n>>m;
		int start, home;cin>>start>>home;
		ll c; cin>>c;
		for(int i=0; i<m; i++){
			int x,y,z; cin>>x>>y>>z;
			adj[x].push_back({y,z});
			adj[y].push_back({x,z});
		}
		
		dijkstra(n, c, start,home);
	}