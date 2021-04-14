#include<iostream>
using namespace std;

int main() {
	int a[10],n,temp;
	cout<<"Enter number of elements"<<endl;
	cin>>n;
	cout<<"Enter Elements"<<endl;
	for(int i=0;i<n;i++)
		   cin>>a[i];
  for(int i=0;i<n;i++) {
  	for(int j=i+1;j<n;j++) {
  		if(a[i] > a[j]) {
  			temp=a[i];
  			a[i]=a[j];
  			a[j]=temp;
  		}
  	}
  }
  cout<<endl<<"sorted : ";
  for(int i=0;i<n;i++) {
  	cout<<endl<<a[i];
  }
	return 0;
}