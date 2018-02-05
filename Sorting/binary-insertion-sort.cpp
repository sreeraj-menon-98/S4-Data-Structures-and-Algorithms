#include <bits/stdc++.h>
using namespace std;
int binary_search(int array[], int key, int low, int high)
{
	if(high<=low)
		return (key  > array[low])?(low + 1)  : low;
	int mid= (low + high)/2;
	if(array[mid]==key)
		return mid;
	else if(array[mid]>key)
		return binary_search(array, key, low, mid-1);
	else return binary_search(array, key, mid +1, high);
}
int insertion_sort(int array[], int n)
{
	int i,j,key,pos;
	for (j = 1; j <n ; ++j)
	{
		key = array[j];
		i= j-1;
		pos = binary_search(array, key, 0, i);
		while(i>=pos)
		{
			array[i+1] = array[i];
			i--;
		}
		array[i+1] = key;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,array[100];
	cin>>n;
	for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}	
		insertion_sort(array, n);
		for (int i = 0; i < n; ++i)
		{
			cout<<array[i]<<" ";
		}
	return 0;
}