
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	//Cada bloque es un back
	//NEUT Cualquier operador neutro.
	//Hacer un lazy en el update de bloques para actualizar, si es parial hacerlo a pata.
	
	int query(int l, int r){
		int bl = l/s;
		int br = r/s;
		
		
		if(bl == br){
			int ans = NEUT;
			
		}else{
			//bloque parcial
			for(int i=l; i<S*(bl+1); i++){
				ans = op(ans,a[i]);
			}
			//bloque al final
			for(int i=S*br; i<=r; i++){
				ans = op(ans,a[i]);
			}
			//bloques enteros [bl+1, br-1]
			for(int i=bl+1; i<br; i++){
				ans = op(ans,bloque[i]);
			}
		}
	}
	
	
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int t; cin>>t;
		while(t--){
			
		}
		
		return 0;
	}