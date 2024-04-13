#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    long double x; cin>>x;
    vector<long double>v(n);
    long double p = 0.0;
    for(int i=0; i<n; i++){
        cin>>v[i];
        p+=(v[i]*v[i]);
    };
    p/=(double(n));
    if(p == 0){
        for(int i=0; i<n; i++)printf("%0.10Lf ", sqrt(x)*v[i]);
    }else{
        for(int i=0; i<n; i++)printf("%0.10Lf ", sqrt(x)*v[i]/sqrt(p));
    }
    return 0;
}
