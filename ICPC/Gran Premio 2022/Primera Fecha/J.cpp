
	#include<bits/stdc++.h>
	using namespace std;
	
	const int N =1e4;
	
	bool ordenar(vector<int>&a, vector<int>&b){
		return a.size()<b.size();
	}
	
	int main(){
		int n,m; cin>>n>>m;
		vector<vector<int>>v(n);
		for(int i=0; i<n; i++){
			int x; cin>>x;
			for(int j=0; j<x; j++){
				int xx; cin>>xx;
				v[i].push_back(xx);
			}
			sort(v[i].begin(),v[i].end());
		}
		bool visited[m+1];
		memset(visited, false, sizeof(visited));
		sort(v.begin(),v.end(), ordenar);
		
		/*
		for(auto a:v){
			cout<<"xd";
			for(auto x:a)cout<<x<<" ";
			cout<<"\n";
		}*/
		
		for(int i=0; i<n; i++){
			int k = v[i].size();
			for(int j=0; j<k; j++){
				if(!visited[v[i][j]]){
					visited[v[i][j]] = true;
					break;
				}
			}
		}
		//for (auto a:visited)cout<<a<<" ";
		int res = 0;
		for(int i=1; i<=m; i++)if(visited[i])res++;
		cout<<m-res;
	}