#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mapa[105][105];
int rCasa,cCasa,rMeta,cMeta;
int MinEstampas = 11;
int N,M;
bool visitado[105][105];
bool comprado[11];
int cants[105][105];
int movs[4][4] = {{0,1},{-1,0},{0,-1},{1,0}};

void dfs(int cantEstampas,int r,int c){
	if(cants[r][c] >= cantEstampas || cants[r][c] == 0){
		cants[r][c] = cantEstampas;
		if(cantEstampas > MinEstampas){
		return;
		}
		if(r == rMeta && c == cMeta){
			MinEstampas = min(MinEstampas,cantEstampas);
			cout<<"Llego al final\n";
			return;
		}
		for(int i = 0;i < 4;i++){
			int newr = r+movs[i][0],newc = c+movs[i][1]; 
			if((newr <= N && newr >= 1) && (newc <= M &&  newc >= 1)){ //esta dentro de la matriz
				if(!visitado[newr][newc]){
					if(!comprado[mapa[newr][newc]]){
						visitado[newr][newc] = true;
						comprado[mapa[newr][newc]] = true;
						dfs(cantEstampas+1,newr,newc);
						visitado[newr][newc] = false;
						comprado[mapa[newr][newc]] = false;
					}
					else{
						visitado[newr][newc] = true;
						dfs(cantEstampas,newr,newc);
						visitado[newr][newc] = false;
					}
				}
			}
		}	
	}else return;
}

int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	cin>>N>>M;
	cin>>rCasa>>cCasa;
	cin>>rMeta>>cMeta;
	for(int i = 1; i <= N;i++){
		for(int j = 1; j <= M;j++){
			cin>>mapa[i][j];
		}
	}
	comprado[mapa[rCasa][cCasa]] = true;
	dfs(1,rCasa,cCasa);
	cout<<MinEstampas<<endl;
	return 0;
}