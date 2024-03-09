
#include <bits/stdc++.h>
using namespace std;

const int M = 200;
const int C = 20;
const int K = 20+1;

int prices[C][K];
int memo[C][M];
int m, c;
int dp(int g, int money){
    if(money < 0)return -1e9;
    if(g==c)return m-money;
    if(memo[g][money] != -1)return memo[g][money];
    int ans = -1e9;
    for(int i=0; i<prices[g][0]; i++){
        ans = max(ans, dp(g+1, money - prices[g][i+1]));
    }
    return memo[g][money] = ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(memo,-1,sizeof(memo));
        scanf("%d %d",&m,&c);

        for(int i = 0; i < c; i++){
            scanf("%d",&prices[i][0]);
            for(int j = 0; j < prices[i][0]; j++){
                scanf("%d",&prices[i][j+1]);
            }
        }
        int ans = dp(0,m);
        if(ans < 0)printf("no solution\n");
        else printf("%d\n",ans);
    }
    return 0;
}
