#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp(high - low + 1);
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    left = low;
    while (left <= high)
    {
        arr[left] = temp[left - low];
        left++;
    }
}
void mergeSort(vector<int> &arr, int i, int j)
{
    if (i == j)
    {
        return;
    }

    int low = i, high = j;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
int main()
{
    vector<int> arr = {5, 4, 2, 3, 1};
    mergeSort(arr, 0, arr.size() - 1);
    for (auto it : arr)
    {
        cout << it << " ";
    }
}