
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	string solve(ll k){
		if(k == 1)return "2";
		if(k%2 == 0 ) return "("+solve(k/2)+")^2";
		if(k%2 != 0) return "(2*"+solve(k-1)+")"; 
	}
	
	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		int t; cin>>t;
		
		while(t--){
			ll k; cin>>k;
			cout<<solve(k)<<"\n";
		}
	}