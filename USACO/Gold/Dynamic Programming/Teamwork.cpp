
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
const int K = 1e3+5;
int skill[N];
int n,k;
int memo[N][K];

const int A = 1e6;
const int B = 4e2;
int mem[A][B];

ifstream fin("teamwork.in");
ofstream fout("teamwork.out"); 

int solve(int pos, int max_value, int amount){
	if(pos>=n)return amount*max_value;
	if(memo[pos][amount]!=-1)return memo[pos][amount];
	int ans = 0, a=0, b=0;
	if(amount+1 <= k)a = solve(pos+1, max(skill[pos],max_value), amount+1); //agregar integrante
	b = solve(pos+1, skill[pos], 1) + amount*max_value;    				    //crear nuevo grupo
	ans = max(a,b);
	
	return memo[pos][amount] = ans;
}

int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	memset(memo,-1,sizeof(memo));
	cin>>n>>k;
	for(int i=0; i<n; i++)cin>>skill[i];
	cout<<solve(0,0,0);
	return 0;
}