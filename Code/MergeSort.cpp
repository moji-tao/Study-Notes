#include <algorithm>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

void sort(vector<int>& arr, int left, int right)
{
	if(left == right)
		return;
	sort(arr, left, left+(right-left)/2);
	sort(arr, left+(right-left)/2+1, right);
	marge(arr, left, left+(right-left)/2, right);

}

void marge(vector<int>& arr, int left, int mid, int right)
{
	vector<int> tmp(right-left+1);
	int i=0;
	int l=left;
	int m=mid+1;
	int r=right;
	while(l<=mid && m<=right)
	{
		tmp[i++] = arr[l]<arr[m]? arr[l++] : arr[m++];
	}
	while(l<=mid)
	{
		tmp[i++] = arr[l++];
	}
	while(m<=right)
	{
		tmp[i++] = arr[m++];
	}
	for(int k=0;k<tmp.size();++k)
	{
		arr[left++] = tmp[k];
	}
}

vector<int> sortArray(vector<int>& nums) 
{
	sort(nums, 0, nums.size()-1);
	return nums;
}

int main()
{
	int size;
	cin>>size;

	vector<int> nums(size);
	for(int i=0; i < size; ++i)
	{
		cin >> nums[i];
	}
	sortArray(nums);
	for(int i = 0; i < size; ++i)
	{
		cout << nums[i] << " ";
	}
	return 0;
}