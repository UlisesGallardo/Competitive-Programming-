#include<bits/stdc++.h>
using namespace std;

ifstream fin("visitfj.in");
ofstream fout("visitfj.out"); 

const int N = 100;
int matrix[N][N];
typedef long long int ll;
vector<vector<ll>>distances(N, vector<ll>(N, LLONG_MAX));
vector<vector<bool>>processed(N,vector<bool>(N,false));
int n,t;

int move_x[] = {3,-3,0,0,-2,-1,2,1,-2,-1,2,1,0,1,0,-1};
int move_y[] = {0,0,3,-3,1,2,-1,-2,-1,-2,1,2,1,0,-1,0};
/*
Edge cases:
si está a una distancia de 1 o de 2 del objetivo, entonces
ya se retorna la respuesta, de lo contrario, sigue buscando. 

A excepcion de este caso, siempre se recorre una distancia de 3, entonces
solo es cuestion de sumar el nodo visitado y 3*T. 
*/
int disktra(){
	priority_queue<pair<ll,pair<int,int>>>pq; 
	distances[0][0] = 0;
	pq.push({0,{0,0}});
	
	while(!pq.empty()){
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		
		if (processed[y][x]) continue;
		processed[y][x] = true;
		if(x == n-1 && y == n-1)break;
		
		for(int i=0; i<16; i++){
			int _x = x + move_x[i];
			int _y = y + move_y[i];
			if(_x < n && _x>= 0 && _y < n && _y >= 0){
				if (distances[y][x] + matrix[_y][_x] + t*3 < distances[_y][_x]) {
					distances[_y][_x] = distances[y][x] + matrix[_y][_x] + t*3;
					pq.push({-distances[_y][_x], {_x, _y}});
				}
			}
		}
		int dis = (abs((n-1)-x) + abs((n-1)-y));
		if(dis < 3){
			distances[n-1][n-1] = min(distances[y][x] + dis*t, distances[n-1][n-1]);	
		} 
	}
	return distances[n-1][n-1];
}

int main(){
	//cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	fin>>n>>t;
	for(int i=0; i<n; i++)for(int j=0; j<n; j++)fin>>matrix[i][j];
	fout<<disktra();
}