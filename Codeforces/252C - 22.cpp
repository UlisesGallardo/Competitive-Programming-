
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	ll nCr(ll n)
	{
		return n*(n-1)/2; //nCr -> r = 2
	}
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		ll d; 
		int n; cin>>n>>d;
		vector<ll>v(n);
		for(int i=0; i<n; i++)cin>>v[i];
		
		ll res = 0;
		int l=0,r= 2;
		while(r<n){
				while(v[r]-v[l]>d)l++;
				res+=nCr((r-l));
				r++;
		}
		cout<<res;
		return 0;
	}