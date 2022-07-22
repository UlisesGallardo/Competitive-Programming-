	
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	ll maximo(ll C, ll R,ll S){
		ll res = 0;
	    if(R == 0 && C%S>0){
	    	res = C/S;
	    	return res+1;
	    }
	    if(C >= S){
	    	res = C/S;
	    	return res;
	    } 
	    return 0;
	}
	
	ll minimo(ll C,ll R,ll S){
		ll cantidad =  (unsigned long long int)R* (unsigned long long int)(S-1);
	    C=C-cantidad;
	    if(C>0) return maximo(C,0,S);
	    return 0;
	}
	
	int main(){
	    int Q;cin>>Q;
	    while(Q--){
	        ll C,R,S; cin>>C>>R>>S;
	        cout<<maximo(C,R,S)<<" ";
	        cout<<minimo(C,R,S)<<"\n";
	    }
	}