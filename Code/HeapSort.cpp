#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int arr[100005];
int N;

void HeapIns(int index)
{
	int lenth = index;
	while (arr[(index - 1) / 2] < arr[index])
	{
		swap(arr[(index - 1) / 2], arr[index]);
		index = (index - 1) / 2;
	}
}

void Heapi(int lenth)
{
	int index = 0;
	int ileft = 2 * index + 1;
	int imax;
	while (ileft < lenth)
	{
		if (ileft + 1 < lenth && arr[ileft] < arr[ileft + 1])
		{
			imax = ileft + 1;
		}
		else
		{
			imax = ileft;
		}

		if (arr[index] < arr[imax])
		{
			swap(arr[index], arr[imax]);
		}
		else
		{
			break;
		}
		index = imax;
		ileft = 2 * index + 1;
	}
}

int main()
{
	memset(arr, 0x00, sizeof(arr));
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];	
		HeapIns(i);
	}

	for (int i = 0; i < N; ++i)
	{
		swap(arr[0], arr[N - 1 - i]);
		Heapi(N - i - 1);
	}

	for (int i = 0; i < N; ++i)
	{
		cout << arr[i] << " ";
	}

}