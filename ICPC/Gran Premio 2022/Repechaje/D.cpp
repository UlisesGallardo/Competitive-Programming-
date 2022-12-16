
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int m; cin>>m;
		vector<ll>v(m+10, 0);
		multiset<ll>ms;
		
		int i=0;
		while(m--){
			int type; cin>>type;
			if(type == 1){
				i++;
				ll x; cin>>x;
				v[i] = x;
				ms.insert(x);
			}else if(type == 2){
				int index; cin>>index;
			
				auto itr = ms.find(v[index]);
				if(itr!=ms.end()){
				    ms.erase(itr);
				}
				
			}else if(type==3){
				ll index, x; cin>>index>>x;
				auto itr = ms.find(v[index]);
				if(itr!=ms.end()){
				    ms.erase(itr);
				}
				v[index]+=x;
				ms.insert(v[index]);
			}else if(type==4){
				int index; cin>>index;
				auto it = ms.lower_bound(v[index]);
				
				if(it == ms.end())cout<<0<<endl;
				else{
					ll pos  = std::distance(ms.begin(), it);
					cout<<pos<<endl;
				}
			}
		}
		
		return 0;
	}