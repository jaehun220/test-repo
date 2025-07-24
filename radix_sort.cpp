#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int N, i, m = 0, exp = 1;
	cin>>N;
	vector<int> arr(N);
	vector<int> temp(N);
	for (int i = 0; i < N; i++)
	{	
		cin>>arr[i];
		if (arr[i] > m)
			m = arr[i];		
	}
	while (m / exp > 0)
	{
		vector<int> bucket(10, 0);

		for (int i = 0; i < N; i++)
			bucket[(arr[i]/exp)%10]++;

		for (int i = 1; i < 10; i++)
			bucket[i] += bucket[i-1]; 

		for (int i =  N - 1; i >= 0; i--)
			temp[--bucket[(arr[i]/exp)%10]] = arr[i];

		for (int i = 0; i < N; i++)
			arr[i] = temp[i];

		exp *= 10;
	}
	for (int i = 0; i < N; i++)
		cout<<arr[i]<<endl;
	return 0;
}
