
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	/**/
	
	vector<int> z_function(string s) {
	    int n = (int) s.length();
	    vector<int> z(n);
	    for (int i = 1, l = 0, r = 0; i < n; ++i) {
	        if (i <= r)
	            z[i] = min (r - i + 1, z[i - l]);
	        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
	            ++z[i];
	        if (i + z[i] - 1 > r)
	            l = i, r = i + z[i] - 1;
	    }
	    return z;
	}


	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		string s; cin>>s;
		vector<int>z = z_function(s);
		/*	
		for(auto a:z){
			cout<<a<<" ";
		}
		cout<<"\n";
		*/
		vector<int>sum_mayores((int)s.size(),0); 
		
		for(auto a:z) sum_mayores[a]++;
		/*
		for(auto a:sum_mayores){
			cout<<a<<" ";
		}
		cout<<"\n";*/
		
		for(int i=sum_mayores.size()-2; i>=0; i--){
			sum_mayores[i]+=sum_mayores[i+1];
		}
	
		
		vector<pair<int,int>>ans;
		for(int i=z.size()-1; i>=0; i--){
			int tam = s.size()-i;
			//cout<<i<<" "<<tam<<" -- "<< z[i]<<" "<<sum_mayores[tam]<<"\n";
			if(z[i] == tam){
				ans.push_back({tam, sum_mayores[tam]});
				//cout<<tam<<" "<<sum_mayores[i]<<"\n";
			}
		}
		cout<<ans.size()+1<<"\n";
		for(auto a:ans){
			cout<<a.first<<" "<<a.second+1<<"\n";
		}
		
		cout<<s.size()<<" "<<1;
		
		return 0;
	}