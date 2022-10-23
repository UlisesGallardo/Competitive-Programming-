
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		int N; cin>>N;
		int cartas[14];
		for(int i = 1;i <=13;i++ ){
			cartas[i] = 4;
		}
		int J1,J2; cin>>J1>>J2;
		int M1,M2; cin>>M1>>M2;
		int sumaJ = 0,sumaM = 0;
		if(J1 <10) sumaJ += J1;
		else sumaJ += 10;
		if(J2 <10) sumaJ += J2;
		else sumaJ += 10;
		if(M1 <10) sumaM += M1;
		else sumaM += 10;
		if(M2 <10) sumaM += M2;
		else sumaM += 10;
		
		cartas[J1]--;
		cartas[J2]--;
		cartas[M1]--;
		cartas[M2]--;
		
		int x;
		while(N--){
			cin>>x;
			if(x < 10) {
				sumaM += x;
				sumaJ += x;
			}
			else {
				sumaM += 10;
				sumaJ += 10;
			}
			cartas[x]--;	
		}
		
		if(sumaM<sumaJ){
			int needed = 24-sumaJ;
			int card = -1;
			for(int i = 1;i<=13;i++){
				int aux = i;
				if(aux>=10)aux = 10;
				if(cartas[i] >0 && sumaJ+aux>=24 ){
					card = aux;
					break;
				}
			}
			if(card!=-1){
				if(sumaM + card<=23)cout<<card<<endl;
				else cout<<-1<<endl;
			} else cout<<-1<<endl;
		}else{
			int needed = 23-sumaM;
			if(needed<=10){
				if(needed<10){
					if(cartas[needed]>0)cout<<needed<<endl;
					else cout<<-1<<endl;
				}else{
					bool flag = false;
					int card = 0;
					
					for(int i=10; i<=13; i++){
						if(cartas[i]>0){
							card = i;
							flag = true;
							break;
						}
					}
					if(flag)cout<<card<<endl;
					else cout<<-1<<endl;
				}
			}else cout<<-1<<endl;
		}
		
		return 0;
	}