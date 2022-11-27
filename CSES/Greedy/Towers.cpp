
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int n; cin>>n;
		multiset<ll>towers;
		
		for(int i=0; i<n; i++){
			 ll size; cin>>size;
			 auto it = towers.upper_bound(size);
			 if(it==towers.end()){
			 	towers.insert(size);
			 }else{
			 	towers.erase(it);
			 	towers.insert(size);
			 }
		}
		cout<<towers.size();

		
		return 0;
	}