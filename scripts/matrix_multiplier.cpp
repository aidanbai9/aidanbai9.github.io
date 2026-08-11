#include "bits/extc++.h"

using namespace std;

int main(){
	cout<<"welcome to matrix multiplication, by AIDAN BAI\n";
	while(1){
		cout<<"please don't troll with input, program WILL crash\n";
		cout<<"\nwhat are the dimensions of the 'first' matrix?\n";
		cout<<"please have positive integers less than 500 plez\n";
		int a,b;
		cin>>a>>b;
		cout<<"what are the dimensions of the 'second' matrix?\n";
		cout<<"please have positive integers less than 500 plez\n";
		int c,d;
		cin>>c>>d;
		if(a<0 || b<0 || c<0 || d<0){
			cout<<"bruh, STAHP THROWING\n";
			continue;
		}
		if(a>1000 || b>1000 || c>1000 || d>1000){
			cout<<"I'M NOT STUPID, STOP TRYING TO CRASH ME\n";
			continue;
		}
		if(b!=c){
			cout<<"error, can't be multiplied\n";
			continue;
		}
		cout<<"input first matrix (row by row plez)\n";
		cout<<"numbers less than 1e6 plez\n";
		double matrix1[a][b];
		double matrix2[c][d];
		for(int i = 0; i<a; i++){
			for(int j = 0; j<b; j++){
				cin>>matrix1[i][j];
			}
		}
		cout<<"input second matrix (row by row plez)\n";
		cout<<"numbers less than 1e6 plez\n";
		for(int i = 0; i<c; i++){
			for(int j = 0; j<d; j++){
				cin>>matrix2[i][j];
			}
		}
		double ans[a][d];
		memset(ans,0,sizeof(ans));
		for(int i = 0; i<a; i++){
			for(int j = 0; j<d; j++){
				for(int k = 0; k<b; k++){
					ans[i][j]+=matrix1[i][k]*matrix2[k][j];
				}
			}
		}
		cout<<"result is:\n";
		for(int i = 0; i<a; i++){
			for(int j = 0; j<d; j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
}
