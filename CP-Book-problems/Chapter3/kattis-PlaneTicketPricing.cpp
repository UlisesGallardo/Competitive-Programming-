
#include <bits/stdc++.h>
using namespace std;

const int W = 52 + 10;
const int K = 100 + 10;
const int N = 300;
int prices[W][K];
int to_sell[W][K];
int memo[W][N];
int n,w;
vector<pair<int,int>>answer;

int dp(int week, int tickets_left){
    if(week>w)return 0;
    if(tickets_left == 0)return 0;
    int &ans = memo[week][tickets_left];
    if(ans != -1)return ans;
    //printf("%d",to_sell[week][0]);

    for(int i = 0; i < to_sell[week][0]; i++){
        int max_revenue = 0;
        if(tickets_left - to_sell[week][i+1] >= 0){
            int j = to_sell[week][i+1];
            ans = max(ans, dp(week+1, tickets_left - j) + j*prices[week][i+1]);
        }else if(tickets_left > 0){
            ans = max(ans, dp(week+1, 0) + tickets_left*prices[week][i+1]);
        }
        if(week == 0){
            answer.push_back({ans, prices[week][i+1]});
        }
    }
    return ans;
}

bool ordenar(pair<int,int> &a, pair<int,int>&b){
    if(a.first>b.first)return true;
    if(a.first==b.first && a.second<b.second)return true;
    return false;
}

int main(){
    memset(memo,-1,sizeof(memo));
    scanf("%d %d",&n,&w);
    for(int i = 0; i <= w; i++){
        scanf("%d", &prices[i][0]);
        to_sell[i][0] = prices[i][0];
        for(int j = 1; j <= prices[i][0]; j++){
            scanf("%d",&prices[i][j]);
        }
        for(int j = 1; j <= prices[i][0]; j++){
            scanf("%d",&to_sell[i][j]);
        }
    }

    dp(0,n);
    sort(answer.begin(), answer.end(), ordenar);
    /*for(int i=0; i<answer.size(); i++){
        printf("%d %d\n",answer[i].first, answer[i].second);
    }*/
    printf("%d\n%d",answer[0].first,answer[0].second);
    return 0;
}
