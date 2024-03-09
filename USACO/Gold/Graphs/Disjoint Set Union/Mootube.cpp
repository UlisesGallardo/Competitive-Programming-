#include<bits/stdc++.h>
using namespace std;

ifstream fin("mootube.in");
ofstream fout("mootube.out"); 

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

struct Query{
	int w,u,index;
};

struct Edge{
	int u,v,w;
	bool operator > (const Edge& edge) const
    {
        return (w > edge.w);
    }
};

bool compare(const Query &a, const Query &b){
	return a.w > b.w ? true : false;
}

int main(){
	int n,q; fin>>n>>q;
	vector<Edge>edges;
	for(int i=0; i<n-1; i++){
		int u,v,w; fin>>u>>v>>w;
		Edge new_e = {u,v,w};
		edges.push_back(new_e);
	}
	vector<Query>queries;
	for(int i=0; i<q; i++){
		int k,u; fin>>k>>u;
		Query new_q = {k,u,i};
		queries.push_back(new_q);
	}
	sort(queries.begin(),queries.end(), compare);
	sort(edges.begin(),edges.end(), greater<Edge>());
	vector<int>ans(q);
	
	DSU dsu(n+1);
	int nodes = 0;
	for(int i=0; i<q; i++){
		Query query = queries[i];
		//it is important to unite all the components
		while(nodes<edges.size() && edges[nodes].w >= query.w){
			dsu.unite(edges[nodes].u,edges[nodes].v);
			nodes++;
		}
		ans[query.index] = dsu.size(query.u);
	}
	
	for(auto a:ans)fout<<a-1<<"\n";
}