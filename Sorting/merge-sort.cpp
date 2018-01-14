/*	merge sort in c++
  	input : 1. n = size of input array
  		    2. elements of array
  	output : sorted array
  	worst case : descending order input - O(nlogn)
  	best case : already sorted array - O(nlogn)
  	author : visakhsuku	*/
#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int p, int q, int r)
{
	int n1,n2,i,j;
	n1=q-p+1;
	n2=r-q;
	int L[n1+1],R[n2+1];
	for(i=0;i<n1;i++)
		L[i]=a[p+i];		//it should be p+i-1 but here index starts from 0
	for(j=0;j<n2;j++)
		R[j]=a[q+j+1];		//it should be q+j but here index starts from 0
	L[n1]=2147483647;		//sentinel = the max value of int
	R[n2]=2147483647;
	i=0;
	j=0;
	for (int k = p; k <=r; ++k)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i=i+1;
		}
		else
		{
			a[k]=R[j];
			j=j+1;
		}
	}
}

void merge_sort(int a[], int p, int r)
{
	int q;
	if (p<r)
	{
		q= (p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
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
	merge_sort(a,0, n-1);
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<'\t';
	}
	return 0;
}