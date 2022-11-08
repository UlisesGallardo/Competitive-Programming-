	#include<bits/stdc++.h>
	using namespace std;
	
	const int N = 100001;
	vector<int>v(N), sum(N);
	int n;
	string s; 
	
	int dp(int pos){
		if(pos == 0){
			if(s[pos] == '0')return 0;
			else return v[0];
		}
		if(s[pos] == '1') return max(sum[pos-1], v[pos] + dp(pos-1));
		else return dp(pos-1);
	}
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>v[i];
			if(i)sum[i]+=sum[i-1]+v[i];
			else sum[i] = v[i];
		}
		cin>>s;
		cout<<dp(n-1);
	}