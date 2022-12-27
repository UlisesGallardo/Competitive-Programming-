
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	/*
	Author: Ulises Gallardo
	1.-Find all unique combinations taking from r to r which are 1022
	2.-Check any combination of stamps, and choose the samllest 
	3.- To do do, to travel from one section to another, the stamp has to be in the combination,
	    if it is, mark each node as visited , this doesn't invalidate any other path 
	*/
	
	void combinationUtil(std::vector<int>& arr, std::vector<int>& combination, std::vector<std::vector<int>>& combinations, int start, int end, int index, int r) { 
	    if (index == r) { 
	        combinations.push_back(combination);
	        return;
	    }
	    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
	        combination[index] = arr[i];
	        combinationUtil(arr, combination, combinations, i+1, end, index+1, r);
	    } 
	} 

	void getCombinations(std::vector<int>& arr, std::vector<std::vector<int>>& combinations, int n, int r) {
	    std::vector<int> combination(r);
	    combinationUtil(arr, combination, combinations, 0, n-1, 0, r); 
	} 
	
	
	
	bool visited[105][105];
	int matrix[105][105];
	bool found;
	
	int X[] = {1,0,-1,0};
	int Y[] = {0,1,0,-1};
	
	int n,m; 
	int r1,c1,r2,c2; 
	
	bool dfs(int x, int y, vector<int>&Stamps){
		visited[y][x] = true;
		
		for(int i=0; i<4; i++){
			int u = x+X[i];
			int v = y+Y[i];
				
			if(v>=1 && v<=n && u>=1 && u<=m && !visited[v][u]){
				auto it = find(Stamps.begin(), Stamps.end(), matrix[v][u]);
				if(it != Stamps.end()){
					if(u == c2 && v == r2){
						return true;
					}
					if(dfs(u,v,Stamps))return true;
				}	
			}
			
 		}
 		
 		return false;
	}
		
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
		set<vector<int>>unique_combinations;
		
		
		for(int i=1; i<10; i++){
			 vector<std::vector<int>> combinations;
		    int r = i; 
		    int n = arr.size();
		    getCombinations(arr, combinations, n, r);
		    for(std::vector<int>& combination : combinations) {
		    	sort(combination.begin(),combination.end());
		    	unique_combinations.insert(combination);
		    }
		}

		cin>>n>>m;
		cin>>r1>>c1>>r2>>c2;
		
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				cin>>matrix[i][j];
				
		if(n==1&&m==1 || r1==r2 && c1==c2){
			cout<<1<<endl;
			return 0;
		}
		
		int ans = 10;
		for(auto Stamps : unique_combinations){
			memset(visited, false, sizeof(visited));
			
			if(find(Stamps.begin(), Stamps.end(),matrix[r1][c1])==Stamps.end())continue;
			
			bool res = dfs(c1,r1,Stamps);
			if(res){
				int tam = Stamps.size();
				//for(auto a : Stamps)cout<<a<<" ";
				//cout<<"\n";
				ans = min(ans,tam);
			}
		}
		
		cout<<ans;
	   
		return 0;
	}