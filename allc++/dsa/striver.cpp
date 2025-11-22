// #include <bits/stdc++.h>

// using namespace std;
// using ll = long long;

// #define fastio                        \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(0);                       \
//     cout.tie(0);

// class Solution
// {
// public:
//     int maxFrequency(vector<int> &nums, int k)
//     {
//         sort(nums.begin(), nums.end());
//         int l = 0, r = 0;
//         long total = 0, res = 0;
//         while (r < nums.size())
//         {
//             total += nums[r];

//             while (nums[r] * (long)(r - l + 1) > total + k)
//             {
//                 total -= nums[l];
//                 l++;
//             }

//             res = max(res, (long)(r - l + 1));
//             r++;
//         }
//         return (int)res;
//     }
// };

// void bubblesort(int arr[], int n)
// {

//     for (int i = n - 1; i >= 1; i--)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 int temp = arr[j + 1];
//                 arr[j + 1] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }

// void insertionsort(int arr[], int n)
// {
//     int j = 0;
//     for (int i = 0; i <= n - 1; i++)
//     {
//         j = i;
//         while (j >= 0 and arr[j - 1] > arr[j])
//         {
//             int temp = arr[j - 1];
//             arr[j - 1] = arr[j];
//             arr[j] = temp;
//             j--;
//         }
//     }
// }

// void selectionsort(vector<int> &arr, int n)
// {
//     for (int i = 0; i <= n - 2; i++)
//     {
//         for (int j = i + 1; j <= n - 1; j++)
//         {
//             if (arr[j] < arr[i])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[i];
//                 arr[i] = temp;
//             }
//         }
//     }
// }
// // class Solution {
// // public:

// // };
// int climbStairs(int n)
// {
//     if (n <= 3)
//     {
//         return n;
//     }
//     std::vector<int> steps(n + 1,0);
//     steps[1] = 1;
//     steps[2] = 2;
//     steps[3] = 3;
//     for (int i = 4; i <= n; i++)
//     {
//         steps[i] = steps[i - 1] + steps[i - 2];
//     }

//     return steps[n];
// }

// void merge(vector<int> &arr, int low, int mid, int high)
// {
//     vector<int> temp;
//     int left = low;
//     int right = mid + 1;

//     while (left <= mid and right <= high)
//     {
//         if (arr[left] <= arr[right])
//         {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else
//         {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }
//     while (left <= mid)
//     {
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while (right <= high)
//     {
//         temp.push_back(arr[right]);
//         right++;
//     }

//     for (int i = low; i <= high; i++)
//     {
//         arr[i] = temp[i - low];
//     }
// }
// void ms(vector<int> &arr, int low, int high)
// {
//     if (low >= high)
//     {
//         return;
//     }
//     int mid = (low + high) / 2;
//     ms(arr, low, mid);
//     ms(arr, mid + 1, high);
//     merge(arr, low, mid, high);
// }
// void mergesort(vector<int> &arr, int n)
// {

//     ms(arr, 0, n - 1);
// }
// 3 4 5 1 2
// bool check(vector<int> &nums)
// {
//     int index = 0, n = nums.size();
//     for (int i = 0; i < n - 1; i++)
//     {
//         if (nums[i] > nums[i + 1])
//         {
//             index = i + 1;
//             break;
//         }
//     }
//     vector<int> temp(n, 0);
//     int j = index;
//     for (int i = 0; i < n - index; i++)
//     {
//         temp[i] = nums[j];
//         j++;
//     }
//     j = 0;
//     for (int i = n - index; i < n; i++)
//     {
//         temp[i] = nums[j];
//         j++;
//     }

//     for (int i = 0; i < n - 1; i++)
//     {
//         if (temp[i] > temp[i + 1])
//         {
//             return false;
//             break;
//         }
//     }
//     return true;
// }

// vector<int> rotateArray(vector<int>& arr, int n) {
//     // Write your code here.
//     int temp = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         arr[i-1]=arr[i];
//     }
//     arr[n-1]=temp;

// }

// void leftRotate(vector<int> &arr, int d)
// {
//     // code here

//     int n = arr.size(), j = 0;
//     vector<int> temp(n, 0);

//     for (int i = d; i < n; i++)
//     {
//         temp[j] = arr[i];
//         j++;
//     }
//     for (int i = 0; i < d; i++)
//     {
//         temp[j] = arr[i];
//         j++;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = temp[i];
//     }
// }

// void rotate(vector<int> &nums, int k)
// {

//     int n = nums.size(), j = 0;

//     int d = k % n;
//     d = n - d;
//     vector<int> temp(n, 0);

//     for (int i = d; i < n; i++)
//     {
//         temp[j] = nums[i];
//         j++;
//     }
//     for (int i = 0; i < d; i++)
//     {
//         temp[j] = nums[i];
//         j++;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         nums[i] = temp[i];
//     }
// }

// bool customComparator(const string &a, const string &b)
// {

//     if (a.size() != b.size())
//         return a.size() < b.size();

//     return a < b;
// }

// vector<string> bigSorting(vector<string> unsorted)
// {
//     sort(unsorted.begin(), unsorted.end(), customComparator);
//     return unsorted;
// }

// vector<int> sortedArray(vector<int> a, vector<int> b)
// {
//     // Write your code here
//     vector<int> union_array;
//     int i = 0, j = 0;
//     int n1 = a.size(), n2 = b.size();
//     while (i < n1 and j < n2)
//     {
//         /* code */
//         if (a[i] <= b[j])
//         {
//             if (union_array.empty() or union_array.back() != a[i])
//             {
//                 union_array.push_back(a[i]);
//             }
//             i++;
//         }
//         else
//         {
//             if (union_array.empty() or union_array.back() != b[j])
//             {
//                 union_array.push_back(b[j]);
//             }
//             j++;
//         }
//     }
//     while (j < n2)
//     {
//         if (union_array.empty() or union_array.back() != b[j])
//         {
//             union_array.push_back(b[j]);
//         }
//         j++;
//     }
//     while (i < n1)
//     {
//         if (union_array.empty() or union_array.back() != a[i])
//         {
//             union_array.push_back(a[i]);
//         }
//         i++;
//     }

//     return union_array;
// }

// vector<int> intersection(vector<int> &arr1, vector<int> &arr2)
// {
//     vector<int> ans;
//     int n1 = arr1.size(), n2 = arr2.size();
//     int i = 0, j = 0;

//     while (i < n1 && j < n2)
//     {
//         if (arr1[i] < arr2[j])
//         {
//             i++;
//         }
//         else if (arr1[i] > arr2[j])
//         {
//             j++;
//         }
//         else
//         { // arr1[i] == arr2[j]
//             if (ans.empty() || ans.back() != arr1[i])
//             {
//                 ans.push_back(arr1[i]);
//             }
//             i++;
//             j++;
//         }
//     }
//     return ans;
// }

// int missingNumber(vector<int> &nums)
// {
//     int n = nums.size(), ans;
//     vector<int> v(n + 1, 0);
//     for (int i = 0; i < n; i++)
//     {
//         v[nums[i]] = 1;
//     }
//     for (int i = 0; i < n + 1; i++)
//     {
//         if (v[i] == 0)
//         {
//             ans = i;
//             break;
//         }
//     }
//     return ans;
// }

// int singleNumber(vector<int> &nums)
// {
//     int xor1 = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {

//         xor1 = xor1 ^ nums[i];
//     }
//     return xor1;
// }

// int longestSubarrayWithSumK(vector<int> a, long long k)
// {
//     int maxlen = 0, n = a.size();
//     long sum = a[0];
//     int left, right;
//     left = right = 0;
//     while (right < n)
//     {

//         while (left <= right and sum > k)
//         {
//             sum -= a[left];
//             left++;
//         }
//         if (sum == k)
//         {
//             maxlen = max(maxlen, right - left + 1);
//         }
//         right++;
//         if (right < n)
//         {
//             sum += a[right];
//         }
//     }

//     return maxlen;
// }

// vector<int> twoSum(vector<int> &nums, int target)
// {

//     map<int, int> mp;

//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         int a = nums[i];
//         int b = target - a;
//         if (mp.find(b) != mp.end())
//         {
//             return {i, mp[b]};
//         }

//         mp[a] = i;
//     }
//     return {-1, -1};
// }

// void sortArray(vector<int> &arr, int n)
// {
// int low, mid, high;
// low = mid = 0;
// high = n - 1;
// while (mid <= high)
// {
//     if (arr[mid] == 0)
//     {
//         swap(arr[low], arr[mid]);
//         low++;
//         mid++;
//     }
//     else if (arr[mid] == 2)
//     {
//         swap(arr[mid], arr[high]);
//         high--;
//     }
//     else
//     {
//         mid++;
//     }
// }
// }

// int main()
// {

//     vector<int> arr = {2, 2, 1};
//     vector<pair<int, int>> mp;
//     mp.push_back({1, 2});

//     if (mp.empty())
//     {
//         cout<<"Yes";
//     }

// int arr[] = {13, 46, 24, 52, 20, 9};
// int n = sizeof(arr) / sizeof(int);

// vector<int> arr = {-1};

// int largest = arr[0];
// int slar = INT_MIN;
// for (int i = 1; i < n; i++)
// {
//     if (largest < arr[i])
//     {
//         slar = largest;
//         largest = arr[i];
//     }
//     if (arr[i] < largest and arr[i] > slar)
//     {
//         slar = arr[i];
//     }
// }
// vector<int> temp(arr.size(), 0);
// int j = 0;
// for (int i = 0; i < arr.size(); i++)
// {
//     if (arr[i] != 0)
//     {
//         temp[j] = arr[i];
//         j++;
//     }
// }

// for (auto it : temp)
// {
//     cout << it << " ";
// }

//     return 0;
// }

// void reverseArray(vector<int> &a , int m) {
//     // Write your code here
//     int n = a.size();
//     int left=m+1,right=n-1;
//     while(left<=right){
//         if(left==right){break;}
//         swap(a[left],a[right]);
//         left++;right--;

//     }
// }
/* int majorityElement(vector<int> v)
{
    // Write your code here
    int c = 0, el, n = v.size();
    for (int i = 0; i < n; i++)
    {

        if (c == 0)
        {
            c = 1;
            el = v[i];
        }
        else if (el == v[i])
        {
            c++;
        }
        else
            c--;
    }
    return el;

} */

// int maximumProfit(vector<int> &prices)
// {
//     // Write your code here.
//     int profit = -1, j = 0;

//     int buy = prices[0];
//     for (int i = 1; i < prices.size(); i++)
//     {
//         /* code */

//         profit = max(profit, prices[i] - buy);
//         buy = min(buy, prices[i]);
//     }
//     return profit;
// }

// vector<int> alternateNumbers(vector<int> &a)
// {
//     // Write your code here.
//     int n = a.size();
//     vector<int> pos, neg;

//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] > 0)
//         {
//             pos.push_back(a[i]);
//         }
//         else
//         {
//             neg.push_back(a[i]);
//         }
//     }
//     int small = min(pos.size(), neg.size());
//     int big = max(pos.size(), neg.size());

//     for (int i = 0; i <small; i++)
//     {
//         a[2 * i] = pos[i];

//         a[2 * i + 1] = neg[i];
//     }
//     int idx = 2 * small;
//     if (pos.size() > neg.size())
//     {

//         for (int i = small; i < big; i++)
//         {

//             a[idx] = pos[i];
//             idx++;
//         }
//     }
//     else
//     {
//         for (int i = small; i < big; i++)
//         {
//             a[idx] = neg[i];
//             idx++;
//         }
//     }

//     return a;
// }

// int longestSuccessiveElements(vector<int> &a)
// {
//     // Write your code here.
//     sort(a.begin(), a.end());
//     int answer = 0;
//     int length = 1;
//     int first_element = a[0];
//     for (int i = 1; i < a.size(); i++)
//     {
//         /* code */
//         if (a[i] == first_element)
//         {
//             continue;
//         }
//         else
//         {
//             if ((a[i] - first_element) == 1)
//             {
//                 length += 1;
//             }
//             else
//             {
//                 length = 1;
//             }
//             first_element = a[i];
//             answer = max(length, answer);
//         }
//     }
//     return answer;
// }

// vector<int> generaterows(int row)
// {
//     long long res = 1;
//     vector<int> roww;
//     roww.push_back(1);

//     for (int col = 1; col < row; col++)
//     {
//         res = res * (row - col);
//         res /= col;
//         roww.push_back(res);
//     }

//     return roww;
// }

// vector<vector<int>> pascalTriangle(int N)
// {
//     // Write your code here.
//     vector<vector<int>> ans;
//     for (int i = 1; i <= N; i++)
//     {
//         ans.push_back(generaterows(i));
//     }
//     return ans;
// }
// vector<vector<int>> triplet(int n, vector<int> &arr)
// {
//     // Write your code here.
//     sort(arr.begin(),arr.end());
//     vector<vector<int>>ans;
//     int n = arr.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (i>0 and arr[i]==arr[i-1])
//         {
//             continue;
//         }

//         int j=i+1,k=n-1;
//         while (j<k)
//         {
//             int sum = arr[i]+arr[j]+arr[k];
//             if (sum<0)
//             {
//                j++;
//             }
//             else if (sum>0)
//             {
//                 k--;
//             }
//             else
//             {
//                 vector<int>temp={arr[i],arr[j],arr[k]};
//                 ans.push_back(temp);
//                 j++;
//                 k--;
//                 while (j<k and arr[j]==arr[j-1])
//                 {
//                     j++;
//                 }
//                 while (j<k and arr[k]==arr[k+1])
//                 {
//                     k--;
//                 }
//             }

//         }

//     }
//     return ans;
// }

// int main()
// {

//     return 0;
// }

// int countCustomers(vector<int> &arr, int k)
// {
//     //    Write your code here
//     vector<int>c;
//     int free=k,ans=0;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         /* code */
//         if (c[arr[i]]==0)
//         {
//             /* code */
//             if (free>0)
//             {
//                 c[arr[i]]=1;free--;
//             }
//             else{ ans++;}

//             continue;
//         }
//         else if (c[arr[i]]==1)
//         {
//             free++;
//             c[arr[i]]=2;
//             continue;
//         }

//     }
//     return ans;

// }

// vector<vector<int>> fourSum(vector<int> &a, int target)
// {
//     // Write your code here
//     vector<vector<int>> ans;
//     sort(a.begin(), a.end());
//     int n = a.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (i > 0 and a[i] == a[i - 1])
//             continue;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (j != i + 1 and a[j] == a[j - 1])
//             {
//                 continue;
//             }

//             int k = j + 1;
//             int l = n - 1;
//             while (k < l)
//             {
//                 long long sum = a[i];
//                 sum += a[j];
//                 sum += a[k];
//                 sum += a[l];
//                 if (sum > target)
//                 {
//                     l--;
//                 }
//                 else if (sum < target)
//                 {
//                     k++;
//                 }
//                 else
//                 {
//                     vector<int> temp = {a[i], a[j], a[k], a[l]};
//                     ans.push_back(temp);
//                     k++;
//                     l--;
//                     while (k < l and a[k] == a[k - 1])
//                         k++;
//                     while (k < l and a[l] == a[l + 1])
//                         l--;
//                 }
//             }
//         }
//     }
//     return ans;
// }

// int singleNonDuplicate(vector<int>& nums) {
//     int n = nums.size();
//     if(n==1) return nums[0];
//     if(nums[0]!=nums[1]) return nums[0];
//     if(nums[n-1]!=nums[n-2]) return nums[n-1];

//     int low = 1,high = n-2;

//     while (low<=high)
//     {
//         int mid = (low+high)/2;

//         if(nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1]){return
//         nums[mid];}

//         if ((mid%2==1 and nums[mid-1]==nums[mid]) or (mid%2==0 and
//         nums[mid+1]==nums[mid]))
//         {
//             low=mid+1;
//         }
//         else
//         {
//             high=mid-1;
//         }

//     }
//     return -1;

//     }

//     int findPeakElement(vector<int> &arr) {
//     // Write your code here
//     int n = arr.size();
//     if(n==1 or arr[0]>arr[1]) return 0;
//     if(arr[n-1]>arr[n-2]) return n-1;
//     int low = 1,high = n-2;
//     while(low<=high){
//         int mid = (low+high)/2;
//         if(arr[mid-1]<arr[mid] and arr[mid]>arr[mid+1]){
//             return mid;
//         }
//         else if (arr[mid]>arr[mid-1] and arr[mid]<arr[mid+1]){
//             low=mid+1;
//         }
//         else{
//             high=mid-1;
//         }
//     }
//     return -1;
// }

// int NthRoot(int n, int m)
// {
//     // Write your code here.
//     long low = 1, high = m;
//     while (low <= high)
//     {
//         /* code */
//         long mid = (low + high) / 2;

//         if (pow(mid, n) == m)
//             return mid;

//         else if (pow(mid, n) > m)
//         {
//             /* code */
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return -1;
// }

// int searchInsert(vector<int> &nums, int target)
// {
//     if (target <= nums[0])
//     {
//         return 0;
//     }
//     if (target >= nums.back())
//     {
//         return nums.size();
//     }

//     int low = 0, high = nums.size() - 1, idx = -1;

//     while (low <= high)
//     {
//         int mid = (low + high) / 2;

//         if (nums[mid] == target)
//         {
//             return mid;
//         }
//         else if (nums[mid] < target)
//         {
//             low = mid + 1;
//         }
//         else if (nums[mid] > target)
//         {
//             /* code */
//             high = mid - 1;
//             idx = mid;
//         }
//     }
//     return idx;
// }

// bool possible(vector<int> arr, int k, int m, int day)
// {
//     int cnt = 0, boq = 0;
//     for (auto i = 0; i < arr.size(); i++)
//     {
//         if (arr[i] <= day)
//         {
//             cnt++;
//         }
//         else
//         {
//             boq += (cnt / k);
//             cnt = 0;
//         }
//     }

//     boq += (cnt / k);

//     return boq >= m;
// }
// int roseGarden(vector<int> arr, int k, int m)
// {
//     // Write your code here
//     set<int> days(arr.begin(), arr.end());

//     for (auto it : days)
//     {
//         if (possible(arr, k, m, it))
//         {
//             return it;
//         }
//         else
//             continue;
//     }
//     return -1;
// }
// int minDays(vector<int> &arr, int m, int k)
// {
//     long ans = -1;
//     long low = *min_element(arr.begin(), arr.end()), high =
//     *max_element(arr.begin(), arr.end()); while (low <= high)
//     {
//         long mid = low + (high - low) / 2;
//         if (possible(arr, k, m, mid))
//         {
//             ans = mid;
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

// bool div(vector<int> &nums, int threshold, int d)
// {
//     long sum = 0;
//     for (auto i = 0; i < nums.size(); i++)
//     {
//         sum += (nums[i] + d - 1) / d;
//     }

//     return sum <= threshold;
// }
// int smallestDivisor(vector<int> &nums, int threshold)
// {
//     int ans = -1;
//     long low = 1, high = *max_element(nums.begin(), nums.end());
//     while (low <= high)
//     {
//         long mid = low + (high - low) / 2;

//         if (div(nums, threshold, mid))
//         {
//             high = mid - 1;
//             ans = mid;
//         }
//         else
//             low = mid + 1;
//     }

//     return ans;
// }

// int shipments(vector<int> a, int capacity)
// {
//     int s = 0, ans = 0;
//     for (int i = 0; i < a.size(); i++)
//     {
//         if (a[i] > capacity)
//         {

//             return -1;
//         }
//         s += a[i];
//         if (s > capacity)
//         {
//             ans++;
//             s = a[i];
//         }
//     }
//     if (s > 0)
//     {
//         ans++;
//     }
//     return ans;
// }

// int shipWithinDays(vector<int> &w, int days)
// {

//     long sum = 0,ans=-1;
//     for (auto i = 0; i < w.size(); i++)
//     {
//         sum += w[i];
//     }

//     long low = *max_element(w.begin(), w.end()), high = sum;

//     while (low<=high)
//     {
//         long mid = low+(high-low)/2;
//         if (shipments(w,mid)<=days)
//         {
//             high=mid-1;ans=mid;
//         }
//         else low=mid+1;

//     }
//     return ans;

// }
// #include <bits/stdc++.h>
// using namespace std;

// int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
// {
//     // Write Your Code Here
//     int cnt_max = 0, index = -1;
//     for (int i = 0; i < n; i++)
//     {
//         int cnt_ones = m - (lower_bound(matrix[i].begin(), matrix[i].end(),
//         1) - matrix[i].begin()); if (cnt_ones > cnt_max)
//         {
//             cnt_max = cnt_ones;
//             index = i;
//         }
//     }
//     return index;
// }
// int student(vector<int> a, int pages)
// {
//     int cnt = 0, stdpages = 0;

//     for (int i = 0; i < a.size(); i++)
//     {
//         if (stdpages + a[i] <= pages)
//         {
//             stdpages += a[i];
//         }
//         else
//         {
//             cnt++;
//             stdpages = a[i];
//         }
//     }
//     return cnt;
// }
// int findPages(vector<int> &arr, int n, int m)
// {
//     // Write your code here.
//     long ans = -1;
//     if (m > n)
//     {
//         return -1;
//     }

//     long sum = accumulate(arr.begin(), arr.end(), 0);
//     long low = *max_element(arr.begin(), arr.end()), high = sum;

//     while (low <= high)
//     {
//         long mid = low + (high - low) / 2;

//         long stdcnt = student(arr, mid);
//         if (stdcnt >= m)
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
//         }
//     }

//     return low;
// }

// double minimiseMaxDistance(vector<int> &arr, int k)
// {
//     // Write your code here.
//     int n = arr.size();
//     vector<int> howmany(n - 1, 0);
//     priority_queue<pair<long double, int>> pq;
//     for (int i = 0; i < n - 1; i++)
//     {
//         pq.push({arr[i + 1] - arr[i], i});
//     }

//     for (int gasstn = 1; gasstn <= k; gasstn++)
//     {
//         auto tp = pq.top();
//         pq.pop();

//         int secidx = tp.second;
//         howmany[secidx]++;

//         long double diff = arr[secidx + 1] - arr[secidx];
//         long double secdiff = diff / (long double)(howmany[secidx] + 1);

//         pq.push({secdiff, secidx});
//     }

//     return pq.top().first;
// }

// int lowerBound(vector<vector<int>> arr, int x)
// {
//     // Write your code here
//     int n = arr.size() - 1;
//     int l = 0, h = n - 1, ans = n;

//     while (l <= h)
//     {
//         int mid = (l + h) / 2;
//         if (arr[mid][0] >= x)
//         {
//             ans = mid;
//             h = mid - 1;
//         }
//         else
//         {
//             l = mid + 1;
//         }
//     }
//     return ans;
// }
// int getrowindex(vector<vector<int>> a, int col)
// {
//     int n = a.size(), maxvalue = -1, maxidx = -1;
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i][col] > maxvalue)
//         {
//             maxvalue = a[i][col];
//             maxidx = i;
//         }
//     }
//     return maxidx;
// }
// vector<int> findPeakGrid(vector<vector<int>> &mat)
// {
//     int m = mat[0].size();
//     int low = 0, high = m - 1;

//     while (low <= high)
//     {
//         int mid = (low + high) / 2;

//         int row = getrowindex(mat, mid);

//         int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
//         int right = mid + 1 < m ? mat[row][mid + 1] : -1;

//         if (mat[row][mid] >= left && mat[row][mid] >= right)
//         {
//             return {row, mid};
//         }
//         else if (mat[row][mid] > left && mat[row][mid] < right)
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
//         }
//     }
//     return {-1, -1};
// }

// string removeOuterParentheses(string s)
// {

//     string ss = "";
//     int hmap = 0;
//     int start = 0, end = -1;

//     for (int i = 0; i < s.size(); i++)
//     {

//         if (s[i] == '(')
//         {
//             if (hmap > 0)
//             {
//                 ss += s[i];
//             }
//             hmap++;
//         }
//         else if (s[i] == ')')
//         {
//             hmap--;
//             if (hmap > 0)
//             {
//                 ss += s[i];
//             }
//         }
//     }

//     return ss;
// }

// string reverseWords(string s)
// {
//     int n = s.size();
//     string ans = "";
//     reverse(s.begin(), s.end());
//     for (int i = 0; i < n; i++)
//     {
//         string word = "";
//         while (i < n and s[i] != ' ')
//         {
//             word += s[i];
//             i++;
//         }

//         reverse(word.begin(), word.end());
//         if (word.length() > 0)
//         {
//             if (ans.size() == 0)
//             {
//                 ans += word;
//             }
//             else
//             {
//                 ans += " " + word;
//             }
//         }
//     }
//     return ans;
// }

// string largestOddNumber(string num)
// {

//     string s = "";

//     for (int i = num.length() - 1; i >= 0; i--)
//     {
//         if ((num[i] - '0') & 1)
//         {
//             return num.substr(0, i + 1);
//         }
//     }

//     return s;
// }

// string longestCommonPrefix(vector<string> &strs)
// {
//     string s = strs[0];
//     int len = s.size();

//     for (int i = 1; i < strs.size(); i++)
//     {
//         string ss = strs[i];

//         while (len > ss.length() or s != ss.substr(0, len))
//         {
//             len--;
//             if (len == 0)
//             {
//                 return "";
//             }
//         }
//     }

//     return s;
// }

// bool isIsomorphic(string s, string t)
// {
//     unordered_map<char, char> mp1, mp2;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (mp1.find(s[i]) == mp1.end())
//         {
//             mp1[s[i]] = t[i];
//         }
//         else if (mp1.find(s[i]) != mp1.end() and mp1[s[i]] != t[i])
//         {
//             return false;
//         }
//         if (mp2.find(t[i]) == mp2.end())
//         {
//             mp2[t[i]] = s[i];
//         }
//         else if (mp2.find(t[i]) != mp2.end() and mp2[t[i]] != s[i])
//         {
//             return false;
//         }
//     }
//     return true;
// }

// bool rotateString(string s, string goal)
// {

//     if (s.size() != goal.size())
//     {
//         return false;
//     }

//     return (s + s).find(goal) != string::npos;
// }

// bool isAnagram(string s, string t)
// {

//     if (s.size() != t.size())
//     {
//         return false;
//     }
//     unordered_map<char, int> mp1, mp2;

//     for (int i = 0; i < s.size(); i++)
//     {
//         mp1[s[i]]++;
//         mp2[t[i]]++;
//     }
//     for (int i = 0; i < t.size(); i++)
//     {
//         if (mp2[t[i]] != mp1[t[i]])
//         {
//             return false;
//         }
//     }

//     return true;
// }

// string frequencySort(string s)
// {
//     map<char, int> mp;

//     for (auto it : s)
//     {
//         mp[it]++;
//     }
//     vector<pair<char, int>> hmap(mp.begin(), mp.end());

//     sort(hmap.begin(), hmap.end(), [](const pair<char, int> &a, const
//     pair<char, int> &b)
//          { return a.second > b.second; });

//     string ans = "";

//     for (auto it : hmap)
//     {
//         ans += string(it.second, it.first);
//     }

//     return ans;
// }

// int maxDepth(string s)
// {
//     int depth = 0, maxdepth = 0;

//     for (auto it : s)
//     {
//         if (it == '(')
//         {
//             depth++;
//             maxdepth = max(maxdepth, depth);
//         }
//         else if (it == ')')
//         {
//             depth--;
//         }
//     }

//     return maxdepth;
// }

// int romanToInt(string s)
// {
//     int ans = 0;

//     map<char, int> mp = {
//         {'I', 1},
//         {'V', 5},
//         {'X', 10},
//         {'L', 50},
//         {'C', 100},
//         {'D', 500},
//         {'M', 1000}};

//     for (int i = s.size() - 1; i >= 0; i--)
//     {
//         if (i == s.size() - 1 || mp[s[i]] >= mp[s[i + 1]])
//         {
//             ans += mp[s[i]];
//         }
//         else
//         {
//             ans -= mp[s[i]];
//         }
//     }

//     return ans;
// }

// string longestPalindrome(string s)
// {
//     string ans = "";
//     int n = s.size();

//     for (int i = 0; i < n; i++)
//     {
//         int l = i, r = i;
//         while (l >= 0 and r < n and s[l] == s[r])
//         {
//             if (r - l + 1 > ans.size())
//             {
//                 ans = s.substr(l, r - l + 1);
//             }
//             l -= 1;
//             r += 1;
//         }
//         l = i, r = i + 1;
//         while (l >= 0 and r < n and s[l] == s[r])
//         {
//             if (r - l + 1 > ans.size())
//             {
//                 ans = s.substr(l, r - l + 1);
//             }
//             l -= 1;
//             r += 1;
//         }
//     }

//     return ans;
// }

// int getsum(vector<int> dp)
// {
//     int a1 = *max_element(dp.begin(), dp.end()), a2 = 1;
//     for (auto it : dp)
//     {
//         if (it >= 1)
//         {
//             a2 = min(a2, it);
//         }
//     }

//     return a1 - a2;
// }
// int beautySum(string s)
// {
//     int res = 0, n = s.size();
//     for (int i = 0; i < n; i++)
//     {
//         vector<int> dp(26, 0);
//         for (int j = i; j < n; j++)
//         {
//             dp[s[j] - 'a']++;
//             res += getsum(dp);
//         }
//     }
//     return res;
// }

// // vector<int> twoSum(vector<int> &nums, int target)
// // {

// //     map<int, int> sum;

// //     int n = nums.size();
// //     sum.insert({nums[0], 0});

// //     for (int i = 1; i < n; i++)
// //     {
// //         int a = nums[i];
// //         int b = target - a;
// //         if (sum.find(b) != sum.end())
// //         {
// //             return {sum[b], i};
// //         }
// //         sum[nums[i]] = i;
// //     }

// //     return {-1, -1};
// // }

// vector<int> lcmAndGcd(int a, int b)
// {
//     // code here
//     int gcd = 0, lcm = 0, n1 = a, n2 = b;
//     while (a > 0 and b > 0)
//     {
//         if (a > b)
//         {
//             a = a % b;
//         }
//         else
//             b = b % a;
//     }
//     if (a == 0)
//     {
//         gcd = b;
//     }
//     else
//         gcd = a;

//     lcm = (n1 * n2) / gcd;

//     return {lcm, gcd};
// }
// int gcdd(int a, int b)
// {
//     int gcd = 0;
//     while (a > 0 and b > 0)
//     {
//         if (a > b)
//         {
//             a = a % b;
//         }
//         else
//             b = b % a;
//     }
//     if (a == 0)
//     {
//         return b;
//     }
//     return a;
// }
// int findGCD(vector<int> &nums)
// {
//     int n1 = *min_element(nums.begin(), nums.end());
//     int n2 = *max_element(nums.begin(), nums.end());
//     int gcd = gcdd(n1, n2);

//     return gcd;
// }
// vector<int> evenOddBit(int n)
// {
//     int i = 0, oddcnt = 0, evencnt = 0;
//     for (int i = 0; i < 9; i++)
//     {
//         if ((n >> i) & 1 == 1)
//         {
//             if (i & 1)
//             {
//                 oddcnt++;
//             }
//             else
//             {
//                 evencnt++;
//             }
//         }
//     }
//     return {evencnt, oddcnt};
// }
// string removeDigit(string number, char digit)
// {
//     string ans = "";
//     for (int i = 0; i < number.length(); i++)
//     {

//         if (number[i] == digit)
//         {
//             string s = number;
//             /* code */
//             s.erase(i, 1);
//             if (s > ans)
//             {
//                 ans = s;
//             }
//         }
//     }
//     return ans;
// }

// int findxr(int n)
// {
//     if (n % 4 == 1)
//     {
//         return 1;
//     }
//     else if (n % 4 == 2)
//     {
//         return n + 1;
//     }
//     else if (n % 4 == 3)
//     {
//         return 0;
//     }
//     else
//     {
//         return n;
//     }
// }
// int findXOR(int l, int r)
// {
//     // complete the function here
//     int g1, g2;
//     g1 = findxr(l - 1);
//     g2 = findxr(r);

//     return g1 ^ g2;
// }

// int divide(int dividend, int divisor)
// {
//     if (dividend == divisor)
//         return 1;
//     if (dividend == INT_MIN)
//     {
//         if (divisor==1)
//         {
//             return INT_MIN;
//         }

//         return INT_MAX;
//     }
//     if (dividend == INT_MAX)
//     {
//         if (divisor==-1)
//         {
//             return INT_MIN;
//         }

//         return INT_MAX;
//     }
//     bool sign = (dividend >= 0 == divisor >= 0) ? true : false;

//     long n = labs(dividend);
//     long d = labs(divisor);
//     long ans = 0;
//     while (n >= d)
//     {
//         int cnt = 0;
//         while (n >= (d * (1 << cnt + 1)))
//         {
//             cnt++;
//         }
//         ans += (1 << cnt);
//         n -= (d * (1 << cnt));
//     }

//     if (ans == (1 << 31) and sign)
//     {
//         return INT_MAX;
//     }
//     if (ans == (1 << 31) and !sign)
//     {
//         return INT_MIN;
//     }

//     if (sign)
//     {
//         return ans;
//     }
//     else
//     {
//         return -ans;
//     }
// }

// bool isPrime(int n)
// {
//     // code here
//     if (n <= 1)
//     {
//         return false;
//     }

//     bool t = true;
//     for (int i = 2; i <= sqrt(n); i++)
//     {
//         /* code */
//         if (n % i == 0)
//         {
//             return false;
//         }
//     }

//     return t;
// }

// void print_divisors(int n)
// {
//     // Code here.
//     vector<int> li;

//     for (int i = 1; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//         {
//             li.push_back(i);
//             if (n / i != i)
//             {
//                 li.push_back(n / i);
//             }
//         }
//     }
//     sort(li.begin(), li.end());

//     for (auto i : li)
//     {
//         cout << i << " ";
//     }
// }

// vector<int> AllPrimeFactors(int n)
// {
//     // Code here
//     vector<int> li;
//     for (int i = 2; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//         {
//             li.push_back(i);
//             while (n % i == 0)
//             {
//                 n /= i;
//             }
//         }
//     }
//     if (n != 1)
//     {
//         li.push_back(n);
//     }

//     sort(li.begin(), li.end());

//     return li;
// }

// double power(double x, int n)
// {
//     long long exp = static_cast<long long>(n);

//     bool negative = false;
//     if (exp < 0)
//     {
//         negative = true;
//         exp = -exp;
//     }

//     double ans = 1;
//     while (exp > 0)
//     {
//         if (exp & 1)
//         {
//             ans *= x;
//             exp--;
//         }
//         x *= x;
//         exp /= 2;
//     }

//     return negative ? 1 / ans : ans;
// }

// int countprimes(int n)
// {
//     int cnt = 0;
//     if (n <= 1)
//     {
//         return 0;
//     }

//     vector<int> prime(100000 + 1, 1);

//     for (int i = 2; i <= prime.size(); i++)
//     {
//         prime[i] = i;
//     }

//     for (int i = 2; i * i <= 100000; i++)
//     {
//         /* code */
//         if (prime[i] == i)
//         {
//             for (int j = i * i; j <= n; j += i)
//             {
//                 if (prime[j] == j)
//                 {
//                     prime[j] = i;
//                 }
//             }
//         }
//     }
//     for (int i = 2; i <= n; i++)
//     {
//         cnt += prime[i];
//     }

//     return cnt;
// }

// vector<int> findPrimeFactors(int N)
// {
//     vector<int> prime(100000 + 1, 1);
//     vector<int> ans;

//     for (int i = 2; i <= prime.size(); i++)
//     {
//         prime[i] = i;
//     }

//     for (int i = 2; i * i <= 100000; i++)
//     {
//         /* code */
//         if (prime[i] == i)
//         {
//             for (int j = i * i; j <= 100000; j += i)
//             {
//                 if (prime[j] == j)
//                 {
//                     prime[j] = i;
//                 }
//             }
//         }
//     }
//     while (N != 1)
//     {
//         /* code */
//         ans.push_back(prime[N]);
//         N /= prime[N];
//     }
//     return ans;
// }

// // 1, 6, 4, 10, 2, 5
// //-1, 1, 1,  4, 1, 2
// vector<int> leftSmaller(int n, vector<int> a)
// {
//     // code here
//     stack<int> st;
//     vector<int> ans;
//     st.push(a[0]);
//     ans.push_back(-1);

//     for (int i = 1; i < n; i++)
//     {

//         while (!st.empty() and st.top() <= a[i])
//         {
//             st.pop();
//         }

//         if (st.empty())
//         {
//             ans.push_back(-1);
//         }
//         else
//             ans.push_back(st.top());

//         st.push(a[i]);
//     }
//     return ans;
// }

// int trap(vector<int> &height)
// {
//     int n = height.size();
//     if (n <= 2)
//         return 0;

//     vector<int> leftMax(n), rightMax(n);

//     leftMax[0] = height[0];
//     for (int i = 1; i < n; i++)
//     {
//         leftMax[i] = max(leftMax[i - 1], height[i]);
//     }

//     rightMax[n - 1] = height[n - 1];
//     for (int i = n - 2; i >= 0; i--)
//     {
//         rightMax[i] = max(rightMax[i + 1], height[i]);
//     }

//     int totalWater = 0;
//     for (int i = 0; i < n; i++)
//     {
//         totalWater += min(leftMax[i], rightMax[i]) - height[i];
//     }

//     return totalWater;
// }

// vector<int> asteroidCollision(vector<int> &asteroids)
// {
//     stack<int> st;

//     for (int asteroid : asteroids)
//     {
//         bool destroyed = false;

//         while (!st.empty() && asteroid < 0 && st.top() > 0)
//         {
//             int p = st.top();
//             if (abs(asteroid) > p)
//             {
//                 st.pop();
//             }
//             else if (abs(asteroid) == p)
//             {
//                 st.pop();
//                 destroyed = true;
//                 break;
//             }
//             else
//             {
//                 destroyed = true;
//                 break;
//             }
//         }

//         if (!destroyed)
//         {
//             st.push(asteroid);
//         }
//     }

//     vector<int> ans;
//     while (!st.empty())
//     {
//         ans.push_back(st.top());
//         st.pop();
//     }
//     reverse(ans.begin(), ans.end());

//     return ans;
// }

// int leftlimit(vector<int> &heights, int pos)
// {
//     if (pos == 0)
//     {
//         return 0;
//     }

//     int c = 0;
//     for (int i = pos - 1; i >= 0; i--)
//     {
//         if (heights[i] >= heights[pos])
//         {
//             c++;
//         }
//         else
//             break;
//     }

//     return c;
// }
// int rightlimit(vector<int> &heights, int pos)
// {
//     if (pos == heights.size() - 1)
//     {
//         return 0;
//     }

//     int c = 0;
//     for (int i = pos + 1; i < heights.size(); i++)
//     {
//         if (heights[i] >= heights[pos])
//         {
//             c++;
//         }
//         else
//             break;
//     }

//     return c;
// }
// int allsame(vector<int> &heights, int pos)
// {

//     int c = 0;
//     for (int i = pos + 1; i < heights.size(); i++)
//     {
//         if (heights[pos] == heights[i])
//         {
//             c++;
//         }
//         else
//             break;
//     }

//     return c;
// }

// int largestRectangleArea(vector<int> &heights)
// {

//     int result = 0, n = heights.size();
//     if (allsame(heights, 0) + 1 == n)
//     {
//         return heights[0] * n;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (heights[i] == 0)
//         {
//             continue;
//         }

//         int l = leftlimit(heights, i);
//         int r = rightlimit(heights, i);

//         int r1 = (l + r + 1) * heights[i];

//         i += allsame(heights, i);

//         result = max(result, r1);
//     }

//     return result;
// }

// double f(double a)
// {
//     return a * a * a - (2.0 * a) - 5.0;
// }

// void bisection(double a, double b, int i, int max_iter)
// {
//     double mid = (a + b) / 2.0;
//     cout << ::left;
//     cout << "X" << i << setw(3) << ":" << setw(10) << mid << endl;

//     if (fabs(f(mid)) < 1e-6 || i == max_iter)
//     {
//         return;
//     }

//     if (f(mid) * f(a) < 0)
//     {
//         bisection(a, mid, ++i, max_iter);
//     }
//     else
//     {
//         bisection(mid, b, ++i, max_iter);
//     }
// }

// bool containsDuplicate(vector<int> &nums)
// {

//     map<int, int> hmap;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         hmap[nums[i]]++;
//         if (hmap[nums[i]] >= 2)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// vector<vector<int>> subsets(vector<int> &nums)
// {
//     vector<vector<int>> ans;
//     int n = nums.size();
//     int limit = 1 << n;

//     for (int i = 0; i < limit; i++)
//     {
//         vector<int> a;
//         for (int j = 0; j < n; j++)
//         {
//             if (i & (1 << j))
//             {
//                 a.push_back(nums[j]);
//             }
//         }
//         ans.push_back(a);
//     }
//     return ans;
// }

// string minWindow(string &S, string &T)
// {
//     int start = -1, s = S.size(), t = T.size(), minlen = s + 1;
//     if (t > s)
//     {
//         return "";
//     }

//     for (int i = 0; i < s; i++)
//     {
//         if (S[i] != T[0])
//         {
//             continue;
//         }

//         int sptr = i, tptr = 0;

//         while (sptr < s)
//         {
//             if (S[sptr] == T[tptr])
//             {
//                 tptr++;
//                 if (tptr == t)
//                 {
//                     break;
//                 }
//             }
//             sptr++;
//         }

//         if (tptr == t)
//         {
//             tptr--;
//             int end = sptr;

//             while (sptr > i)
//             {
//                 if (S[sptr] == T[tptr])
//                 {
//                     tptr--;
//                     if (tptr < 0)
//                     {
//                         break;
//                     }
//                 }
//                 sptr--;
//             }

//             if (end - sptr + 1 < minlen)
//             {
//                 minlen = end - sptr + 1;
//                 start = sptr;
//             }
//         }
//     }
//     if (start == -1)
//     {
//         return "";
//     }
//     return S.substr(start, minlen);
// }

// #define MOD 1000000007

// // recursive approc , gives TLE
// /* long solving(int index, vector<int> &nums, int minVal, int maxVal, int
// target)
// {
//     if (index == nums.size())
//     {
//         if (minVal != INT_MAX)
//         {
//             return ((minVal + maxVal) <= target) ? 1L : 0L;
//         }
//         return 0L;
//     }

//     long take = solving(index + 1, nums, min(minVal, nums[index]),
//     max(maxVal, nums[index]), target);

//     long nottake = solving(index + 1, nums, minVal, maxVal, target);

//     return (take+nottake)%MOD;
// }

// int numSubseq(vector<int> &nums, int target)
// {
//     return solving(0,nums,INT_MAX,INT_MIN,target);
// } */

// int numSubseq(vector<int> &nums, int target)
// {
//     sort(nums.begin(), nums.end());
//     int left = 0, right = nums.size() - 1;
//     long result = 0;

//     vector<long> power(nums.size(), 1);
//     for (int i = 1; i < nums.size(); i++)
//     {
//         power[i] = (power[i - 1] * 2) % MOD;
//     }

//     while (left <= right)
//     {
//         /* code */
//         if (nums[left] + nums[right] <= target)
//         {
//             result += (power[right - left] % MOD);
//             left++;
//         }
//         else
//             right--;
//     }

//     return result % MOD;
// }

// bool isSubsetPresent(int n, int k, vector<int> &a)
// {
//     vector<bool> dp(k + 1, false);

//     dp[0] = true;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = k; j >= a[i]; j--)
//         {
//             dp[j] = dp[j] or dp[j - a[i]];
//         }
//     }

//     return dp[k];
// }

// void printSubsequences(vector<int> &arr, vector<int> &temp, int index)
// {
//     if (index == arr.size())
//     {
//         cout << "{ ";
//         // Base case: print the current subsequence
//         if (!temp.empty())
//         {
//             for (int num : temp)
//             {
//                 cout << num << " ";
//             }
//             cout << "}" << endl;
//         }
//         else
//             cout << "}" << endl;
//         return;
//     }

//     // Include the current element
//     temp.push_back(arr[index]);
//     printSubsequences(arr, temp, index + 1);

//     // Exclude the current element
//     temp.pop_back();
//     printSubsequences(arr, temp, index + 1);
// }

// void s(int index, vector<int> &candidate, int target,
//        vector<vector<int>> &ans, vector<int> &temp)
// {

//     if (target == 0)
//     {
//         ans.push_back(temp);
//         return;
//     }

//     for (int i = index; i < candidate.size(); i++)
//     {

//         if (i > index && candidate[i] == candidate[i - 1])
//         {
//             continue;
//         }

//         if (candidate[i] > target)
//         {
//             break;
//         }

//         temp.push_back(candidate[i]);
//         s(i + 1, candidate, target - candidate[i], ans, temp);
//         temp.pop_back();
//     }
// }

// vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
// {
//     sort(candidates.begin(), candidates.end());
//     vector<vector<int>> ans;
//     vector<int> temp;
//     s(0, candidates, target, ans, temp);
//     return ans;
// }

// /* vector<vector<int>> combinationSum(vector<int> &candidates, int target)
// {

//     vector<vector<int>> ans;
//     vector<int> temp;
//     s(0, candidates, target, ans, temp);
//     set<vector<int>>t={ans.begin(),ans.end()};
//     ans={t.begin(),t.end()};
//     return ans;
// } */

// void sums(vector<int> &arr, vector<int> &ans, int sum, int index)
// {
//     if (index == arr.size())
//     {
//         ans.push_back(sum);
//         return;
//     }

//     sums(arr, ans, sum + arr[index], index + 1);
//     sums(arr, ans, sum, index + 1);
// }
// vector<int> subsetSums(vector<int> &arr)
// {
//     // code here
//     vector<int> ans;
//     sums(arr, ans, 0, 0);
//     return ans;
// }

// void subsetsWithDuprecursion(int index, vector<int> &nums,
//                              vector<vector<int>> &ans, vector<int> &temp)
// {

//     ans.push_back(temp);

//     for (int i = index; i < nums.size(); i++)
//     {

//         if (i > index && nums[i] == nums[i - 1])
//         {
//             continue;
//         }

//         temp.push_back(nums[i]);
//         subsetsWithDuprecursion(i + 1, nums, ans, temp);
//         temp.pop_back();
//     }
// }

// vector<vector<int>> subsetsWithDup(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     vector<vector<int>> ans;
//     vector<int> temp;
//     subsetsWithDuprecursion(0, nums, ans, temp);
//     return ans;
// }
// void permutations(vector<int> &nums, vector<int> &temp, vector<vector<int>>
// &ans, vector<int> freq)
// {
//     if (temp.size() == nums.size())
//     {
//         ans.push_back(temp);
//         return;
//     }
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (!freq[i])
//         {
//             freq[i] = 1;
//             temp.push_back(nums[i]);
//             permutations(nums, temp, ans, freq);
//             freq[i] = 0;
//             temp.pop_back();
//         }
//     }
// }
// vector<vector<int>> permute(vector<int> &nums)
// {
//     vector<vector<int>> ans;
//     vector<int> temp;

//     vector<int> freq(nums.size(), 0);

//     permutations(nums, temp, ans, freq);

//     return ans;
// }
// bool ispalindrome(string s, int start, int end)
// {
//     while (start <= end)
//     {
//         if (s[start++] != s[end--])
//         {
//             return false;
//             break;
//         }
//     }
//     return true;
// }
// void func(int index, string s, vector<vector<string>> &ans, vector<string>
// &temp)
// {
//     if (index == s.size())
//     {
//         ans.push_back(temp);
//         return;
//     }

//     for (int i = index; i < s.size(); i++)
//     {
//         if (ispalindrome(s, index, i))
//         {
//             temp.push_back(s.substr(index, i - index + 1));
//             func(i + 1, s, ans, temp);
//             temp.pop_back();
//         }
//     }
// }

// vector<vector<string>> partition(string s)
// {

//     vector<vector<string>> ans;
//     vector<string> temp;
//     func(0, s, ans, temp);
//     return ans;
// }

// void ratinmaze(int i, int j, vector<vector<int>> &mat, vector<string> &ans,
// string s, int n, vector<vector<int>> &freq)
// {
//     if (i == n - 1 && j == n - 1)
//     {
//         ans.push_back(s);
//         return;
//     }

//     string dir = "DLRU";
//     int di[] = {1, 0, 0, -1};
//     int dj[] = {0, -1, 1, 0};

//     for (int idx = 0; idx < 4; idx++)
//     {
//         int ni = i + di[idx];
//         int nj = j + dj[idx];

//         if (ni >= 0 && nj >= 0 && ni < n && nj < n && !freq[ni][nj] &&
//         mat[ni][nj] == 1)
//         {
//             freq[ni][nj] = 1;
//             ratinmaze(ni, nj, mat, ans, s + dir[idx], n, freq);
//             freq[ni][nj] = 0;
//         }
//     }
// }

// vector<string> findPath(vector<vector<int>> &mat)
// {
//     vector<string> ans;
//     string s = "";
//     int n = mat.size();
//     vector<vector<int>> freq(n, vector<int>(n, 0));

//     if (mat[0][0] == 1)
//     {
//         freq[0][0] = 1;
//         ratinmaze(0, 0, mat, ans, s, n, freq);
//     }

//     return ans;
// }

// // bool Subsequences(vector<int> &arr, int index, int sum, int k, int n)
// // {
// //     if (index == n)
// //     {

// //         if (sum == k)
// //         {
// //             return true;
// //         }
// //         return false;
// //     }

// //     sum += arr[index];
// //     if (Subsequences(arr, index + 1, sum, k, n))
// //     {
// //         return true;
// //     }

// //     sum -= arr[index];
// //     if (Subsequences(arr, index + 1, sum, k, n))
// //     {
// //         return true;
// //     }

// //     return false;
// // }

// // bool isSubsetPresent(int n, int k, vector<int> &a)
// // {

// //     return Subsequences(a, 0, 0, k, n);
// // }

// // vector<int> buildArray(vector<int> &nums)
// // {

// //     vector<int> ans(nums.size());

// //     for (int i = 0; i < nums.size(); i++)
// //     {
// //         /* code */
// //         ans[i] = nums[nums[i]];
// //     }

// //     return ans;
// // }

// vector<int> buildArray(vector<int> &nums)
// {

//     for (int i = 0; i < nums.size(); i++)
//     {
//         /* code */
//         swap(nums[i], nums[nums[i]]);
//     }

//     return nums;
// }

// void hanoi(int n, char source, char helper, char destination)
// {
//     if (n <= 0)
//     {
//         return;
//     }

//     hanoi(n - 1, source, destination, helper);

//     cout << "Move disk from " << source << " to " << destination << endl;
//     hanoi(n - 1, helper, source, destination);
// }

// bool reachDestination(int sx, int sy, int dx, int dy)
// {
//     while (dx >= sx && dy >= sy)
//     {
//         if (dx == sx && dy == sy)
//             return true;

//         if (dx > dy)
//             dx -= dy;
//         else
//             dy -= dx;
//     }
//     return false;
// }

// void findallPaths_solve(string &path, vector<string> &ans,
// vector<vector<bool>> &arr, vector<vector<bool>> &visited, int x, int y, int
// n, int m)
// {

//     if (x < 0 || y < 0 || x >= n || y >= m || !arr[x][y] || visited[x][y])
//     {
//         return;
//     }

//     if (x == n - 1 && y == m - 1)
//     {
//         ans.push_back(path);
//         return;
//     }

//     visited[x][y] = true;

//     path.push_back('D');
//     findallPaths_solve(path, ans, arr, visited, x + 1, y, n, m);
//     path.pop_back();

//     path.push_back('U');
//     findallPaths_solve(path, ans, arr, visited, x - 1, y, n, m);
//     path.pop_back();

//     path.push_back('R');
//     findallPaths_solve(path, ans, arr, visited, x, y + 1, n, m);
//     path.pop_back();

//     path.push_back('L');
//     findallPaths_solve(path, ans, arr, visited, x, y - 1, n, m);
//     path.pop_back();

//     visited[x][y] = false;
// }

// vector<string> findAllPaths(vector<vector<bool>> &arr)
// {
//     vector<string> ans;

//     if (arr.empty() || arr[0].empty() || !arr[0][0])
//     {
//         return ans;
//     }

//     int n = arr.size();
//     int m = arr[0].size();

//     vector<vector<bool>> visited(n, vector<bool>(m, false));
//     string path;

//     findallPaths_solve(path, ans, arr, visited, 0, 0, n, m);

//     return ans;
// }

// void clearScreen()
// {
// #ifdef _WIN32
//     system("cls"); // Windows
// #else
//     system("clear"); // Linux/MacOS
// #endif
// }

// class Base
// {
// public:
//     virtual void show(){
//         cout<<"Base"<<endl;
//     }
// };

// class Derived : public Base
// {
// public:
//     void show() override
//     {
//         cout << "Derived class is derived from the base class." << endl;
//     }
// };

// class A {
// public:
//     void printmsg() { cout << "msg from person A\n"; }
// };

// class C :virtual public A {
// public:
//     void printmsg() { cout << "msg from person C\n"; }
// };

// class B : virtual public A {
// public:
//     void printmsg() { cout << "msg from person B\n"; }
// };

// class D : public C, public B {
// public:
//     void printmsg() { cout << "msg from person D\n"; }
// };

// #include<fstream>
// int main(){
//    ifstream infile;
//    infile.open("input.txt",ios::in);

//    ofstream outfile;
//    outfile.open("output.txt",ios::app | ios::out);

//    if (!infile.is_open() or !outfile.is_open())
//    {
//     cerr<<"File not opened!!\n";
//     return 0;
//    }

//    cout<<"Writing\n";
//    string line;
//    while (getline(infile,line))
//    {
//     cout<<line<<endl;
//     outfile<<line<<endl;
//    }

// infile.close();
// outfile.close();
// return 0;

// }

#include "bits/stdc++.h"
#include <iostream>

using namespace std;
/*
* * * * * 
 * * * * 
  * * * 
   * * 
    * 
 */
// void print() {
//   for (int i = 0; i < 5; i++) {

//     for (int j = 0; j < i; j++) {
//       cout << " ";
//     }
//     for (int j = 1; j < 6 - i; j++) {
//       cout << "* ";
//     }

//     cout << "\n";
//   }
// }
/* 
* * * * 
 * * * * 
  * * * * 
   * * * * 
    * * * * 

 */

//  void print(){
//     for (int i = 0; i < 5; i++) {
//     for(int j=0;j<i;j++){
//         cout<<" ";
//     }
//     for (int j = 0; j < 4; j++) {
//       cout << "* ";
//     }
//     cout<<endl;
//   }
//  }
/* 
    
   * 
  * * 
 * * * 
* * * * 
 * * * 
  * * 
   * 
*/

// void print(){
//     for(int i=0;i<5;i++){
//         for(int j=0;j<4-i;j++){
//             cout<<" ";
//         }
//         for(int j=0;j<i;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     for(int i=0;i<3;i++){
//         for(int j=0;j<=i;j++){
//             cout<<" ";
//         }
//         for(int j=3;j>i;j--){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

/* 
* * * * * 
*       * 
*       * 
*       * 
* * * * * 
*/
// void print() {

//   for (int i = 0; i < 5; i++) {
//     for (int j = 0; j < 5; j++) {
//       if (j == 0 or j == 4 or i == 0 or i == 4) {
//         cout << "* ";
//       } else {
//         cout << "  ";
//       }
//     }
//     cout << endl;
//   }
// }

/* 
    * 
   * * 
  *   * 
 *     * 
* * * * *
*/
// void print(){
    
//     for(int i=0;i<=4;i++){
//         for(int j=0;j<4-i;j++){
//             cout<<" ";
//         }
//         for(int j=0;j<=i;j++){
//             if (i==0 or i==4 or j==0 or j==i) {
//             cout<<"* ";
//             }
//             else {
//             cout<<"  ";
//             }
//         }
//         cout<<endl;
//     }
    
// }

// void print(){
//     for(int i=0;i<=4;i++){
//         for(int j=0;j<=i;j++){
//             cout<<" ";
//         }
//         for(int j=4;j>=0;j--){
//             if (i==0 or i==4 or j==0 or j==i) {
//             cout<<"* ";
//             }
//             else {
//             cout<<"  ";
//             }
//         }
//         cout<<endl;
//     }
// }

void print(){
    int n = 5;
    for(int i = n; i >= 1; i-=2)
    {
        for(int j = 0; j < (n-i)/2;j++){
            cout << "  ";
        }
        for(int j = 0;j < i; j++){
            cout << "* ";
        }
        cout << endl;
    }

    for(int i = 3; i <= n; i+=2)
    {
        for(int j = 0; j < (n-i)/2;j++){
            cout << "  ";
        }
        for(int j = 0;j < i; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
  print();
}

