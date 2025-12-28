#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000007;
const int base = 52;
vector<int> ans;

int modExp(int a, int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }
    // if n is even
    int half = modExp(a, n / 2);
    int result = (half * half) % MOD;

    // if n is odd
    if (n & 1)
    {
        result *= a;
        result %= MOD;
    }

    return result;
}

int getcode(char a)
{
    if (a >= 'A' and a <= 'Z')
    {
        return a - 'A';
    }
    return a - 'a' + 26;
}

int getHashCode(string z)
{
    int code = 0;
    int len = z.length();

    for (int i = 0; i < len; i++)
    {
        code += (getcode(z[i]) * modExp(base, len - 1 - i));
    }
    return code;
}

bool check(string a, string b)
{
    for (int i = 0; i < b.size(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

void robincarp(string a, string b)
{
    int asize = a.length();
    int bsize = b.length();

    int bhash = getHashCode(b);

    int ahash = 0;
    string s = a.substr(0, bsize);
    ahash = getHashCode(s);

    int highestPower = modExp(base, bsize - 1);

    for (int i = 0; i <= asize - bsize; i++)
    {
        if (ahash == bhash && check(s, b))
            ans.push_back(i);

        if (i < asize - bsize) // Only slide if there's a next window
        {
            ahash -= getcode(a[i]) * highestPower;
            ahash *= base;
            ahash += getcode(a[i + bsize]);
            s = a.substr(i + 1, bsize);
        }
    }
}

int main()
{
    string a = "abcdefgabc", b = "abc";

    robincarp(a, b);

    if (ans.size() == 0)
    {
        cout << "No such pattern found";
    }

    for (auto it : ans)
    {
        cout << "Pattern found at index: " << it << "\n";
    }

    return 0;
}