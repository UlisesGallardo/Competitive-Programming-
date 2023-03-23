
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;

	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		int n; cin>>n;
		vector<int> money(n+1);
		cin.ignore();
		string s;
		for(int i=0; i<=n; i++){
			cin>>s;
			money[i] = stoi(s.substr(s.size()-2,s.size()));
		}
		
		int cnt = 0;
		for(int i=1; i<=n; i++){
			money[i]+=money[i-1];
			//cout<<money[i]<<" ";
			if(money[i]%100>0)cnt++;
			money[i]%=100;
		}
		cout<<cnt;
	}