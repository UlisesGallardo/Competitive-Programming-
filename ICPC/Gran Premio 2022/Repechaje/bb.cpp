
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	int X[] = {0,1,-1,0};
	int Y[] = {1,0,0,-1};
	
	int dfs(vector<vector<int>> &matrix, vector<vector<int>>  &dp, vector<vector<bool>> &visited, int i, int j, set<int> stamps,int n,int m){
		
		if(visited[i][j]){
			dp[i][j]
			return dp[i][j];
		}
		
		visited[i][j] = true;
		
		stamps.insert(matrix[i][j]);
		
		for(int dir=0; dir<4; dir++){
			int x = X[dir]+j;
			int y = Y[dir]+i;
			if(x>=0 && x<=m && y>=0 && y<=n){
				set<int> aux = dfs(matrix,dp,visited,y,x,stamps,n,m);
			}
		}
		
		int res = stamps.size(); 
		dp[i][j] = min(dp[i][j],res);
		
		for(int dir=0; dir<4; dir++){
			int x = X[dir]+j;
			int y = Y[dir]+i;
			if(x>=0 && x<=m && y>=0 && y<=n){
				set<int>aux = stamps;
				aux.insert(matrix[y][x]);
				int value = aux.size();
				dp[y][x] = min(dp[y][x], value);
			}
		}
		
		return dp[i][j];
	}
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		
		int n,m; cin>>n>>m;
		int rhome,chome,rdest,cdest; cin>>rhome>>chome>>rdest>>cdest;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		vector<vector<set<int>>> dp(n, vector<set<int>> (m));
		vector<vector<bool>> visited(n, vector<bool> (m, 0));

		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>matrix[i][j];
			}
		}
		
		n--;m--;
		set<int> stamps;
		dfs(matrix,dp,visited,rhome,chome,stamps,n,m);
		cout<<dp[rhome-1][chome-1].size();
		return 0;
	}