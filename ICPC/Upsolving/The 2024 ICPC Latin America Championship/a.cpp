#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1e6+10;
vector<string>v(N);
int memo[N][3][2];

char vowels[6] = {'A','E','I','O','U','Y'};

bool is_consonant(char a){
    for(int i=0; i<6; i++)if(vowels[i] == a)return false;
    return true;
}

int dp(int pos, int pos_s, int contiguous){
    if(pos == n)return 0;
    if(memo[pos][pos_s][contiguous]!=-1)return memo[pos][pos_s][contiguous];
    if(contiguous > 2)return memo[pos][pos_s][contiguous] = 1e8;
    int ans = 1e8;
    int aux = contiguous;
    for(int i=0; i<min((int)v[pos].size(), 3); i++){
        if(is_consonant(v[pos][i]))aux++;
        else aux = 0;
        ans  = min(ans, dp(pos+1,i,aux)+(i+1));
    }
    return memo[pos][pos_s][contiguous] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(memo,-1,sizeof(memo));
    cin>>n;
	for(int i=0; i<n; i++)cin>>v[i];
    int ans = dp(0,0,0);
    if(ans>=1e8)cout<<"*";
    else cout<<ans;
	return 0;
}
