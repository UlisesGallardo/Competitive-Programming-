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
        setSize.assign(N,0);
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
            if(p[i] == P)members++;
        }
        return members;
    }
};

int main(){
    int n,q; scanf("%d %d",&n,&q);

    while(q--){
        char type; int a,b;
        scanf(" %c %d %d",&type, &a, &b);
        if(type == '?') printf(uf.isSameSet(a,b) ? "yes\n" : "no\n");
        else uf.UnionSet(a,b);
    }
    return 0;
}
