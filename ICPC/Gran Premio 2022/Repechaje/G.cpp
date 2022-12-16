
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	ll getVal(ll f,ll c,ll n){
		return (n*f)-(n-c);
	}
	
	string x,axis="x";
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		map<ll,ll>m;
		
		
		int q;
		ll n, a, b; 
		cin>>n>>q;
		
		for(int i=0; i<q; i++){
			cin>>x;
			
			if(x=="q"){
				cin>>a>>b;
				if(n == 1){
					cout<<1<<endl;
				} 
				else{
					//cout<<"q "<<a<<b<<endl;
					if(axis=="a"){
						swap(a,b);
					}else if(axis=="b"){
						b = n-b+1;
					}else if(axis=="c"){
						
						/*
						ll diff = b-1;
						ll aux = n - diff;
						ll distance = abs(aux - a);
						
						a = aux;
						b = b-distance;
						cout<<a<<" "<<b<<"\n";
						*/
						
					}else if(axis=="d"){
						a = n-a+1;
					}
					cout<<getVal(a,b,n)<<endl;
				}
				cin.ignore();
			}else{
				cin>>axis;
			}
		}
		
		return 0;
	}