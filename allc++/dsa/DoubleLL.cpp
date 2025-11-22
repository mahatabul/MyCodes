#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Node
{

public:
    int data;
    Node *next;
    Node *back;
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

void printLL(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *convert_to_DLL(vector<int> a)
{
    Node *head = new Node(a[0]);

    Node *prev = head;

    for (int i = 1; i < a.size(); i++)
    {
        Node *newNode = new Node(a[i], nullptr, prev);
        prev->next = newNode;
        prev = newNode;
    }

    return head;
}

Node *deleteHead(Node *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return nullptr;
    }

    Node *prev = head;

    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;

    return head;
}
Node *deleteTail(Node *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    Node *prev = temp->back;

    prev->next = nullptr;
    temp->back = nullptr;

    delete temp;

    return head;
}

Node *deleteKnode(Node *head, int k)
{
    // for 0 based indexing enable K++
    // k++;
    if (head == nullptr)
    {
        return NULL;
    }
    if (head->next == nullptr and head->back == nullptr)
    {
        return NULL;
    }

    Node *temp = head;
    if (k == 1)
    {
        temp = temp->next;
        temp->back = nullptr;
        head->next = nullptr;
        delete head;
        return temp;
    }

    int cnt = 0;

    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            break;
        }
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *front = temp->next;
    if (front == NULL)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return head;
    }

    front->back = prev;
    prev->next = front;
    delete temp;

    return head;
}

Node *deleteGivenNode(Node *head, int val)
{
    Node *temp = head;

    while (temp->next != nullptr)
    {
        if (temp->data == val)
        {
            break;
        }

        temp = temp->next;
    }

    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == NULL)
    {
        prev->next = nullptr;
        temp->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return head;
    }

    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;

    return head;
}

Node *insertBeforeHead(Node *head, int val)
{
    Node *newNode = new Node(val, head, nullptr);

    head->back = newNode;
    return newNode;
}

Node *reverseDLL(Node *head)
{
    // Write your code here
    if (head == NULL or head->next == nullptr)
    {
        return head;
    }

    Node *last = nullptr;
    Node *current = head;
    while (current != NULL)
    {
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }
    return last->back;
}

Node *deleteAllOccurrences(Node *head, int k)
{

    if (!head)
        return nullptr;

    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == k)
        {
            Node *deleteNode = temp;
            Node *prev = temp->back;
            Node *nextnode = temp->next;

            if (prev == nullptr)
            {
                head = nextnode;
                if (head != nullptr)
                    head->back = nullptr;
            }

            else if (nextnode == nullptr)
            {
                prev->next = nullptr;
            }

            else
            {
                prev->next = nextnode;
                nextnode->back = prev;
            }

            delete deleteNode;
            temp = nextnode;
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}

vector<pair<int, int>> findPairs(Node *head, int k)
{
    // Write your code here.

    vector<pair<int, int>> ans;
    map<int, int> hmap;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data > k)
        {
            break;
        }
        int a, b;
        a = temp->data;

        b = k - a;
        if (hmap.find(b) != hmap.end())
        {
            ans.push_back({b, a});
        }
        hmap[temp->data] = 1;

        temp = temp->next;
    }

    return ans;
}

Node *removeDuplicates(Node *head)
{
    // Write your code here
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    Node *t1 = head;
    Node *t2 = head->next;

    while (t2 != NULL)
    {
        if (t2->data == t1->data)
        {
            t2 = t2->next;
        }
        else
        {
            /* code */
            t1->next = t2;
            t2->back = t1;
            t1 = t2;
            t2 = t2->next;
        }
    }
    t1->next = t2;

    return head;
}


int main()
{
    vector<int> a = {1, 2, 3, 4, 11, 12, 12, 13, 14, 14};

    Node *head = convert_to_DLL(a);
    // cout << "\nBefore\n";
    // printLL(head);
    
    // cout << "\nAfter\n";
    // printLL(head);
   

    return 0;
}