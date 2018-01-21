/*	quick sort in c++
  	input : 1. n = size of input array
  		    2. elements of array
  	output : sorted array
  	worst case : O(n^2)
  	best case : O(nlogn)
  	author : visakhsuku	*/
#include <bits/stdc++.h>
using namespace std;
int partition(int a[], int p, int r)
{
	int temp,i,j,x;
	x=a[r];
	i=p-1;
	for (j = p; j<r; j++)
	{
		if (a[j]<=x)
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;

	return i+1;
}
void quick_sort(int a[], int p, int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	quick_sort(a,0,n-1);
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<' ';
	}
	return 0;
}