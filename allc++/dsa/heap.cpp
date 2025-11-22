#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap
{
    int *harr;
    int capacity;
    int heap_size;

public:
    MinHeap(int capacity)
    {
        capacity = capacity;
        heap_size = 0;
        harr = new int[capacity];
    }

    int getMin() { return harr[0]; }
    int parent(int i) { return (i - 1) / 2; }
    int leftchild(int i) { return 2 * i + 1; }
    int rightchild(int i) { return 2 * i + 2; }

    void insertKey(int a)
    {

        if (heap_size == capacity)
        {
            cout << "Overflow!!\n";
            return;
        }

        heap_size++;
        int i = heap_size - 1;
        harr[i] = a;
        while (i != 0 and harr[parent(i)] > harr[i])
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }

    void decreaseKey(int i, int val)
    {
        harr[i] = val;
        while (i != 0 and harr[parent(i)] > harr[i])
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }

    void MinHeapify(int i)
    {
        int l = leftchild(i), r = rightchild(i);

        int smallest = i;

        if (l < heap_size and harr[l] < harr[i])
        {
            smallest = l;
        }
        if (r < heap_size and harr[r] < harr[smallest])
        {
            smallest = r;
        }

        if (smallest != i)
        {
            swap(&harr[i], &harr[smallest]);
            MinHeapify(smallest);
        }
    }

    int extractMin()
    {
        if (heap_size <= 0)
        {
            return INT_MAX;
        }
        if (heap_size == 1)
        {
            heap_size--;
            return harr[heap_size];
        }

        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);

        return root;
    }

    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
};

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < n and arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n and arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapsort(vector<int> &arr, int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    vector<int> arr = {4, 7, 1, 2, 9, 3, 0, 6, 5, 8};

    cout << "Before\n";
    for (auto it : arr)
    {
        cout << it << " ";
    }

    heapsort(arr, arr.size());
    
    cout << "\nAfter\n";
    for (auto it : arr)
    {
        cout << it << " ";
    }

  

    return 0;
}