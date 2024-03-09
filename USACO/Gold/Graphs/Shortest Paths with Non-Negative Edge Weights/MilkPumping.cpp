#include<bits/stdc++.h>
using namespace std;

ifstream fin("pump.in");
ofstream fout("pump.out"); 

const int N = 1e3+5;
vector<vector<pair<int,pair<int,int>>>>adj(N);
vector<int>distances(N, INT_MAX);
vector<bool>processed(N,false);
int n,m;
const int PRECISION = 1e6;

int disktra(int start, int flow){
	priority_queue<pair<int,int>>pq; //cost, node, flow
	distances[start] = 0;
	pq.push({0,start});
	
	while(!pq.empty()){
		int a = pq.top().second; 
		pq.pop();
		
		if (processed[a]) continue;
		processed[a] = true;
		
		for (auto u : adj[a]) {
			int b = u.first;
			int c = u.second.first;
			int f = u.second.second;
			
			if (distances[a] + c < distances[b] && f >= flow) {
				distances[b] = distances[a]+c;
				pq.push({-distances[b], b});
			}
		}
	}
	return distances[n];
}

int main(){
	//cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	fin>>n>>m;
	
	set<int>fixed_flow;
	
	for(int i=0; i<m; i++){
		int u,v,c,f; fin>>u>>v>>c>>f;
		adj[u].push_back({v,{c,f}});
		adj[v].push_back({u,{c,f}});
		fixed_flow.insert(f);
	}
	
	int ans = -1;
	for(auto flow : fixed_flow){
		processed.assign(processed.size(), false);
		distances.assign(processed.size(),INT_MAX);
		int sum_cost = disktra(1, flow);
		if (sum_cost == INT_MAX) continue;
		double ratio = double(flow) / double(sum_cost);
		ans = max(ans,(int)(ratio * PRECISION));
	}
	fout<<ans;
}