
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;

	string add_delay(string s, double delay){
		stringstream ss(s); string aux;
		vector<string>values;
		while(getline(ss,aux,':')){
			//cout<<aux<<"\n";
			values.push_back(aux);
		}
		values[2][2] = '.';
		double seg = stod(values[2])+delay;
		int min = stoi(values[1]);
		int hour = stoi(values[0]);
		//cout<<seg<<" - ";
		if(seg>=60.0){
			seg-=60.0;
			min++;
		}
		if(min>=60){
			min-=60;
			hour++;
		}
		string a = to_string(hour),b = to_string(min);
		if(a.size()==1)a = "0"+a;
		if(b.size()==1)b = "0"+b;
		string c1,c2;c1 =c2 = "";
		aux = to_string(seg);
		bool flag = false;
		for(int i=0;i<6; i++){
			if(aux[i]=='.')flag = true;
			else{
				if(!flag) c1+=aux[i];
				else c2+=aux[i];
			}
		}
		while(c1.size()<2)c1 = "0"+c1;
		while(c2.size()<3)c2 = c2+"0";
		return  a+":"+b+":"+c1+","+c2.substr(0,3);
	}
	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		int n; cin>>n;
		double delay;  cin>>delay;
		vector<vector<string>>v;
		cin.ignore();
		while(n--){
			string s; 
			vector<string>sub;
			while(getline(cin,s)){
				if(s.size() == 0)break;
				sub.push_back(s);
			}
			string tiempo = sub[1];
			stringstream ss(tiempo);
			string aux;
			vector<string>tiempo_aux;
			while(getline(ss,aux,' ')){
				//cout<<aux<<"\n";
				tiempo_aux.push_back(aux);
			}
			string new_tiempo = add_delay(tiempo_aux[0], delay)+" --> "+add_delay(tiempo_aux[2], delay);
			
			cout<<sub[0]<<"\n";
			cout<<new_tiempo<<"\n";
			for(int i=2; i<sub.size(); i++)cout<<sub[i]<<"\n";
			cout<<"\n";
			v.push_back(sub);
		}
	}