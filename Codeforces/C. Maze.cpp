	
		#include <bits/stdc++.h>
		using namespace std;
		typedef long long int ll;
		
		const int N = 500+1;
		char maze[N][N];
		bool visited[N][N];
		int n,m,k;
		int X[] = {1,0,-1,0};
		int Y[] = {0,1,0,-1};
		
		bool dfs(int x, int y){
			visited[y][x] = true;
			for(int i=0; i<4; i++){
				int u = x+X[i];
				int v = y+Y[i];
				if(u>=0 && u<m && v>=0 && v<n && maze[v][u] == '.' && !visited[v][u]){
					if(dfs(u,v))return true;
				}
			}
			
			maze[y][x] = 'X';
			k--;
			if(k==0)return true;
			return false;
		}
		
		int main(){
			cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
			memset(visited, false, sizeof(visited));
			cin>>n>>m>>k;
			int x, y; 
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					cin>>maze[i][j];
					if(maze[i][j]=='.'){x=j;y=i;}
				}
			}
			if(k!=0)dfs(x,y);
			
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					cout<<maze[i][j];
				}
				cout<<"\n";
			}
				
			return 0;
		}