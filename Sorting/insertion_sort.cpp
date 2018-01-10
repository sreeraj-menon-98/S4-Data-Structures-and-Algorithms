/*	insertion sort in c++
  	input : 1. n = size of input array
  		    2. elements of array
  	output : sorted array
  	worst case : descending order input - O(n^2)
  	best case : already sorted array - O(n)
  	author : visakhsuku	*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int array[100],n,key,i,j;
	cin>>n;
	for (i = 0; i < n; ++i)
	{
		cin>>array[i];
	}
	for (j = 1; j < n; ++j)
	{
		key = array[j];
		i=j-1;
		while(i>-1&&array[i]>key)
		{
			array[i+1] = array[i];
			i=i-1;
		}
		array[i+1] = key;
	}
	for (i = 0; i < n; ++i)
	{
		cout<<array[i]<<'\t';
	}

	return 0;
}
