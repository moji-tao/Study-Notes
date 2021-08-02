#include <algorithm>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

int arr[100005];
int n;
vector<int> mar(int left, int right);

void quickSort(int left, int right)
{
	if (left >= right - 1)
		return;
	int mid = (rand()%(right - left)) + left;
	swap(arr[mid], arr[right - 1]);

	vector<int> nums = mar(left, right);
	quickSort(left, nums[0]);
	quickSort(nums[1], right);
}

vector<int> mar(int left, int right)
{
	int num = arr[right - 1];
	int index = left;
	int p1 = left;
	int p2 = right;
	while (index < p2)
	{
	    if (arr[index] < num)
			swap(arr[index++], arr[p1++]);
		else if (arr[index] > num)
			swap(arr[index], arr[--p2]);
		else
			++index;
	}
	return { p1,p2 };
}

int main()
{
    srand((unsigned)time(NULL));
	memset(arr, 0x00, sizeof(arr));
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	quickSort(0, n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	return 0;
}