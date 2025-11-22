#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int lengthOfLongestSubstring(string s)
{

    int l = 0, r = 0, maxlength = 0;
    map<char, int> hmap;
    while (r < s.size())
    {
        hmap[s[r]]++;

        while (hmap[s[r]] > 1)
        {
            hmap[s[l]]--;
            l++;
        }

        maxlength = max(maxlength, r - l + 1);
        r++;
    }

    return maxlength;
}

int longestKSubstr(string &s, int k)
{
    // your code here
    int l = 0, maxlen = -1;

    map<char, int> hmap;
    for (int r = 0; r < s.size(); r++)
    {
        hmap[s[r]]++;

        if (hmap.size() > k)
        {
            hmap[s[l]]--;
            if (hmap[s[l]] == 0)
            {
                hmap.erase(s[l]);
            }
            l++;
        }

        if (hmap.size() == k)
        {
            maxlen = max(maxlen, r - l + 1);
        }
    }
    return maxlen;
}

int longestOnes(vector<int> &nums, int k)
{
    int ans = 0;
    int l = 0;
    int ktemp = 0;

    for (int r = 0; r < nums.size(); r++)
    {

        if (nums[r] == 0)
        {
            ktemp++;
        }

        while (ktemp > k)
        {
            if (nums[l] == 0)
            {
                ktemp--;
            }
            l++;
        }

        ans = max(ans, r - l + 1);
    }
    return ans;
}

int totalElements(vector<int> &arr)
{
    // code here

    int l = 0, maxlen = 0;
    map<int, int> mp;
    for (int r = 0; r < arr.size(); r++)
    {
        mp[arr[r]]++;

        if (mp.size() > 2)
        {
            mp[arr[l]]--;
            if (mp[arr[l]] == 0)
            {
                mp.erase(arr[l]);
            }
            l++;
        }
        if (mp.size() <= 2)
        {
            maxlen = max(maxlen, r - l + 1);
        }
    }

    return maxlen;
}

int solve(vector<int> &s, int k)
{
    int l = 0, maxlen = 0;

    map<int, int> hmap;
    for (int r = 0; r < s.size(); r++)
    {
        hmap[s[r]]++;

        while (hmap.size() > k)
        {
            hmap[s[l]]--;
            if (hmap[s[l]] == 0)
            {
                hmap.erase(s[l]);
            }
            l++;
        }

        maxlen += r - l + 1;
    }
    return maxlen;
}
int subarraysWithKDistinct(vector<int> &s, int k)
{
    return solve(s, k) - solve(s, k - 1);
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{

    map<int, int> presum;
    presum[0] = 1;
    int sum = 0, ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (presum.find(sum - goal) != presum.end())
        {
            ans += presum[sum - goal];
        }

        presum[sum]++;
    }

    return ans;
}

int maxScore(vector<int> &cp, int k)
{

    int ans = 0;
    int l = k - 1, r = cp.size() - 1;
    for (int i = 0; i < k; i++)
    {
        ans += cp[i];
    }

    int curr = ans;

    while (k != 0)
    {
        curr -= cp[l];
        l--;
        curr += cp[r];
        r--;
        k--;

        ans = max(ans, curr);
    }

    return ans;
}

int numberOfSubstrings(string s)
{

    vector<int> c(3, -1);
    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        c[s[i] - 'a'] = i;

        int mini = min({c[0], c[1], c[2]});
        ans += (1 + mini);
    }
    return ans;
}

int numberOfSubarrays(vector<int> &nums, int goal)
{

    map<int, int> presum;
    presum[0] = 1;
    int sum = 0, ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] & 1)
        {
            sum++;
        }

        if (presum.find(sum - goal) != presum.end() and sum >= goal)
        {
            ans += presum[sum - goal];
        }

        presum[sum]++;
    }

    return ans;
}

int characterReplacement(string s, int k)
{

    map<char, int> hp;
    int ans = 0;

    int maxfreq = 0, l, r;
    l = r = 0;

    while (r < s.size())
    {
        hp[s[r]]++;

        maxfreq = max(maxfreq, hp[s[r]]);

        if ((r - l + 1) - maxfreq <= k)
        {
            ans = max(ans, r - l + 1);
        }
        while ((r - l + 1) - maxfreq > k)
        {
            hp[s[l]]--;
            for (char i = 'A'; i <= 'Z'; i++)
            {
                maxfreq = max(maxfreq, hp[i]);
            }

            l++;
        }

        r++;
    }

    return ans;
}

bool exist(string s, string t)
{
    int m = s.size(), n = t.size();
    int j = 0;

    for (int i = 0; i < m && j < n; i++)
    {
        if (s[i] == t[j])
        {
            j++;
        }
    }

    return j == n;
}

string minWindow(string s, string t)
{
    if (t.size() > s.size())
    {
        return "";
    }

    map<char, int> h1, h2;

    for (char c : t)
    {
        h1[c]++;
    }
    int requiredsize = h1.size(), havesize = 0, l = 0, r = 0, minlen = INT_MAX, start = -1;

    while (r < s.size())
    {
        h2[s[r]]++;
        if (h1.count(s[r]) and h2[s[r]] == h1[s[r]])
        {
            havesize++;
        }

        while (havesize == requiredsize)
        {
            if (r - l + 1 < minlen)
            {
                minlen = r - l + 1;
                start = l;
            }

            h2[s[l]]--;
            if (h1.count(s[l]) and h2[s[l]] < h1[s[l]])
            {
                havesize--;
            }
            l++;
        }
        r++;
    }

    if (minlen == INT_MAX)
    {
        /* code */
        return "";
    }
    return s.substr(start, minlen);
}

string solve(string s, string t)
{
    // Write your Code here
    if (t.size() > s.size())
    {
        return "";
    }

    map<char, int> h1, h2;

    for (char c : t)
    {
        h1[c]++;
    }
    int requiredsize = h1.size(), havesize = 0, l = 0, r = 0, minlen = INT_MAX, start = -1;

    while (r < s.size())
    {
        h2[s[r]]++;
        if (h1.count(s[r]) and h2[s[r]] == h1[s[r]])
        {
            havesize++;
        }

        if (havesize == requiredsize and exist(s.substr(l, r + 1), t))
        {

            if (r - l + 1 < minlen)
            {
                minlen = r - l + 1;
                start = l;
            }
            while (havesize == requiredsize and exist(s.substr(l, r + 1), t))
            {
                /* code */
                h2[s[l]]--;
                
            }
            

        }

        r++;
    }

    if (minlen == INT_MAX)
    {
        /* code */
        return "";
    }
    return s.substr(start, minlen);
}
int main()
{
    string s = "goodbye", t = "be";
    cout << solve(s, t);

    return 0;
}