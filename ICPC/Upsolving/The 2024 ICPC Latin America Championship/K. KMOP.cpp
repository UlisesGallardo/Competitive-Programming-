#include <bits/stdc++.h>
using namespace std;

char vowels[6] = {'A','E','I','O','U','Y'};
bool is_consonant(char a){
    for(int i=0; i<6; i++)if(vowels[i] == a)return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<string>v(n);
	for(int i=0; i<n; i++) cin>>v[i];
    int MAX = 1e8;

    int dp[n+1][4][3];
    for(int i=0; i<n+1; i++)
        for(int j=0; j<4; j++)
            for(int k=0; k<3; k++)
                dp[i][j][k] = MAX;

    for(int j=0; j<4; j++)
        for(int k=0; k<3; k++)
            dp[0][j][k] = 0;

    for(int i=1; i<=n; i++){
        int contiguos = 0;
        for(int j=0; j<min((int)v[i-1].size(), 3); j++){
            if(is_consonant(v[i-1][j]))contiguos++;
            else contiguos = 0;

            if(contiguos == 3)continue;
            for(int k=1; k<4; k++){
                for(int l=0; l<3; l++){
                    if(contiguos + l <= 2){
                        int &a = dp[i-1][k][l];
                        int &b = dp[i][j+1][contiguos+l];
                        int z = a + (j+1);
                        b = min(b,z);
                    }
                }
            }

        }
    }
    int ans = MAX;
    for(int j=0; j<3; j++) ans = min(ans, dp[n][1][j]);
    if(ans==MAX)cout<<"*";
    else cout<<ans;
	return 0;
}
