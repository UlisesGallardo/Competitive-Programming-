#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c; cin>>a>>b>>c;
    bool res = true;
    for(int i=0; i<a; i++){
        string s,ss; cin>>s>>ss;
        int sum = 0, sum2 = 0;
        for(int j=0; j<ss.size(); j++)
            if(ss[j] == '*')sum+=1;

        for(int j=0; j<s.size(); j++)
            if(s[j] == '*')sum2+=1;
        if(sum!=0 && sum2 < b)res = false;
    }
    if(!res)cout<<"N";
    else cout<<"Y";
}
