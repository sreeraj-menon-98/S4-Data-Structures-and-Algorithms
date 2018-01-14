/*	3 way merge sort in c++
  	input : 1. n = size of input array
  		    2. elements of array
  	output : sorted array
  	worst case : descending order input - O(nlogn)
  	best case : already sorted array - O(nlogn)
  	author : visakhsuku	*/
#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int p, int mid1, int mid2, int r)
{
	int n1, n2, n3, i, j ,k ,l;
	n1= mid1-p+1;
	n2= mid2-mid1;
	n3= r-mid2;
	int L[n1+1], M[n2+1], R[n3+1];
	for(i=0;i<n1;i++)
		L[i]= a[p+i];
	for(j=0;j<n2;j++)
		M[j]=a[mid1+1+j];
	for(k=0;k<n3;k++)
		R[k]=a[mid2+1+k];
	L[n1]=2147483647;		//sentinel = the max value of int
	M[n2]=2147483647;
	R[n3]=2147483647;
	i=0;
	j=0;
	k=0;
	for(l=p;l<=r;l++)	
	{
		if(L[i]<=M[j])
		{
			if(L[i]<=R[k])
				{
					a[l]=L[i];
					i=i+1;
				}

			else
			{
				a[l]=R[k];
				k=k+1;
			}	
		}
		else
		{
			if(M[j]<=R[k])
			{
				a[l]=M[j];
				j=j+1;
			}
			else
			{
				a[l]=R[k];
				k=k+1;
			}
		}
		
	}
}
void merge_sort(int a[], int p, int r)
{
	int mid1, mid2;
	if(p<r){
		mid1 = p + ((r - p) / 3);			//first middle
        mid2 = p + 2 * ((r - p) / 3) + 1;	//second middle
        merge_sort(a, p, mid1);
        merge_sort(a, mid1+1, mid2);
        merge_sort(a, mid2+1, r);
        merge(a, p, mid1, mid2, r);
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