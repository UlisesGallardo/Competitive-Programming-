
	#include <bits/stdc++.h>
	using namespace std;
	const int N = 1000;
	char matrix[N][N];
	int X[] = {1,0,-1,0, 1,-1,1,-1};
	int Y[] = {0,1,0,-1, -1,-1,1,1};
	
	int res = 0;
	void solve(int xx, int yy, int tam,int n, int m){
		res = max(res,tam);
		if(tam==26){
			cout<<26<<"\n";
			exit(0);
		}
		for(int i=0; i<8; i++){
			int u = xx + X[i];
			int v = yy + Y[i];
			if(u>=0 && v>=0 && u<m && v<n && matrix[v][u] == char((int)matrix[yy][xx]+1)){
				solve(u,v,tam+1,n,m);
			}
		}
	}
	
	
	int main(){
		int n,m; cin>>n>>m;
		for(int i=0; i<n;i++){
			for(int j=0; j<m; j++){
				cin>>matrix[i][j];
			}
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				solve(j,i,1,n,m);
			}
		}
		cout<<res<<"\n";
	}