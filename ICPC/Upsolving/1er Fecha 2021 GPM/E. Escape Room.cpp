
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;

	char matrix[1001][1001];
	int paths[1001][1001];
	bool visited[1001][1001];
	int X[] = {-1,0,1, 0};
	int Y[] = {0 ,1,0,-1};	
	//L,D,R,U
	
	void bfs(int x, int y, int n, int m){
		if(x==-1&&y==-1)return;
		queue<int>q;
		q.push(x);
		q.push(y);
		visited[y][x] = true;
		paths[y][x] = 0;
		
		while(!q.empty()){
			int u = q.front();q.pop();
			int v = q.front();q.pop();
			for(int i=0; i<4; i++){
				int x1 = X[i]+u;
				int y1 = Y[i]+v;
				if(x1>=0 && x1<m && y1>=0 && y1<n && !visited[y1][x1] && matrix[y1][x1]!='#' && matrix[y1][x1]!='X'){
					paths[y1][x1] = paths[v][u] +1;
					visited[y1][x1] = true;
					q.push(x1);
					q.push(y1);
				}
			}
		}
	}
	
	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		
		int n,m; cin>>n>>m;
		int x=-1,y=-1;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>matrix[i][j];
				if(matrix[i][j] == 'E'){
					x = j;
					y = i;
				}
			}
		}
		
		memset(visited,false, sizeof(visited));
		memset(paths,1e5,sizeof(paths));
		bfs(x,y,n,m);
		
		int q; cin>>q;
		while(q--){
			cin>>y>>x;
			x--;
			y--;
			if(matrix[y][x] == '#')cout<<"W";
			else if(matrix[y][x] == 'X')cout<<"X";
			else if(matrix[y][x] == 'E')cout<<"E";
			else if(!visited[y][x])cout<<"?";
			else{
				char dir;
				vector<pair<int,int>>ans;
				for(int i=0; i<4; i++){
					int x1 = X[i]+x;
					int y1 = Y[i]+y;
					if(x1>=0 && x1<m && y1>=0 && y1<n && matrix[y1][x1]!='#' && matrix[y1][x1]!='X'){
						ans.push_back({paths[y1][x1],i});
					}
				}
				
				sort(ans.begin(),ans.end());
				//for(auto a:ans)cout<<a.first<<" "<<a.second<<"\n";
				//cout<<"\n";
				int i = ans[0].second;
				if(i==0)dir = 'L';
				if(i==1)dir = 'D';
				if(i==2)dir = 'R';
				if(i==3)dir = 'U';
		
				cout<<dir;
			} 
			cout<<"\n";
		}
	}