
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int n; cin>>n;
		unordered_map<int,vector<int>>m;
		unordered_set<int>visited;
		vector<int>v(n);	
		
		for(int i=0; i<n; i++){
			cin>>v[i];
			m[v[i]].push_back(i);
		}
		
		int res = 0;
		for(int i=0; i<n; i++){
			if(visited.count(i)==0){
				res++;
				int value = v[i]-1;
				int pos=i;
				//cout<<"entrando"<<v[i]<<"\n";
				m[v[i]].erase(find(m[v[i]].begin(),m[v[i]].end(),i));
				
				while(true){
					if(value==0)break;
					vector<int>aux = m[value];
					//cout<<"arreglo->";
					//for(auto a:aux)cout<<a<<" ";
					//cout<<"\n";
					auto it = upper_bound(aux.begin(),aux.end(),pos);
					//cout<<*it<<" ";
					if(it!=aux.end() && (*it)>pos){
						//cout<<"found "<<*it;
						m[value].erase(find(m[value].begin(), m[value].end(),*it));
						visited.insert(*it);
						pos = (*it);
						value--;
					}else{
						break;
					}
				}
				//cout<<"\n";
			}
		}
		cout<<res<<endl;
		return 0;
	}