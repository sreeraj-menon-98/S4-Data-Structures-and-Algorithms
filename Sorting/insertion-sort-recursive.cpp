#include <bits/stdc++.h>
using namespace std;
int insertion_sort(int array[], int n)
{
	if (n<=1)
	{
		return 0;
	}
	insertion_sort(array, n-1);
	int key = array[n-1];
	int i = n-2;
	while(i>-1&&array[i]>key)
	{
		array[i+1] = array[i];
		i=i-1;
	}
	array[i+1] = key;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int array[10000], n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>array[i];
	}
	insertion_sort(array,n);
	for (int i = 0; i < n; ++i)
	{
		cout<<array[i]<<" ";
	}
	return 0;
}
