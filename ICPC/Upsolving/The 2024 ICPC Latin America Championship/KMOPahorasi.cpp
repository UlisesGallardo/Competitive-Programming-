#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1e6+10;
const int INF = 1e8;
vector<string>v(N);
int memo[N][3][3];

char vowels[6] = {'A','E','I','O','U','Y'};

bool is_consonant(char a){
    for(int i=0; i<6; i++)if(vowels[i] == a)return false;
    return true;
}

int dp(int pos, int j, int contiguous){
    if(pos == n)return 0;
    int &r = memo[pos][j][contiguous];
    if(r!=-1)return r;
    r = INF;
    for(int i=0; i<3; i++){
        if(i>=v[pos].size())break;
        if(is_consonant(v[pos][i]))contiguous++;
        else contiguous = 0;
        if(contiguous > 2)break;
        r  = min(r, dp(pos+1,i,contiguous)+(i+1));
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(memo,-1,sizeof(memo));
    cin>>n;
	for(int i=0; i<n; i++)cin>>v[i];
    int ans = dp(0,0,0);
    if(ans>=INF)cout<<"*";
    else cout<<ans;
	return 0;
}
