	
		#include <bits/stdc++.h>	
		using namespace std;
		
		typedef long long int ll;
		
		struct task{
			ll idx,t,d;
		};
		
		bool ordenar(task &a, task &b){
			if(a.d<b.d)return true;
			if(a.idx<b.idx)return true;
			return false;
		}
		
		int main(){
			ios_base::sync_with_stdio(false); cin.tie(NULL);
			
			ll n; cin>>n;
			vector<task>v(n);
			for(int i=0; i<n; i++){
				ll t,d; cin>>t>>d;
				v[i].idx = i;
				v[i].t = t;
				v[i].d = d;
			}
			sort(v.begin(),v.end(),ordenar);
			
			ll time = 0;
			vector<ll>ans;
			for(auto a:v){
				time+=a.t;
				if(time>a.d){
					break;
				}
				ans.push_back(a.idx);
				//cout<<a.t<<" "<<a.d<<"\n";
			}
			
			if(ans.size() == n){
				for(auto a:ans)cout<<a+1<<" ";
			}else{
				cout<<"*";
			}
			
			return 0;
		}
		
		/*
		Casos:
4
1 10
2 9
2 9
2 9 
		ans = 1 2 3 4
		*/