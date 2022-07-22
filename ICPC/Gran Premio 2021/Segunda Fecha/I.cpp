
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	int main(){
			int t; cin>>t;
			
			while(t--){
				string s; cin>>s;
				int con=0;
				stack<int>pila;
				for(int i=0; i<s.size(); i++){
					pila.push(s[i]-'0');
				}
				while(pila.size()>1){
					int a = pila.top();
					pila.pop();
					int b = pila.top();
					pila.pop();
					int res = a*b;
					if(a*b>9){
						pila.push((a*b)%10);
						pila.push((a*b)/10);
					}else{
						pila.push(a*b);
					}
					con++;
				}
				cout<<con<<"\n";
		}
		
	}