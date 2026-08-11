#include "bits/extc++.h"

using namespace std;

string next(string a){
	string b=a;
	for(int i = b.size()-1; i>=0; i--){
		if(b[i]=='1')b[i]='0';
		else {
			b[i]='1';
			break;
		}
	}
	return b;
}

int main(){
	while(1){
		cout<<"how many digits/up to what number\n";
		cout<<"don't troll with input\n";
		string s="";
		int n,m;
		cin>>n>>m;
		for(int i = 0; i<n; i++){
			s+="0";
		}
		for(int i = 0; i<m; i++){
			cout<<s<<"\n";
			s=next(s);
		}
	}
}
