#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;

struct Student{
	ll id;
	vector<ll>request; 
	vector<ll>has;
	ll add=0, remove=0;
	vector<ll>changes;
	
	friend bool operator<(const Student &a, const Student &b){
		if(a.id<b.id) return true;
		return false;
	}
};
 
int main()
{
	ios_base::sync_with_stdio(false);
	
	ll n,m; cin>>n>>m;
	unordered_map<ll, Student>v;
	for(int i=0; i<n; i++){	
		ll a,b; cin>>a>>b;
		v[a].id = a;
		for(int j=0; j<b; j++){
			ll x; cin>>x;
			v[a].request.emplace_back(x);
		}
	}
	vector<ll>has;
	for(int j=0; j<m; j++){
		ll a,b; cin>>a>>b;
		v[a].id = a;
		has = v[a].has;
		for(int i=0; i<b; i++){
			ll x; cin>>x;
			has.emplace_back(x);
		}
		v[a].has = has;
	}
	vector<Student>aux;
	ll con = 0;
	
	vector<ll>add,remove, changes;
	
	for(auto a: v){
		ll id = a.first;
		Student s = a.second;
		has = s.has;
		
		std::vector<ll>::iterator it;
		
		for(int i=0; i<s.request.size(); i++){
			it = std::find (has.begin(), has.end(), s.request[i]);
			if(it == has.end())add.emplace_back(s.request[i]);
			else has.erase(it);
		}
		for(int i=0; i<s.has.size(); i++){
			it = std::find (s.request.begin(), s.request.end(),s.has[i]);
			if(it == s.request.end())remove.emplace_back(-1*s.has[i]);
			else s.request.erase(it);
		}
		sort(add.begin(),add.end());
		sort(remove.begin(),remove.end(), greater<ll>());
		
		for(auto a:remove){
			s.changes.emplace_back(a);
		}
		for(auto a:add){
			s.changes.emplace_back(a);
		}
		s.add = add.size();
		s.remove = remove.size();
		if(s.changes.size() == 0)con++; 
		
		aux.emplace_back(s);
		add.clear();
		remove.clear();
	}
	
	sort(aux.begin(),aux.end());
	
	if(con == aux.size()){
		cout<<"GREAT WORK! NO MISTAKES FOUND!"<<endl;
		return 0;
	}
	ll mistakes = 0, r=0,missed=0;
	for(auto s:aux){
		if(s.changes.size() >0){
			mistakes++;
			r += s.remove;
			missed += s.add;
			cout<<s.id<<" ";
			
			for(int i=0; i<s.changes.size(); i++){
				if(s.changes[i]>0)cout<<"+";
				cout<<s.changes[i];
				if(i < s.changes.size()-1) cout<<" ";
			}
			cout<<endl;
		}
	}
	cout<<"MISTAKES IN "<<mistakes<<" STUDENTS: "<<r<<" NOT REQUESTED, "<<missed<< " MISSED"<<endl;
}