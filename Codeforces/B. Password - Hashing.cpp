
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	struct hashing{
		string s;
		int n,b;
		int mod;
		vector<int>hash,base;
		
		hashing(){}
		
		int v(char c){
			return c - 'a' +1;
		}
		
		void init(string &s, int b, int mod){
			this->s = s; n = s.size(); this->b=b;this->mod = mod;
			hash.resize(n); base.resize(n);
			build();
		}
		
		void build(){
			base[0] = 1;
			for(int i=1; i<n; i++) 
				base[i] = (1ll* b * base[i-1])%mod;
				
			int h = 0;
			for(int i=0; i<n; i++){
				h = (1ll*h*b + v(s[i]))%mod;
				hash[i] = h;
			} 
		}
		
		int string_hashing(){return hash[n-1];}
		int substring_hashing(int l, int r){return (l==0) ? hash[r] : (hash[r] - (1ll*hash[l-1]*base[r-l+1])%mod + mod)%mod;}
		
		
		bool substring_in_string(int tam, int hash_2){
			for(int i=1; i<n-1; i++){
				if(i+tam<n-1){
					if(substring_hashing(i,i+tam) == hash_2){
						return true;
					}	
				}else{
					break;
				}	
			}
			return false;
		}
		
	};
	
	
	
	
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		hashing h;
		
		string s; cin>>s;
		int n; n = s.size();
		h.init(s, 31, 1e9+9);
		
		vector<int>v;
		string prefix="";
		
		for(int i=0; i<n-1; i++){
			prefix.push_back(s[i]);
			int hash_1 = h.substring_hashing(0,i);
			int hash_2 = h.substring_hashing(n-1-i,n-1);
			if(hash_1 == hash_2){
				//cout<<prefix<<"\n";
				v.push_back(i);
			}
		}
		
		if(v.size() == 0){
			cout<<"Just a legend";
			return 0;
		}
		
		int mid,l=0,r=v.size()-1, tam, hash_1;
		
		do{
			mid = l + (r-l)/2;
			//cout<<l<<" "<<mid<<" "<<r<<"\n";

			tam  = v[mid];
			hash_1 = h.substring_hashing(0, tam);
			
			bool found = h.substring_in_string(tam, hash_1);
			if(found && mid == v.size()-1){
				l=r;
				break;
			}
			
			if(mid != v.size()-1){
				
				tam  = v[mid+1];
				hash_1 = h.substring_hashing(0, tam);
				bool found_next = h.substring_in_string(tam, hash_1);
				if(found && !found_next){
					l = mid;
					r=l;
					break;
				}
			}		
					
			if(found){
				l = mid+1;
			}else{
				r = mid-1;
			}
			
		}while(l<r);
				
		cout<< (l==r ? s.substr(0, v[l]+1) : "Just a legend");
		
		return 0;
	}