
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
		vector<ll>h(n+1),hp(n+1),pb(n+1);
		
		h[0] = 0;
		for(int i=0; i<n; i++){
			h[i+1] = (h[i]*b + v(s[i]))%M;
		}
		
		hp[n] = 0;
		for(int i=n; i>0; i--){
			hp[i-1] = (hp[i]*b + v(s[i-1]))%M;
		}
		
		pb[0] = 1;
		for(int i=0; i<n; i++){
			pb[i+1] = (pb[i]*b)%M;
		}
		
		for(int i=1; i<=n; i++){
			ll hash1 = h[i]%M;
			ll hash2 = ((h[n] - h[n-i]*pb[i])%M + M)%M;

			if(hash1 == hash2 && i!=n){
				cout<<i<<" ";
			}
		}
	}