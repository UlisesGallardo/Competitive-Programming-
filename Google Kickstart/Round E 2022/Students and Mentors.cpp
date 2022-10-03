	#include<bits/stdc++.h>
	using namespace std;
	typedef long long ll;
	
	int main(){
		
		int t; cin>>t;
		int t_case = 1;
		while(t--){
			int n; cin>>n;
			vector<ll>v(n);
			multiset<ll>s;
			for(int i=0; i<n; i++){
				cin>>v[i];
				s.insert(v[i]);
			}
			
			cout<<"Case #"<<t_case<<": ";
			for(int i=0; i<n; i++){
				s.erase(s.lower_bound(v[i]));
				auto j = s.lower_bound(2*v[i]);
				if(j==s.end())j--;
				ll valor = *j;
				if(valor<=2*v[i]){
					cout<<valor;
				}else{
					bool flag = true;
					while(j!=s.begin()){
						if((*j)<=2*v[i]){
							cout<<*j;
							flag = false;
							break;
						}
						j--;
						if(j == s.begin()){
							if((*j)<=2*v[i]){
								cout<<*j;
								flag = false;
								break;
							}
						}
					}
					if(flag)cout<<-1;
				} 
				s.insert(v[i]);
				cout<<" ";
			}
			
			
			cout<<"\n";
			t_case++;
		}
		
	}