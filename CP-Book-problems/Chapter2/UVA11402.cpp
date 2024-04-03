
//Alternative Solution : https://lbv-pc.blogspot.com/2012/10/ahoy-pirates_24.html

#include <bits/stdc++.h>
using namespace std;

typedef vector<char>vc;
typedef vector<short int>vsi;

class LazySegmentTree{
public:
    int n;
    vc lazy;
    vsi A, segtree;

    int l(int p) {return p<<1;}
    int r(int p) {return (p<<1)+1;}

    void build(int p, int L, int R){

        if(L==R) segtree[p] = A[L];
        else{
            int m = (L+R)/2;
            build(l(p),L,m);
            build(r(p),m+1,R);
            segtree[p] = segtree[l(p)] + segtree[r(p)];
        }
    }

    char apply_flip(char v) {
        if (v == 'F') return 'E';
        if (v == 'E') return 'F';
        if (v == 'I') return 'N';
        return 'I';
    }

    void propagate(int p, int L, int R){
        if(lazy[p] == 'N')return;

        int tam = (R-L)+1;
        if(lazy[p] == 'I'){
            //cout<<tam - segtree[p]<<" "<<segtree[p]<<" "<<L<<" "<<R<<"-I\n";
            segtree[p] = (tam - segtree[p]);
        }else if(lazy[p] == 'F'){
            //cout<<tam<<" "<<segtree[p]<<" "<<L<<" "<<R<<"-F\n";
            segtree[p] = tam;
        }else if(lazy[p] == 'E'){
            segtree[p] = 0;
        }

        if(L!=R){

            if(lazy[p] == 'F' || lazy[p] == 'E'){
                lazy[l(p)] = lazy[r(p)] = lazy[p];
            }else{
                lazy[l(p)] = apply_flip(lazy[l(p)]), lazy[r(p)] = apply_flip(lazy[r(p)]);
            }
            /* ****TLE****
            //Instead of applying all the operations, inverse the operation and override the previous one.

            int m = (L+R)/2;
            if(lazy[l(p)] != 'N'){
                propagate(l(p),L,m);
            }
            if(lazy[r(p)] != 'N'){
                propagate(r(p),m+1,R);
            }
            lazy[l(p)] = lazy[r(p)] = lazy[p];
            */
        }

        lazy[p] = 'N';
    }

    int RMQ(int p, int L, int R, int i, int j){
        propagate(p,L,R);

        if(i>j)return 0;
        //printf("%d %d %d %d\n",L,R,i,j);
        if((L>=i) && (R<=j)) return segtree[p];
        int m = (L+R)/2;
        int a = RMQ(l(p),L,m,i,min(m,j));
        int b = RMQ(r(p),m+1,R,max(m+1,i),j);
        //printf("%d %d\n",a,b);
        return  a+b ;
    }

    void update(int p, int L, int R, int i, int j, char val){

        propagate(p,L,R);
        if(i>j)return;
        //printf("%d %d %d %d\n",L,R,i,j);
        if((L>=i) && (R<=j)){
            lazy[p] = val;
            propagate(p, L, R);
        }else{
            int m = (L+R)/2;
            update(l(p),L,m,i,min(m,j), val);
            update(r(p),m+1,R,max(m+1,i),j, val);
            segtree[p] = segtree[l(p)] + segtree[r(p)];;
        }
    }

    LazySegmentTree(int sz) : n(sz), segtree(sz*4, 0), lazy(sz*4,'N'){}

    LazySegmentTree(vsi initialA): LazySegmentTree((int)initialA.size()){
        A = initialA;
        build(1,0,n-1);
    }

    void update(int i, int j, char val){ update(1, 0, n-1, i, j, val);}

    int RMQ(int i, int j){ return RMQ(1,0,n-1,i,j);}
};

int main(){
    int n,m,t,q;
    scanf("%d",&n);
    int caso = 0;
    while(n--){
        caso++;
        scanf("%d",&m);
        string s = "";
        for(int i = 0; i < m; i++){
            scanf("%d",&t);
            string aux;cin>>aux;
            while(t--)s+=aux;
        }
        vsi vec(s.size());
        for(int i = 0; i < s.size(); i++) {vec[i] =  s[i] == '0' ? 0 : 1;}
        LazySegmentTree st(vec);
        scanf("%d",&q);
        printf("Case %d:\n",caso);
        int query = 0;
        for(int i = 0 ; i < q; i++){
            int a,b;
            char type; scanf(" %c %d %d",&type,&a, &b);
            if(type == 'F'){
                st.update(a, b, 'F');
            }else if(type == 'E'){
                st.update(a, b, 'E');
            }else if(type == 'I'){
                st.update(a, b, 'I');
            }else{
                query++;
                printf("Q%d: %d\n",query,st.RMQ(a, b));
            }
        }
    }


    return 0;
}
