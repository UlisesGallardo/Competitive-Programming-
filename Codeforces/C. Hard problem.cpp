
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	#define INF 999999999999999

	const int N = 1e5+5;
	ll energy[N];
	vector<pair<string,string>>v;
	ll memo[N][2];	
	int n; 
			
	ll dp(int pos, string prev, int tipo){
		if(pos>=n)return 0;
		if(prev>max(v[pos].first,v[pos].second))return INF;
		
		if(memo[pos][tipo]!=-1)return memo[pos][tipo];
		
		ll ans = INF;
		if(prev<=v[pos].first) ans = min(ans, dp(pos+1,v[pos].first,0));
		if(prev<=v[pos].second)ans = min(ans, dp(pos+1,v[pos].second,1) + energy[pos]);
		
		memo[pos][tipo] = ans;
		return memo[pos][tipo]; 
	}
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		cin>>n;
		for(int i=0; i<n; i++)cin>>energy[i];
		for(int i=0; i<n; i++){
			string aux, sorted; cin>>aux;
			sorted = aux;
			reverse(sorted.begin(),sorted.end());
			v.push_back({aux,sorted});
		}
		memset(memo, -1, sizeof(memo));
		
		ll a = dp(1,v[0].first, 0);
		ll b = dp(1,v[0].second,1) + energy[0];
		
		ll res = min(a,b);
		if(res == INF)cout<<-1;
		else cout<<res;
		
		return 0;
	}