#include <bits/stdc++.h>
using namespace std;
void counting_sort(int a[], int b[], int large, int n)
{
	int c[large+1];
	for (int i = 0; i <=large; ++i)
	{
		c[i]=0;
	}
	for (int j = 0; j < n; ++j)
	{
		c[a[j]] = c[a[j]] + 1;
	}
	for (int i = 1; i <= large ; ++i)
	{
		c[i] = c[i] + c[i-1];
	}
	for (int j=n-1; j>=0; --j)
	{
		b[c[a[j]]-1] = a[j];
		c[a[j]] -= 1; 
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	cin>>a[0];
	int large = a[0];
	for (int i = 1; i < n; ++i)
		{
			cin>>a[i];
			if(large<a[i])
				large = a[i];

		}	
	int b[n];
	for (int i = 0; i < n; ++i)
	{
		b[i]=0;
	}
	counting_sort(a, b, large, n);
	for (int i = 0; i < n; ++i)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}