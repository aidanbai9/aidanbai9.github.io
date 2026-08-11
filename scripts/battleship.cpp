#include "bits/extc++.h"

using namespace std;

int main(){
	mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());
    auto rint = [&](long l, long r) -> long {
        return cowng()%(r-l+1)+l;
    };
	cout<<"welcome to the game of battleship!\n";
	int n=5;
	char arr[5][5];
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			arr[i][j]='#';
		}
	}
	auto outarr = [&]() -> void {
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				cout<<arr[i][j];
			}
			cout<<"\n";
		}
	};
	bool ship[5][5]{};
	auto place = [&](int x, int y) -> void {
		int ori=rint(0,1);
		if(ori)swap(x,y);
		int posx=0,posy=0;
		bool flag=0;
		do{
			flag=0;
			posx=rint(0,n-x),posy=rint(0,n-y);
			for(int i = posx; i<posx+x; i++){
				for(int j = posy; j<posy+y; j++){
    				if(ship[i][j])flag=1;
				}
			}
		}while(flag);
		for(int i = posx; i<posx+x; i++){
			for(int j = posy; j<posy+y; j++){
				ship[i][j]=1;	
			}
		}
	};
	place(1,5);
	place(1,4);
	place(1,3);
	outarr();
	cout<<"put ur guesses!\n";
	auto done = [&]() -> bool {
		bool pass=1;
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				if(ship[i][j] && arr[i][j]!='1')pass=0;	
			}
		}
		return pass;
	};
	while(!done()){
		int a,b;
		cin>>a>>b;
		if(a<0 || a>=5 || b<0 || b>=5 || arr[a][b]!='#'){
			cout<<"invalid\n";
			continue;
		}
		if(ship[a][b]){
			cout<<"righteyo\n";
			arr[a][b]='1';	
		}else{
			cout<<"try again\n";
			arr[a][b]='0';
		}
		outarr();
	}
	cout<<"nicely done!\n";
}
