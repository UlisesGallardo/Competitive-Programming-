	    #include<bits/stdc++.h>
		using namespace std;
		long long int ll;
		
		int main(){
			int t; cin>>t;
			while(t--){
				int n; cin>>n;
				vector<pair<int,int>>v;
				for(int i=0; i<n; i++){
					int x; cin>>x;
					if(i+1>x){
						v.push_back({x,i+1});
					}
			    }
				sort(v.begin(),v.end());
				long long res = 0;
				/*
				for(auto [a,b]:v){
					cout<<a<<" "<<b<<"\n";
				}
				cout<<"\n";
				*/
				n = v.size();
				for(int i=0; i<n; i++){
					if(v[i].first<v[i].second){
					//	cout<<v[i].first<<" "<<v[i].second<<" ";
						int l,r,m;
						l = 0;
						r = n-1;
						while(l<=r){
							m = l + (r-l)/2;
							if(v[m].first > v[i].second){
								r = m-1;
							}else{
								l = m+1;
							}
						}
						//cout<<(r)<<" "<<(n-(r)-1)<<"\n";
						res+=(n-r)-1;
					}
				}
				cout<<res<<"\n";
			}
		}