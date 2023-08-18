
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
char values[N];
int memo[N][3][25];
int n, k;
char v[3] = {'P','S','H'};
map<char,int> m;

ifstream fin("hps.in");
ofstream fout("hps.out"); 

bool cow_won(char a, char b){
	if(a == 'H' && b == 'S')return true;
	if(a == 'S' && b == 'P')return true;
	if(a == 'P' && b == 'H')return true;
	return false;
}

int solve(int pos, char current, int used){
	if(pos >= n)return 0;
	if(memo[pos][m[current]][used] !=-1)return memo[pos][m[current]][used];
	
	int wins=0,a=0,b=0;
	if(cow_won(current,values[pos]))wins+=1;
	if(used < k){
		for(int i=0; i<3; i++){
			if(m[current] != i)
				a = max(solve(pos+1,v[i],used+1), a);
		}
	}
	b = solve(pos+1,current,used);
	wins += max(a,b);
	
	return memo[pos][m[current]][used] = wins;
}

int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	m['P'] = 0;
	m['S'] = 1;
	m['H'] = 2;
	fin>>n>>k;
	for(int i=0; i<n; i++)for(int j=0;j<3; j++)for(int f=0;f<25; f++)memo[i][j][f] = -1;
	for(int i=0; i<n; i++)fin>>values[i];
	
	int ans = 0;
	for(int i=0; i<3; i++){
		ans = max(solve(0,v[i],0),ans);
	}
	fout<<ans;

	return 0;
}