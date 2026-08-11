#include "bits/extc++.h"

using namespace std;

int a[4];

int main(){
	cout<<"WELCOME TO THE ALL 10 SOLVER BY AIDAN BAI\n";
	cout<<"note that order of operations are not considered\n";
	cout<<"enter 4 numbers\n";
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	bool only1;
	cout<<"do you want only one output for each number?\n1 or 0\n";
	cin>>only1;
	for(int want=1; want<=10; want++){
		bool found=0;
	do{
		for(int i = 0; i<4; i++){
			for(int j = 0; j<4; j++){
			    for(int k = 0; k<4; k++){
                    double ans=a[0];
                    string anss=to_string(a[0]);
                    if(i==0){
                        ans+=a[1];
                        anss+="+";
                    }
                    if(i==1){
                        ans-=a[1];
                        anss+="-";
                    }
                    if(i==2){
                        ans*=a[1];
                        anss+="*";
                    }
                    if(i==3){
                        ans/=a[1];
                        anss+="/";
                    }
                    anss+=to_string(a[1]);
                    if(j==0){
                        ans+=a[2];
                        anss+="+";
                    }
                    if(j==1){
                        ans-=a[2];
                        anss+="-";
                    }
                    if(j==2){
                        ans*=a[2];
                        anss+="*";
                    }
                    if(j==3){
                        ans/=a[2];
                        anss+="/";
                    }
                    anss+=to_string(a[2]);
                    if(k==0){
                        ans+=a[3];
                        anss+="+";
                    }
                    if(k==1){
                        ans-=a[3];
                        anss+="-";
                    }
                    if(k==2){
                        ans*=a[3];
                        anss+="*";
                    }
                    if(k==3){
                        ans/=a[3];
                        anss+="/";
                    }
                    anss+=to_string(a[3]);
                    if(ans==want){
                        cout<<want<<"\n";
	                    cout<<anss<<"\n";
                        found=1;
						if(only1&&found){
							break;
						}
                    }
					if(only1&&found)break;
			    }
				if(only1&&found)break;
			}
			if(only1&&found)break;
		}
	}while(next_permutation(a,a+4));
	}
}
