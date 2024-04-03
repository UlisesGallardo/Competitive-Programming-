
	#include <bits/stdc++.h>
	using namespace std;
	typedef unsigned long long int ll;
	
	struct Node{
		int duplicates = 0;
		Node* letters[10];
		Node() { 
        	for(int i=0; i<10; ++i) letters[i] = NULL;
        }
	};
	
	struct Trie{
		Node *root;		
		Trie(){
			root = new Node();
		}
		
		bool exists(Node* actual, int c){
			return actual->letters[c]!=NULL;
		}
		
		void insertWord(const string & word){
			Node * current = root;
			for(auto & c: word){
				if(!exists(current, c-'0')){
					current->letters[c-'0'] = new Node();
				}
				current = current->letters[c-'0'];
				current->duplicates++;
			}
		}

		ll get_max(string & s){
			Node* current = root;
			
			ll ans = 0;
			int iter=0;
			int value, v;
			bool flag;
			for(auto a: s){
				if(iter>0) ans*=10;
				iter++;
				v = a-'0';
				value = 9-v; 
				
				flag = false;
				for(int i=value; i>=0; i--){					
					if(exists(current, i) && current->letters[i]->duplicates > 0){
						current = current->letters[i];
						flag = true;
						ans+=((i+v)%10);
						break;
					}
				}
				if(!flag){
					for(int i=9;  i>=value+1 ; i--){
						if(exists(current, i) && current->letters[i]->duplicates > 0){
							current = current->letters[i];
							ans+=((i+v)%10);
							break;
						}
					}
				}
			}
			return ans;
		}
		
		ll get_min(string &s){
			Node* current = root;
			
			ll ans = 0;
			int iter=0;
			int value, v;
			bool flag;
			for(auto a: s){
				if(iter>0) ans*=10;
				iter++;
				v = a-'0';
				
			    value = 10-v; 
			    flag = false;
				
				for(int i=value;  i<=9 ; i++){
					if(exists(current, i) && current->letters[i]->duplicates > 0){
						current = current->letters[i];
						ans+=((i+v)%10);
						flag = true;
						break;
					}
				}
					
				if(!flag){
					for(int i=0; i<value; i++){
						if(exists(current, i) && current->letters[i]->duplicates > 0){
							current = current->letters[i];
							ans+=((i+v)%10);
							break;
						}
					}
				}
			}
			return ans;
		}

		
	};
	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(0);
		int n; cin>>n;
		Trie t;
		pair<ll,ll>ans = {1999999999999999999,0};
		
		for(int i=0;i<n; i++){
			string s; cin>>s;
			int j=s.size();
			while(j<20){s = "0"+s;j++;}
			
			if(i>0){
				ll maximo = t.get_max(s); 			
				ll minimo = t.get_min(s);
				if(maximo > ans.second)ans.second = maximo;
				if(minimo < ans.first)ans.first = minimo;
			}
			
			t.insertWord(s);
		}
		
		cout<<ans.first<<" "<<ans.second;
		return 0;
	}