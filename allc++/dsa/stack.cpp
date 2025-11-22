
// class MyStack
// {
// private:
//     int arr[1000];
//     int top;
// public:
//     MyStack(){top=-1;}
//     int pop();
//     void push(int);
// };

// void MyStack ::push(int x) {
//     // Your Code
//     if (top>=1000)
//     {
//         /* code */
//         return;
//     }

//    top++;
//    arr[top]=x;

// }

// // Function to remove an item from top of the stack.
// int MyStack ::pop() {
//     // Your Code
//     if (top==-1)
//     {
//         return -1;
//     }

//     return arr[top];
//     top--;
// }

// class MyStack
// {
// private:
//     queue<int> q;

// public:
//     MyStack()
//     {
//     }

//     void push(int x)
//     {
//         q.push(x);
//         int t = q.size() - 1;
//         int y;
//         while (t--)
//         {
//             y = q.front();
//             q.pop();
//             q.push(y);
//         }
//     }

//     int pop()
//     {
//         int ans = q.front();
//         q.pop();
//         return ans;
//     }

//     int top()
//     {
//         return q.front();
//     }

//     bool empty()
//     {
//         return q.empty();
//     }
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// class MyQueue
// {
//     private:
//     stack<int> st1,st2;

// public:
//     MyQueue()
//     {
//     }

//     void push(int x)
//     {
//         while (st1.size())
//         {
//             st2.push(st1.top());
//             st1.pop();
//         }
//         st1.push(x);

//          while (st2.size())
//         {
//             st1.push(st2.top());
//             st2.pop();
//         }

//     }

//     int pop()
//     {
//         int ans = st1.top();
//         st1.pop();
//         return ans;
//     }

//     int peek()
//     {
//         return st1.top();
//     }

//     bool empty()
//     {
//         return st1.empty();
//     }
// };

// bool isValid(string s)
// {
//     stack<char> st;

//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == '(' || s[i] == '[' || s[i] == '{')
//         {
//             st.push(s[i]);
//         }
//         else
//         {
//             if (st.empty())
//             {
//                 return false;
//             }
//             if ((s[i] == ']' and st.top() == '[') or
//                 (s[i] == '}' and st.top() == '{') or
//                 (s[i] == ')' and st.top() == '('))
//             {
//                 st.pop();
//             }
//             else
//             {
//                 return false;
//             }
//         }
//     }

//     return st.empty();
// }

// int main()
// {
//     string s = "()";
//     bool t = isValid(s);

//     if (t)
//     {
//         cout << "true";
//     }
//     else
//     {
//         cout << "false";
//     }

//     return 0;
// }

// class MinStack {
//     stack<long long> s; // Use long long to avoid overflow issues
//     long long mini;          // To store the current minimum element

// public:
//     MinStack() {
//         mini = LLONG_MAX; // Initialize mini to the maximum possible value
//     }

//     void push(int val) {
//         if (s.empty()) {
//             s.push(val);
//             mini = val; // Update the minimum
//         } else {
//             if (val >= mini) {
//                 s.push(val); // Push the value normally
//             } else {
//                 s.push(2LL * val - mini); // Push encoded value
//                 mini = val;              // Update the minimum
//             }
//         }
//     }

//     void pop() {
//         if (s.empty()) return;

//         long long topVal = s.top();
//         s.pop();
//         if (topVal < mini) {
//             // If the top is an encoded value, restore the previous minimum
//             mini = 2LL * mini - topVal;
//         }
//     }

//     int top() {
//         if (s.empty()) return -1;

//         long long topVal = s.top();
//         if (topVal >= mini) {
//             return topVal; // Return the actual value
//         } else {
//             return mini; // The current minimum is the actual top value
//         }
//     }

//     int getMin() {
//         return mini; // Return the current minimum
//     }
// };

#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string infixToPostfix(string infix)
{
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> char_stack;
    string output;

    for (int i = 0; i < l; i++)
    {
        if (isalpha(infix[i]) || isdigit(infix[i]))
        {
            output += infix[i];
        }
        else if (infix[i] == '(')
        {
            char_stack.push('(');
        }
        else if (infix[i] == ')')
        {
            while (!char_stack.empty() && char_stack.top() != '(')
            {
                output += char_stack.top();
                char_stack.pop();
            }
            if (!char_stack.empty() && char_stack.top() == '(')
            {
                char_stack.pop();
            }
        }
        else
        {
            while (!char_stack.empty() && isOperator(char_stack.top()) &&
                   (infix[i] == '^' ? getPriority(infix[i]) < getPriority(char_stack.top())
                                    : getPriority(infix[i]) <= getPriority(char_stack.top())))
            {
                output += char_stack.top();
                char_stack.pop();
            }
            char_stack.push(infix[i]);
        }
    }

    while (!char_stack.empty())
    {
        if (char_stack.top() == '(' || char_stack.top() == ')')
        {
            throw runtime_error("Mismatched parentheses in the input string");
        }
        output += char_stack.top();
        char_stack.pop();
    }

    return output;
}

string infixToPrefix(string infix)
{
    int l = infix.size();
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < l; i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

string postToInfix(string exp)
{
    // Write your code here
    int i = 0;
    stack<string> st;
    string ans;

    while (i < exp.size())
    {
        if (isalpha(exp[i]) or isdigit(exp[i]))
        {

            st.push(string(1, exp[i]));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string s = "(" + t2 + exp[i] + t1 + ")";
            st.push(s);
        }

        i++;
    }
    return st.top();
}

string preToInfix(string exp)
{
    // Write your code here
    reverse(exp.begin(), exp.end());
    int i = 0;
    stack<string> st;
    string ans;

    while (i < exp.size())
    {
        if (isalpha(exp[i]) or isdigit(exp[i]))
        {

            st.push(string(1, exp[i]));
        }
        else
        {
            string t2 = st.top();
            st.pop();
            string t1 = st.top();
            st.pop();

            string s = "(" + t2 + exp[i] + t1 + ")";
            st.push(s);
        }

        i++;
    }
    return st.top();
}

string postToPre(string exp)
{
    // Write your code here

    int i = 0;
    stack<string> st;

    while (i < exp.size())
    {
        if (isalpha(exp[i]) or isdigit(exp[i]))
        {

            st.push(string(1, exp[i]));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string s = exp[i] + t2 + t1;
            st.push(s);
        }

        i++;
    }
    return st.top();
}

string preToPost(string exp)
{
    int i = exp.size() - 1;
    stack<string> st;

    while (i >= 0)
    {
        if (isalpha(exp[i]) or isdigit(exp[i]))
        {

            st.push(string(1, exp[i]));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string s = t2 + t1 + exp[i];
            st.push(s);
        }

        i++;
    }
    return st.top();
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> st;
    map<int, int> ans;

    for (int i = nums2.size() - 1; i >= 0; i--)
    {

        while (!st.empty() and st.top() < nums2[i])
        {
            st.pop();
        }

        if (st.empty())
        {

            ans[nums2[i]] = -1;
            st.push(nums2[i]);
            continue;
        }

        ans[nums2[i]] = st.top();

        st.push(nums2[i]);
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        nums1[i] = ans[nums1[i]];
    }

    return nums1;
}

vector<int> nextGreaterElements(vector<int> &nums)
{
    vector<int> ans(nums.size(), -1);
    stack<int> st;
    int N = nums.size();

    for (int i = 2 * N - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % N])
        {
            st.pop();
        }
        if (i < N)
        {
            ans[i] = st.empty() ? -1 : st.top();
        }

        st.push(nums[i % N]);
    }
    return ans;
}

vector<int> findNSE(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> nse(n, n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            nse[i] = st.top();
        }
        st.push(i);
    }

    return nse;
}

vector<int> findPSEE(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> psee(n, -1);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            psee[i] = st.top();
        }
        st.push(i);
    }

    return psee;
}

vector<int> findNGEE(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> ngee(n, n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] < nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            ngee[i] = st.top();
        }
        st.push(i);
    }

    return ngee;
}

vector<int> findPGE(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> pge(n, -1);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            pge[i] = st.top();
        }
        st.push(i);
    }

    return pge;
}

long long sumSubarrayMins(vector<int> &nums)
{
    int mod = (int)1e9 + 7;
    vector<int> nse = findNSE(nums);
    vector<int> psee = findPSEE(nums);

    long long total = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int left = i - psee[i];
        int right = nse[i] - i;

        total = (total + (long long)nums[i] * left * right % mod) % mod;
    }

    return total;
}

long long sumSubarrayMax(vector<int> &nums)
{
    int mod = (int)1e9 + 7;
    vector<int> ngee = findNGEE(nums);
    vector<int> pge = findPGE(nums);

    long long total = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int left = i - pge[i];
        int right = ngee[i] - i;

        total = (total + (long long)nums[i] * left * right % mod) % mod;
    }

    return total;
}

long long subArrayRanges(vector<int> &nums)
{
    long long maxSum = sumSubarrayMax(nums);
    long long minSum = sumSubarrayMins(nums);
    return maxSum - minSum;
}

string removeKdigits(string num, int k)
{
    string ans;
    stack<char> st;
    int numSize = num.size();

    if (k == numSize)
    {
        return "0";
    }

    for (int i = 0; i < numSize; i++)
    {

        while (!st.empty() && k > 0 && st.top() > num[i])
        {
            st.pop();
            k--;
        }

        st.push(num[i]);
    }

    while (k > 0 && !st.empty())
    {
        st.pop();
        k--;
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    auto it = find_if(ans.begin(), ans.end(), [](char c)
                      { return c != '0'; });
    ans.erase(ans.begin(), it);

    if (ans.empty())
    {
        ans = "0";
    }

    return ans;
}

int solving(vector<int> h)
{
    stack<int> st;
    int maxArea = 0;
    int n = h.size();

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and h[st.top()] > h[i])
        {
            int elementIdx = st.top();
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, h[elementIdx] * (nse - pse - 1));
        }

        st.push(i);
    }

    while (!st.empty())
    {
        int nse = n;
        int elementIdx = st.top();
        st.pop();
        int pse = st.empty() ? -1 : st.top();

        maxArea = max(maxArea, h[elementIdx] * (nse - pse - 1));
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{

    int maxArea = 0;
    int row = matrix.size();
    int col = matrix[0].size();

    vector<vector<int>> dp(row, vector<int>(col, 0));

    for (int i = 0; i < col; i++)
    {
        if (matrix[0][i] == '1')
        {
            dp[0][i]++;
        }
    }
    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == '1')
            {
                dp[i][j]++;
                dp[i][j] += dp[i - 1][j];
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        maxArea = max(maxArea, solving(dp[i]));
    }

    return maxArea;
}

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    int idx;
    StockSpanner()
    {
        idx = -1;
    }

    int next(int price)
    {
        idx = idx + 1;
        while (!st.empty() and st.top().first <= price)
        {
            st.pop();
        }
        int ans;
        ans = idx - (st.empty() ? -1 : st.top().second);
        st.push({price, idx});
        return ans;
    }
};

int getmax(queue<int> t)
{
    queue<int> temp = t;
    int maxi = INT_MIN;

    while (!temp.empty())
    {
        maxi = max(maxi, temp.front());
        temp.pop();
    }
    return maxi;
}
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() and dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() and nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1)
        {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}

int celebrity(vector<vector<int>> &arr)
{
    // code here
    int n = arr.size();
    int celebrity = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[celebrity][i] == 1)
        {
            celebrity = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i != celebrity)
        {
            if (arr[celebrity][i] == 1 or arr[i][celebrity] == 0)
            {
                return -1;
            }
        }
    }
    return celebrity;
}
int main()
{

    return 0;
}