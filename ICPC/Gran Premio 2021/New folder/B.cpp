
	#include <bits/stdc++.h>
	using namespace std;
	
	void solve(){
		int n; cin>>n;
		char matrix[n][n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>matrix[i][j];
			}	
		}

		map<int,set<vector<pair<int,int>>>>mapa,mapa1;

		vector<int>m,mm;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(matrix[i][j]=='.'){
					//cuantas x necesito..
					vector<pair<int, int>>row,colum;
					bool entrar = false;
					int a=0;
					int con = 0;
					//if(!visitedA[i][j]){
						
						for(int k=j; k<n;k++){
							if(matrix[i][k]=='O'){
								entrar = true;
								break;
							}else if(matrix[i][k]=='.'){
								row.push_back({i,k});
								con++;
								a++;
							} 
						}
						for(int k=j-1; k>=0;k--){
							if(matrix[i][k]=='O'){
								entrar = true;
								break;
							}else if(matrix[i][k]=='.'){
								row.push_back({i,k});
								con++;
								a++;
							} 
					     }	
						if(!entrar && a!=0){
							sort(row.begin(),row.end());
							if(mapa[a].count(row)==0){
								m.push_back(a);
								mapa[a].insert(row);
							}
						}
						if(entrar)con--;
						a = 0;
						entrar = false;
					
					
						for(int k=i; k<n;k++){
							if(matrix[k][j]=='O'){
								entrar = true;
								break;
							}else if(matrix[k][j]=='.'){
								colum.push_back({k,j});
								con++;
								a++;
							} 
						}
				
						for(int k=i-1; k>=0;k--){
							if(matrix[k][j]=='O'){
								entrar = true;
								break;
							}else if(matrix[k][j]=='.') {
								colum.push_back({k,j});
								a++;
								con++;
							}
						}
					
						if(!entrar && a!=0 && con!=4){
							sort(colum.begin(),colum.end());
							if(mapa[a].count(colum)==0){
								m.push_back(a);
								mapa[a].insert(colum);
							}		
						}
					//}
					
					//if(!visitedB[i][j]){
						row.clear();
						colum.clear();
						
						a = 0;
						entrar = false;
						//cuantas y necesito
						/*____________________________________*/
						con = 0;
						for(int k=j; k<n;k++){
							if(matrix[i][k]=='X'){
								entrar = true;
								break;
							}else if(matrix[i][k]=='.') {
								row.push_back({i,k});
								con++;
								a++;
							}
						}
						for(int k=j-1; k>=0;k--){
							if(matrix[i][k]=='X'){
								entrar = true;
								break;
							}else if(matrix[i][k]=='.'){
								row.push_back({i,k});
								con++;
								a++;
							}
						}
						if(!entrar && a!=0){
							sort(row.begin(),row.end());
							if(mapa1[a].count(row)==0){
								mm.push_back(a);
								mapa1[a].insert(row);
							}
						}
						if(entrar)con--;
						a = 0;
						entrar = false;
						
						
						for(int k=i; k<n;k++){
							if(matrix[k][j]=='X'){
								entrar = true;
								break;
							}else if(matrix[k][j]=='.'){
								colum.push_back({k,j});
								con++;
								a++;
							} 
						}
					
						for(int k=i-1; k>=0;k--){
							if(matrix[k][j]=='X'){
								entrar = true;
								break;
							}else if(matrix[k][j]=='.'){
								colum.push_back({k,j});
								a++;
								con++;
							}
						}
						if(!entrar && a!=0 && con!=4){
							sort(colum.begin(),colum.end());
							if(mapa1[a].count(colum)==0){
								mm.push_back(a);
								mapa1[a].insert(colum);
							}
						}
					//}
				}	
			}
		}
		int con=0,con1=0;
		int minimo,minimo1;
		minimo=minimo1=INT_MAX;
		if((int)m.size()!=0) minimo = *min_element(m.begin(), m.end());
		if((int)mm.size()!=0) minimo1 = *min_element(mm.begin(), mm.end());
			//for(int i=0; i<(int)mm.size(); i++)if(mm[i]==minimo1)con1++;
		
		if(minimo==INT_MAX && minimo1==INT_MAX){
			cout<<"Impossible";
			return;
		}
		if(minimo!=INT_MAX) con = mapa[minimo].size();
		if(minimo1!=INT_MAX)con1 = mapa1[minimo1].size();

		if(minimo == minimo1){
			cout<<minimo<<" "<<max(con,con1);
		}else{
			if(minimo<minimo1)cout<<minimo<<" "<<con;
			else cout<<minimo1<<" "<<con1;
		}
			
	}
	
	
	int main(){
		int t; cin>>t;
		int con = 1;
		while(t--){
			cout<<"Case #"<<con<<": ";
			con++;
			solve();
			cout<<"\n";
		}
	}