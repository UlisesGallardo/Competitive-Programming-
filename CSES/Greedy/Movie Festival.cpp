
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	bool cmp(pair<ll,ll> &a, pair<ll,ll> &b){
		if(a.second<b.second)return true;
		if(a.second == b.second){
			if(a.first < b.first)return true;
		}
		return false;
	}
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int n; cin>>n;
		vector<pair<ll,ll>>v(n);
		for(int i=0; i<n; i++)cin>>v[i].first>>v[i].second;
		
		sort(v.begin(),v.end(),cmp);
		
		int res = 0;
		int left = v[0].second;
		res++;
		for(int i=1; i<n; i++){
			if(v[i].first>=left){
				left = v[i].second;
				res++;
			}
		}
		
		cout<<res;
		
		return 0;
	}