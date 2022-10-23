
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		ll n,s; cin>>n>>s;
		vector<ll>v(n);
		ll suma = 0;
		for(int i=0; i<n; i++){cin>>v[i];suma+=v[i];}
		
		for(int i=0; i<n; i++){
			
			ll maximo = min(s-(n-1), v[i]);
			ll minimo = 0;
			ll newS = suma - v[i];
			//cout<<"suma"<<newS<<" \n";
			if(newS<s){
				minimo = s-newS;
			}else{
				minimo = 1;
			}
			int valid = abs(maximo-minimo)+1;
			//cout<<maximo<<" "<<minimo<<" \n";
			cout<<v[i]-valid<<" ";
		}
		
		return 0;
	}