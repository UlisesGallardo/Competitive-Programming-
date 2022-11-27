
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int v(char c){
		return c - 'a' +1;
	}
	int main(){
		string s; cin>>s;
		int n = s.size();
		ll b = 41;
		ll M = 1e9+7;
		vector<ll>h(n+1),pb(n+1);
		
		h[0] = 0;
		for(int i=0; i<n; i++){
			h[i+1] = (h[i]*b + v(s[i]))%M;
		}
		
		pb[0] = 1;
		for(int i=0; i<n; i++){
			pb[i+1] = (pb[i]*b)%M;
		}
		
		for(int i=1; i<=n; i++){
			ll hash = h[i];			
			int period = 2;
			while(period<=(n/i)){
				hash = (hash*pb[i] + h[i])%M;
				period++;
			}
			int extra = n%i;
			if(extra) hash = (hash*pb[extra] + h[extra])%M;
			if(hash == h[n]){
				cout<<i<<" ";
			}
		}
	}