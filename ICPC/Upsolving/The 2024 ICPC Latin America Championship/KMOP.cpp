#include <bits/stdc++.h>
using namespace std;

char vowels[6] = {'A','E','I','O','U','Y'};
bool is_consonant(char a){
    for(int i=0; i<6; i++)if(vowels[i] == a)return false;
    return true;
}

struct Node{
    int i, l, c, length;
    Node(int i_, int l_, int c_, int length_){
        i = i_;
        l = l_;
        c = c_;
        length = length_;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<string>v(n);
	for(int i=0; i<n; i++) {
        string s,a=""; cin>>s;
        for(int j=0; j<min((int)s.size(),3); j++){
            if(is_consonant(s[j])) a+="0";
            else a+="1";
        }
        v[i] = a;
    }

	queue<Node>q;
    q.push(Node(-1,-1,0,0));
    int ans = 1e9;
    bool visited[n][4][3] = {false};
	while(!q.empty()){
        Node u = q.front();
        visited[u.i][u.l][u.c] = true;
        q.pop();
        if(u.i>=0 && u.l + 1 < min((int)v[u.i].size(),3)){
            int cc = u.c;
            if(v[u.i][u.l+1] == '0') cc++;
            else cc = 0;
            if(cc<=2 && !visited[u.i][u.l+1][cc])
                q.push(Node(u.i, u.l+1, cc, u.length + 1));
        }

        if(u.i + 1 < n){
            int cc = u.c;
            if(v[u.i+1][0] == '0') cc++;
            else cc = 0;
            if(cc<=2 && !visited[u.i+1][0][cc])
                q.push(Node(u.i+1, 0, cc, u.length + 1));
        }

        if(u.i + 1 >=n){
            ans = u.length;
            break;
        }
	}
	if(ans >= 1e9)cout<<"*";
	else cout<<ans;
}
