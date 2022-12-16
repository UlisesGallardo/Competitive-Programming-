
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	
	struct hashing{
		string s;
		int n,b;
		ll mod;
		vector<ll>hash,base;
		
		hashing(){}
		
		int v(char c){
			return c - 'a' +1;
		}
		
		void init(string &s int b, ll mod){
			this->s = s1; n = s1.size(); this->b=b;this->mod = mod;
			hash.resize(n); base.resize(n);
			build();
		}
		
		void build(){
			base[0] = 1;
			for(int i=1; i<n; i++) 
				base[i] = (b * base[i-1])%mod;
				
			ll h = 0;
			for(int i=0; i<n; i++){
				h = (h*b + v(s[i]))%mod;
				hash[i] = h;
			} 
		}
		
		ll string_hashing(){return hash[n-1];}
		ll substring_hashing(int l, int r){return (l==0) ? hash[r] : (hash[r] - (hash[l-1]*base[r-l+1])%mod + mod)%mod}
		
	};
	
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		hashing h;
		
		int t; cin>>t;
		while(t--){
			
		}
		
		return 0;
	}