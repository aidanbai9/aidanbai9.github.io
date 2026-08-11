#include "bits/extc++.h"

using namespace std;

const int maxn=6561;
int n,large=-1;
int arr[maxn][maxn];
void merger(int x, int y, int size, int state){
	if(size==0){
		arr[x][y]=state;
		return;
	}
	int t=1;
	for(int i = 0; i<size; i++)t*=3;
	if(state==1){
		for(int i = x; i<x+t; i+=t/3){
			for(int j = y; j<y+t; j+=t/3){
				if(i==x+t/3&&j==y+t/3)merger(i,j,size-1,0);
				else merger(i,j,size-1,1);
			}
		}
	}
	if(state==0){
		for(int i = x; i<x+t; i++){
			for(int j = y; j<y+t; j++){
				arr[x][y]=0;
			}
		}
	}
	return;
}

int main(){
	cout<<"please wait...\n";
	merger(0,0,8,1);
	while(1){
		cout<<"what size? (1<=size<=8)\n";
		cout<<"program will output 3^size\n";
		cout<<"don't troll with input, program WILL crash\n";
		cin>>n;
		if(n>8)continue;
		//merger(0,0,n,1);
		large=max(large,n);
		int a=1;
		for(int i = 0; i<n; i++)a*=3;
		for(int i = 0; i<a; i++){
			for(int j = 0; j<a; j++){
				if(arr[i][j]==1)cout<<"||";
				else cout<<"  ";
			}
			cout<<"\n";
		}
	}
}
