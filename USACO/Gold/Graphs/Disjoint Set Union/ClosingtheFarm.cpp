
#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> p;
	DSU(int N) { p = vector<int>(N, -1); }
	int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); }
	bool same_set(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -p[get(x)]; }
	bool unite(int x, int y) {  
		x = get(x), y = get(y);
		if (x == y) return false;
		if (p[x] > p[y]) swap(x, y);
		p[x] += p[y];
		p[y] = x;
		return true;
	}

};

ifstream fin("closing.in");
ofstream fout("closing.out"); 

int main(){
	//cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m;
	fin>>n>>m;
	DSU dsu(n+1);
	
	vector<vector<int>>adj(n+1);
	
	for(int i=0; i<m; i++){
		int u,v; fin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int>query(n);
	for(int i=0; i<n; i++)fin>>query[i];
	reverse(query.begin(), query.end());
	
	vector<string> ans = {"YES"};
	int connected = 1;
	vector<bool>closed(n+1, false);
	closed[query[0]] = true;
	
	for(int i=1; i<n; i++){
		connected++;
		int u = query[i];
		closed[u] = true; 
		for(auto v:adj[u]){
			if(closed[v] && dsu.unite(u, v)) connected--;
		}
		ans.push_back( connected == 1 ? "YES" : "NO" );
	}
	reverse(ans.begin(),ans.end());
	for(auto a: ans) fout<<a<<"\n";
	return 0;
}