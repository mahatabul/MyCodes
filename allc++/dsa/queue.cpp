#include <bits/stdc++.h>
using namespace std;

// stack using array
// class MyQueue
// {
// private:
//     int arr[100005];
//     int front;
//     int rear;

// public:
//     MyQueue()
//     {
//         front = 0;
//         rear = 0;
//     }
//     void push(int);
//     int pop();
// };

// // Function to push an element x in a queue.
// void MyQueue ::push(int x)
// {
//     if (rear < 100005)
//     {
//         arr[rear] = x;
//         rear++;
//     }
// }

// int MyQueue ::pop()
// {
//     if (front == rear)
//     {
//         return -1;
//     }
//     int el = arr[front];
//     front++;
//     return el;
// }

int main()
{
    queue<int> q1;

    q1.push(1);
    q1.push(2);
    q1.push(3);
    int t = q1.size() - 1;
    while (t--)
    {
        int x = q1.front();
        q1.pop();
        q1.push(x);
    }
    t = q1.size();
    while (!q1.empty())
    {
        cout << q1.front() << "\n";
        q1.pop();
    }

    return 0;
}
