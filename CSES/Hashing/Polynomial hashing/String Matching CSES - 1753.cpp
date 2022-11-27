
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int v(char c){
		return c - 'a' +1;
	}
	int main(){
		string s,p; cin>>s>>p;
		int n = s.size(), m = p.size();
		ll b = 41;
		ll M = 1e9+7;
		vector<ll>h(n+1),hp(m+1),pb(m+1);
		
		h[0] = 0;
		for(int i=0; i<n; i++){
			h[i+1] = (h[i]*b + v(s[i]))%M;
		}
		hp[0] = 0;
		for(int i=0; i<m; i++){
			hp[i+1] = (hp[i]*b + v(p[i]))%M;
		}
		pb[0] = 1;
		for(int i=0; i<m; i++){
			pb[i+1] = (pb[i]*b)%M;
		}
		
		int res = 0;
		for(int i=0; i+m<=n; i++){
			ll hash = ((h[i+m] - h[i]*pb[m])%M + M)%M;
			//cout<<hash<<" "<< hp.back();
			if(hash == hp.back())res++;
		}
		cout<<res;
	}