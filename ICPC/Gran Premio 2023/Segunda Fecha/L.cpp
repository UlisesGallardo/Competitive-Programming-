
	#include <bits/stdc++.h>	
	using namespace std;

	vector<double>speed(3);
	int n;
	vector<int>t(50,0);
	int memo[51][510][510]; //n,a,b, mientras que c se calcula
	int total;
	
	int dp(int pos, int a, int b){
		if(memo[pos][a][b]!=-1)return memo[pos][a][b];
		if(pos == n){
			int c = total - a - b;
			return ceil(max(a/speed[0], max(b/speed[1], c/speed[2])));
		}
		
		int t1,t2,t3;
		t1 = dp(pos+1, a+t[pos], b);
		t2 = dp(pos+1, a, b+t[pos]);
		t3 = dp(pos+1, a, b);
		memo[pos][a][b] = min(t1,min(t2,t3));
		return memo[pos][a][b];
	}
	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		cin>>n;
		total = 0;
		for(int i=0; i<3; i++)cin>>speed[i];
		for(int i=0;i<n; i++){
			cin>>t[i]; 
			total+=t[i];
		}
		memset(memo, -1, sizeof(memo));
		cout<<dp(0,0,0);
		return 0;
	}