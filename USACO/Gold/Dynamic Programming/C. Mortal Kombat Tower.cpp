
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int values[N];
int memo[N][2][2];
int n;

int solve(int pos, int player, int times){
	if(pos >= n)return 0;
	if(times == 2)return 1e6;	
	if(memo[pos][player][times] != -1)return memo[pos][player][times];
	
	int skip_point = 0; 
	if(player == 0 && values[pos] == 1)skip_point+=1;
	skip_point += min(solve(pos+1, player, times+1), solve(pos+1, (player+1)%2, 0));
	return memo[pos][player][times] = skip_point;
}

int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	while(t--){
		cin>>n;
		for(int i=0; i<n; i++)for(int j=0;j<2; j++)for(int k=0;k<2; k++)memo[i][j][k]= -1;
		for(int i=0; i<n; i++)cin>>values[i];
		cout<<solve(0,0,0)<<"\n";
	}
	
	return 0;
}