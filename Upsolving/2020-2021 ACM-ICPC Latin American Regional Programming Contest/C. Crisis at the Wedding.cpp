
	#include <bits/stdc++.h>	
	using namespace std;
	typedef long long ll;
	ll n;
	ll solve(vector<ll>v, ll needed){
		deque<ll>dq;
		ll ans = 0;
		for(int i=0; i<5; i++){
			for(int j=0; j<n; j++){
				if(v[j]>needed){
					dq.push_back(j);
				}
				while(!dq.empty() && v[j]<needed){
					ll actual = dq[0];
					ll add = min(abs(v[actual]-needed),abs(v[j] - needed));
					v[j]+=add;
					v[actual]-=add;
					ll dis = ((j-actual + n)%n);
					ans += ll(dis * add);
					if(v[actual] == needed)dq.pop_front();
				}
			}
		}
		
		return ans;
	}
	
	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		cin>>n;
		vector<ll>v(n);
		ll sum = 0;
		for(int i=0; i<n; i++){
			cin>>v[i];
			sum+=v[i];
		}
		ll needed = sum/n;
		//cout<<needed<<"\n";
		ll clock = solve(v,needed);
		reverse(v.begin(),v.end());
		ll clocknt = solve(v,needed);
		//cout<<clock<<" "<<clocknt<<"\n";
		cout<<min(clock, clocknt);
		return 0;
	}