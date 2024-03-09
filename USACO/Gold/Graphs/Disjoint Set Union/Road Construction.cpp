
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
int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	DSU dsu(n+1);
	int total = n;
	int largest = 0;
	while(m--){
		int u,v;cin>>u>>v;
		if(!dsu.same_set(u,v))total--;
		dsu.unite(u, v);
		largest = max(largest, dsu.size(u));
		cout<<total<<" "<<largest<<"\n";
	}
	return 0;
}