
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	struct Fabric{
		string c;
		int d, u; 
		
		friend bool operator==(const Fabric& a, const Fabric& b)
		{
		    if(a.c == b.c && a.d ==b.d && a.u == b.u)return true;
		    return false;
		}
	};
	
	bool ordenar_by_color(const Fabric &a, const Fabric &b){
		if(a.c < b.c){ return true;
		}else if(a.c == b.c){
			if(a.u<b.u)return true;
		}
		return false;
	}
	
	bool ordenar_by_durability(const Fabric &a, const Fabric &b){
		if(a.d < b.d){ return true;
		}else if(a.d == b.d){
			if(a.u<b.u)return true;
		}
		return false;
	}
	
	void solve(){
		int n; cin>>n;
		vector<Fabric>v(n),aux;
		for(int i=0; i<n; i++){
			cin>>v[i].c;
			cin>>v[i].d;
			cin>>v[i].u;
		}
		aux = v;
		sort(v.begin(),v.end(),ordenar_by_color);
		sort(aux.begin(),aux.end(),ordenar_by_durability);
		int res=0;
		for(int i=0;i<n; i++){
			if(v[i] == aux[i])res++;
		}
		cout<<res;
	}
	
	int main(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int t; cin>>t;
		int t_case = 1;
		while(t--){
			cout<<"Case #"<<t_case<<": ";
			solve();
			cout<<"\n";
			t_case++;
		}
	}