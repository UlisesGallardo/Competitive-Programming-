#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
class UnionFind{
private:
    vi p, rank_, setSize;
public:
    UnionFind(int N){
        p.assign(N,0); for(int i = 0; i < N; i++)p[i] = i;
        rank_.assign(N,0);
        setSize.assign(N,1);
    }

    int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
    bool isSameSet(int i, int j){ return findSet(i) == findSet(j);}
    void UnionSet(int i, int j){
        if(isSameSet(i,j))return;
        int x = findSet(i), y = findSet(j);
        if(rank_[x] > rank_[y]) swap(x,y);
        p[x] = y;
        if(rank_[x] == rank_[y]) ++rank_[y];
        setSize[y] += setSize[x];
    }

    int countMembers(int P){
        int members = 0;
        for(int i = 0; i < p.size(); i++){
            if(findSet(i) == P)members++;
        }
        return members;
    }
};

int main(){
    int n,m;
    while(cin>>n>>m){
        if(n == 0 && m == 0)break;
        UnionFind uf(n+10);
        for(int i = 0; i < m; i++){
            int k;scanf("%d",&k);
            vector<int>v(k);
            for(int j = 0; j < k; j++){
                scanf("%d",&v[j]);
                if(j>0){
                    uf.UnionSet(v[0],v[j]);
                }
            }
        }
        printf("%d\n", uf.countMembers(uf.findSet(0)));
    }
    return 0;
}
