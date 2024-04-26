    #include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int a,b,c; cin>>a>>b>>c;

        if(a == 0){
            if(c == 1)cout<<b;
            else cout<<-1;
            cout<<"\n";
            continue;
        }

        int nivel = 0, suma = 0, last = 0;
        for(int i=0; i<20; i++){
            int exp = pow(2,i);
            if(suma + exp <= a){
                nivel++;
                suma += exp;
                last = exp;
            }else break;
        }
        int extra = a - suma;
        int leaf = last*2;
        int nodos_leaf = leaf + extra;
        if( nodos_leaf != c ){
            cout<<-1<<"\n";
            continue;
        }
        if(extra > 0)nivel++;
        if( b > 0 ){
            int rest = leaf - extra;
            if( b - rest > 0){
                //cout<<rest<<"\n";
                b-=rest;
                if(extra == 0)nivel++;
                nivel += ceil(b/double(nodos_leaf));
            }else if(b > 0 && leaf == c)nivel++;
        }
        cout<<nivel<<"\n";
    }
    return 0;
}
