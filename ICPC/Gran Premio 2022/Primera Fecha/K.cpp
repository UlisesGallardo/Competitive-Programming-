#include<bits/stdc++.h>
using namespace std;

const int N = 5*10e4;

int main(){
	 int n,m; cin>>n>>m;
	 vector<int>coins(m);
	 for(int i=0; i<m; i++)cin>>coins[i];
	 int table[N+1];
	 vector<int>k(n);
	 for(int i=0; i<n; i++)cin>>k[i];
	 
	 memset(table, 0, sizeof(table));
	        
	 table[0] = 1;         
	
	 for(int i=0; i<m; i++){
	 	for(int j=coins[i]; j<=N; j++){
	 		table[j] += table[j-coins[i]];
	 	}
	 }         
 
	 for(int i=0; i<n; i++){
	 		for(int j = k[i]; j<=N; j++){
	 			if(table[j]!=0){
	 				cout<<(j-k[i])<<"\n";
	 				break;
	 			}
	 		}
	 }
}