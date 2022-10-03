
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	ll lcm(ll a, ll b)
	{
		return (a / __gcd(a, b)) * b;
	}
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		ll n, x; cin>>n>>x;
		vector<ll>v;
		set<ll>s;
		for(int i=0; i<n; i++){
			ll x; cin>>x;
			s.insert(x);
		}
		for(auto a:s)v.push_back(a);
		n = v.size();
		vector<ll>aux;
		for(int i=0; i<n; i++){
			bool flag = true;
			for(int j=0; j<n; j++){
				if(j!=i && v[i]%v[j]==0){
					flag = false;
				}
			}
			if(flag)aux.push_back(v[i]);
		}
		n = aux.size();
		ll res = 0;
		for(int i=0; i<n; i++){
			vector<ll>div;
			for(int j=i+1; j<n; j++){
				div.push_back(lcm(aux[i], aux[j]));
			}
			res+=(x/aux[i]);
			for(auto a:div)res-=(x/a);
			for(int j=0; j<div.size(); j++){
				for(int jj=j+1; jj<div.size(); jj++){
					res+=((x/lcm(div[j], div[jj])))	;
				}
			}
		}
		
		
		cout<<res<<endl;
		return 0;
	}