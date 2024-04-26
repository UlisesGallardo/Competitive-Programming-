#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>v(2*n),a,neg;
    for(int i=0; i<2*n; i++){
        cin>>v[i];
        if(v[i]<0)neg.push_back(v[i]);
    }

    deque<int>s,g;

    for(int i=0; i<2*n; i++){
        if(v[i]>0) a.push_back(v[i]);
        else{
            while(a.size() > 0 && a.back() != abs(v[i])){
                g.push_front(a.back());
                a.pop_back();
            }
            if(a.size() > 0 && a.back() == abs(v[i])){
                s.push_front(a.back());
                a.pop_back();
            }
        }
    }

    int i=0;
    string ans = "";
    while(!s.empty() || !g.empty()){
        int search_ = abs(neg[i]);
        bool entrar = false;
        if(!s.empty() && s.back() == search_){
            ans+="S";
            s.pop_back();
            entrar = true;
        }
        if(!g.empty() && g.back() == search_){
            ans+="G";
            g.pop_back();
            entrar = true;
        }

        if(!entrar)break;
        i++;
    }
    if(ans.size() == n)cout<<ans;
    else cout<<"*";
}
