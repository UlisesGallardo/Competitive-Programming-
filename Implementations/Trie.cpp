
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	const int N = 1e5;
	int trie[N][26], nodos; //Todos los nodos apuntan a la raíz
	int cnt[N]; terminal[N];
	
	void add(string &s){
		int at = 0; //Estoy en la raíz
		for(auto c : s){
			int x = c-'A'; //Número entre 0 y 25
			if(trie[at][x] == 0){ //no existe el siguiente nodo
				trie[at][x] = ++nodos;	
			}
			at = trie[at][x];
			cnt[at]++;
		} 
		terminal[at]++;
	}
	
	bool search(string &s){ //Saber si existe
		int at = 0;
		for(auto c : s){
			int x = c-'A'; 
			if(trie[at][x] == 0){ 
				 return false; //Ya no puedo avanzar
			}
			at = trie[at][x];
		} 
		return true;
	}
	
	void remove(string &s){
		int at = 0;
		for(auto c : s){
			int x = c-'A'; 
			if(trie[at][x] == 0){ 
				 return; //Ya no puedo avanzar
			}
			at = trie[at][x];
			cnt[at]--;
		} 
		terminal[at]--;
	}
	
	/*También se puede hacer de forma recursiva, para saber si existe una palabra: si encuentro todas las letras, entonces me regreso y decremento el cnt para eliminar la palabra*/
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int t; cin>>t;
		while(t--){
			
		}
		
		return 0;
	}