#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
class UnionFind{
public:
    vi p, rank_, setSize;
    int n;
public:
    UnionFind(int N){
        p.assign(N,0); for(int i = 0; i < N; i++)p[i] = i;
        rank_.assign(N,0);
        setSize.assign(N,1);
    }

    int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
    bool isSameSet(int i, int j){ return findSet(i) == findSet(j);}
    void UnionSet(int i, int j){
        if(isSameSet(i,j)) return;
        int x = findSet(i), y = findSet(j);
        if(rank_[x] > rank_[y]) swap(x,y);
        p[x] = y;
        if(rank_[x] == rank_[y]) ++rank_[y];
        setSize[y] += setSize[x];
    }

    int findMax(){
        return *max_element(setSize.begin(), setSize.end());
    }
};



int main(){
    int n,m;
    while(cin>>n>>m){
        if(n == 0 && m == 0)break;
        map<string,int>names;

        for(int i = 0; i < n; i++){
            string s; cin>>s;
            names[s] = i;
        }
        UnionFind uf(n);
        while(m--){
            string a,b; cin>>a>>b;
            uf.UnionSet(names[a], names[b]);
        }
        int ans = uf.findMax();
        printf("%d\n",ans);
        string blank;
        getline(cin, blank);
    }
}
