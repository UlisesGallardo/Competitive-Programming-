
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;

	#define MAX 200010
	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		int n,x; cin>>n>>x;
		bool activity[MAX] = {false};
		vector<int>v(200010,0);
		for(int i=0; i<n; i++) {
			int start, d; cin>>start>>d;
			for(int j=start;j<=start+d; j++)activity[j]=true;
		}
		pair<int,int> ans {500,1e7};
		
		for(int i=0; i<=480; i++){
			int total = 0;
			for(int j=i; j<=200000; j+=x)if(activity[j])total++;
			if(total < ans.second){
				ans = {i,total};
			}
		}
		
		cout<<ans.first<<" "<<ans.second;
	}