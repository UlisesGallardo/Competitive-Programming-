
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	int final = 10* 100000+10;
	
	int main(){
		int n; cin>>n;
		
		vector<pair<int,int>>v(n);
		for(int i=0; i<n; i++) cin>>v[i].first>>v[i].second;
		
		int con = 0;
		bool visited[n] = {false};
		
		int res = 0;
		while(con<n){
			if(!visited[con]){
				int dir = v[con].second;
				int last;
				if(con == 0)last = v[con].first+10;
				else last = 10;
				visited[con] = true;
			
				for(int i=con+1; i<n; i++ ){
					if(v[i].first>last) break;
					if(v[i].second==dir){
						last = v[i].first +10;
						visited[i] = true;
						//cout<<v[i].first<<"\n";
					}
				}
				
				res+=last;
				con++;
			}else{
				con++;
			}
		}
		cout<<res<<"\n";
	
	}