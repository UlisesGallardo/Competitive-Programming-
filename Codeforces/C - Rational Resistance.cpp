
	#include <bits/stdc++.h>
	using namespace std;
	typedef unsigned long long int ll;
	ll times = 0;
	ll solve(ll a,ll b){
		//cout<<a<<" "<<b<<"\n";
		if(a==1)return b;
		if(b==1)return a;
		ll u = a/b;
		a -= (u*b);
		if(u==0){
			//times++;
			ll aux = b/a;
			times += aux;
			ll n = a;
			ll d = b-(a*aux);
			if(n%d==0){a=n/d;b=1;}
			else{a=n;b=d;}
		}
		return u + solve(a,b);
	}
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		ll a,b; cin>>a>>b;
		if(a==1) (b==1)?cout<<"1" : cout<<b;
		else if(b==1)cout<<a;
		else if(a==b)cout<<1;
		else{
			cout<<solve(a,b) + times;
		}
		
		return 0;
	}