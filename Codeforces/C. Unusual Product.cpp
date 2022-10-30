
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	const int N = 1000+5;
	int matrix[N][N];
	
	int diagonals(int n){
		int sum = 0;
		for(int i=0; i<n; i++) sum+=matrix[i][i];
		return sum;
	}
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);	
		
		int n; cin>>n;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>matrix[i][j];
			}
		}
		int sum = diagonals(n);
		
		int q; cin>>q;
		while(q--){
			int type; cin>>type;
			if(type==1 || type == 2){ //row
				int i; cin>>i;
				i--;
				sum-=matrix[i][i];
				matrix[i][i] = (1-matrix[i][i]);
				sum+=matrix[i][i];
			}else{
				//cout<<"suma"<<sum<<"\n";
				cout<<sum%2;
			}
		}
		
		return 0;
	}