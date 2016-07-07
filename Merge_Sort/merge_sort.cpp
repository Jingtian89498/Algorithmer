#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_sort(vector<int> &arr);
vector<int> merge(vector<int> &left, vector<int> &right);

int main()
{
	vector<int> a = { 6,5,4,3,2,1 };

	vector<int> sortedArr;
	sortedArr = merge_sort(a);
	for (int x : sortedArr)
		cout << x << "\t";
	
	cout << endl;
	return 0;
}

vector<int> merge_sort(vector<int> &arr)
{
	if (arr.size() == 1)
		return arr;
	if (arr.size() == 0)
		return vector<int>();

	vector<int>::iterator mid = arr.begin() + arr.size() / 2;
	vector<int> arr1(arr.begin(), mid);
	vector<int> arr2(mid, arr.end());

	return merge(merge_sort(arr1), merge_sort(arr2));
}

vector<int> merge(vector<int> &left, vector<int> &right)
{
	int i = 0;
	int j = 0;
	int m = int(left.size());
	int n = int(right.size());
	vector<int> result(m+n);
	for (int k = 0; k < m+n; k++)
	{
		if (i == m)
		{
			result[k] = right[j];
			j++;
			continue;
		}

		if (j == n)
		{
			result[k] = left[i];
			i++;
			continue;
		}

		if ((left[i] <= right[j]))
		{
			result[k] = left[i];
			i++;
		}
		else
		{
			result[k] = right[j];
			j++;
		}
	}
	return result;
}

