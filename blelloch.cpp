#include<iostream>
#include<cmath>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main(){
        int n;
	cout << "Enter size of array" << '\n';
        cin >> n;
        int i,j;
	
        int a[n];
	cout << "Enter elememts " << '\n';
        for(i=0;i<n;i++){
                cin >> a[i];
        }
	int newn,k,mediate;

//	Reduction step
	newn=ceil(log2(n));
	
	for(i=1;i<=newn;i++){
		for(j=pow(2,i)-1;j<n;j=j+pow(2,i)){
			k=pow(2,i-1);
			a[j]=a[j]+a[j-k];
			cout  << a[j]  << '\t';
		}
		cout << '\n';
	}

//	Next Step
 	j=n-1;
	a[j]=0;
	for(i=newn;i>0;i--){
		k=pow(2,i-1);
                for(j=n-1;j>=0;j=j-pow(2,i)){
                        cout << a[j] << '\t' << a[j-k]  << '\t' ;
			mediate=a[j];
			a[j]=a[j]+a[j-k];
			a[j-k]=mediate;
		}
		cout << '\n';
	}
	for(i=0;i<n;i++){
		cout << a[i] << '\t';
	}
			
}


