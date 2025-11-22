#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertarrLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}
int lengthofLL(Node *head)
{
    Node *temp = head;
    int cnt = 0;

    while (temp != nullptr)
    {

        temp = temp->next;
        cnt++;
    }

    return cnt;
}

void printLL(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *deletehead(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node *deletetail(Node *head)
{
    if (head == NULL or head->next == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}
void deletenode(Node *node)
{
    Node *nextNode = node->next;
    node->data = node->next->data;
    node->next = node->next->next;
    delete nextNode;
}
Node *deleteNode(Node *head, int pos)
{
    if (head == nullptr || pos < 0)
    {

        return head;
    }

    if (pos == 0)
    {
        head = head->next;
        return head;
    }
    Node *temp = head;
    Node *prev = nullptr;
    int cnt = 0;

    while (temp != nullptr && cnt < pos)
    {
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    if (temp == nullptr)
    {
        return head;
    }

    prev->next = temp->next;
    delete temp;

    return head;
}

Node *removeEl(Node *head, int el)
{
    if (head == nullptr)
    {

        return head;
    }

    if (head->data == el)
    {
        head = head->next;
        return head;
    }
    Node *temp = head;
    Node *prev = nullptr;

    while (temp != nullptr)
    {
        if (temp->data == el)
        {
            prev->next = temp->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}

Node *insertathead(Node *head, int k)
{
    Node *temp = new Node(k);
    // temp->data=k;

    temp->next = head;
    return temp;
}

Node *inserttail(Node *head, int el)
{
    if (head == NULL)
    {
        return new Node(el);
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *newnode = new Node(el);
    temp->next = newnode;

    return head;
}

Node *insertatposition(Node *head, int val, int k)
{
    // k++;

    if (head == nullptr)
    {
        return new Node(val);
    }
    if (k == 1)
    {
        Node *newhead = new Node(val, head);
        return newhead;
    }

    int cnt = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        cnt++;

        if (cnt == k - 1)
        {
            Node *newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;

            return head;
        }
        temp = temp->next;
    }

    return head;
}

Node *insertvalLL(Node *head, int val, int el)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->data == el)
    {
        Node *newNode = new Node(val, head);

        return newNode;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->data == el)
        {
            Node *newnode = new Node(val, temp->next);
            temp->next = newnode;
            return head;
        }

        temp = temp->next;
    }

    return head;
}

bool searchKey(int n, Node *head, int key)
{
    // Code here
    Node *temp = head;
    bool f = false;

    while (temp->next != nullptr)
    {

        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }

    return f;
}

Node *addTwoNumbers(Node *nums1, Node *nums2)
{
    // Write your code here.
    Node *dummy = new Node(-1);
    Node *current = dummy;
    Node *t1 = nums1;
    Node *t2 = nums2;
    int carry = 0;
    while (t1 != nullptr or t2 != nullptr)
    {
        /* code */
        int sum = carry;
        if (t1)
        {
            sum += t1->data;
        }
        if (t2)
        {
            sum += t2->data;
        }
        Node *newNode = new Node(sum % 10);
        current->next = newNode;
        current = current->next;
        if (t1)
        {
            t1 = t1->next;
        }
        if (t2)
        {
            t2 = t2->next;
        }

        carry = sum / 10;
    }
    if (carry)
    {
        current->next = new Node(carry);
    }
    return dummy->next;
}

Node *oddEvenList(Node *head)
{
    // Write your code here.
    if (!head || !head->next)
    {
        return head;
    }
    Node *temp1 = head;
    Node *temp2 = head->next;
    Node *evenHead = temp2;

    while (temp2 and temp2->next)
    {
        temp1->next = temp1->next->next;
        temp2->next = temp2->next->next;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    temp1->next = evenHead;

    return head;
}

Node *sortZerosOnesAndTwos(Node *head)
{

    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneTail = oneHead;
    Node *twoTail = twoHead;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroTail->next = temp;
            zeroTail = zeroTail->next;
        }
        else if (temp->data == 1)
        {
            oneTail->next = temp;
            oneTail = oneTail->next;
        }
        else
        {
            twoTail->next = temp;
            twoTail = twoTail->next;
        }
        temp = temp->next;
    }

    zeroTail->next = NULL;
    oneTail->next = NULL;
    twoTail->next = NULL;

    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }

    if (twoHead->next != NULL)
    {
        oneTail->next = twoHead->next;
    }

    Node *newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}

Node *reverseLL(Node *head)
{
    Node *prev = NULL;
    Node *temp = head;
    Node *front;

    while (temp != NULL)
    {
        front = temp->next;

        temp->next = prev;

        prev = temp;
        temp = front;
    }

    return prev;
}

bool isPalindrome(Node *head)
{
    // write your code here
    Node *fast = head;
    Node *slow = head;

    while (fast->next != nullptr and fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newhead = reverseLL(slow->next);
    Node *first = head;
    Node *second = newhead;
    while (second != nullptr)
    {
        if (first->data != second->data)
        {
            reverseLL(newhead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseLL(newhead);
    return true;
}

Node *addOne(Node *head)
{
    if (head == nullptr)
        return nullptr;

    head = reverseLL(head);

    Node *temp = head;
    int carry = 1;

    while (temp != nullptr)
    {
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;

        if (carry == 0)
            break;

        if (temp->next == nullptr && carry > 0)
        {

            temp->next = new Node(carry);
            carry = 0;
        }

        temp = temp->next;
    }

    return reverseLL(head);
}

Node *findMiddle(Node *head)
{
    // Write your code here
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *t1 = headA;
    ListNode *t2 = headB;

    while (t1 != t2)
    {
        t1 = (t1 == NULL) ? headB : t1->next;
        t2 = (t2 == NULL) ? headA : t2->next;
    }

    return t1;
}

bool detectCycle(Node *head)
{
    //	Write your code here
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr and fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int lengthOfLoop(Node *head)
{
    // Write your code here
    Node *slow = head;
    Node *fast = head;
    int cnt = 0;

    while (fast != nullptr and fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cnt = 1;
            fast = fast->next;
            break;
        }
    }
    if (cnt == 0)
    {
        return 0;
    }

    while (slow != fast)
    {
        cnt++;
        fast = fast->next;
    }

    return cnt;
}

Node *deleteMiddle(Node *head)
{
    // Write your code here.

    if (head == nullptr or head->next == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;
    fast = fast->next->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *middle = slow->next;

    slow->next = slow->next->next;

    delete middle;

    return head;
}

Node *firstNode(Node *head)
{
    //    Write your code here.
    Node *slow = head;
    Node *fast = head;
    bool d = false;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return NULL;
}

Node *getKnode(Node *head, int k)
{
    int cnt = 1;
    Node *temp = head;
    while (cnt < k && temp != nullptr)
    {
        /* code */
        cnt++;
        temp = temp->next;
    }

    return temp;
}

Node *kReverse(Node *head, int k)
{
    if (!head || k <= 1)
    {
        return head; // No reversal needed if list is empty or k <= 1
    }

    Node *temp = head;
    Node *prev = nullptr;
    Node *newHead = nullptr;

    while (temp != nullptr)
    {
        Node *tempHead = temp;
        Node *kthNode = getKnode(temp, k);

        if (kthNode == nullptr)
        {

            if (prev != nullptr)
            {
                prev->next = temp;
            }
            break;
        }

        Node *nextGroup = kthNode->next;
        kthNode->next = nullptr;

        Node *reversedHead = reverseLL(tempHead);

        if (newHead == nullptr)
        {
            newHead = reversedHead;
        }
        else
        {
            prev->next = reversedHead;
        }

        prev = tempHead;
        temp = nextGroup;
    }

    return newHead;
}

Node *rotate(Node *head, int k)
{
    // Write your code here.
    int len = lengthofLL(head);
    if (head == nullptr or head->next == nullptr or k < 1 or k == len or k % len == 0)
    {
        return head;
    }
    k %= len;

    Node *exHead = head;

    int n = len - k;
    Node *temp = head;
    int t = n - 1;
    while (t--)
    {
        temp = temp->next;
    }
    Node *Newhead = temp->next;
    Node *exTail = temp->next;
    while (exTail->next != nullptr)
    {
        /* code */
        exTail = exTail->next;
    }

    temp->next = nullptr;
    exTail->next = exHead;

    return Newhead;
}

Node *mergerwosortedlists(Node *head1, Node *head2)
{
    Node *dummynode = new Node(-1);
    Node *t = dummynode;

    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 != nullptr and temp2 != nullptr)
    {
        /* code */
        if (temp1->data <= temp2->data)
        {
            /* code */
            t->next = temp1;
            t = temp1;
            temp1 = temp1->next;
        }
        else
        {
            t->next = temp2;
            t = temp2;
            temp2 = temp2->next;
        }
    }

    if (temp1 != nullptr)
    {
        /* code */
        t->next = temp1;
    }
    else
    {
        t->next = temp2;
    }

    return dummynode->next;
}

Node *sortList(Node *head)
{

    if (!head or head->next == nullptr)
    {
        return head;
    }
    Node *left = head;
    Node *middle = findMiddle(head);
    Node *right = middle->next;
    middle->next = nullptr;

    left = sortList(left);
    right = sortList(right);

    return mergerwosortedlists(left, right);
}

// void insertbetween(Node *head)
// {
//     Node *temp = head;

//     while (temp != nullptr)
//     {
//         Node *newNode = new Node(temp->data);
//         newNode->next = temp->next;
//         temp->next = newNode;

//         temp = temp->next->next;
//     }
// }
// void copyrandomnode(Node *head)
// {
//     Node *temp = head;

//     while (temp != nullptr)
//     {
//         Node *copyNode = temp->next;
//         if (temp->random)
//         {
//             copyNode->random = temp->random->next;
//         }
//         else
//         {
//             copyNode->random = nullptr;
//         }

//         temp = temp->next->next;
        
//     }
// }

// Node* deepcopy(Node* head){
//     Node* dnode=new Node(-1);
//     Node* res=dnode;
//     Node* temp=head;

//     while (temp!=nullptr)
//     {
//         res->next=temp->next;
//         temp->next=temp->next->next;

//         res=res->next;
//         temp=temp->next;
//     }
//     return dnode->next;
// }
int main()
{
    vector<int> arr = {1, 3, 5};
    vector<int> arr2 = {2, 4, 7};

    // Node *head = convertarrLL(arr);
    // Node *head2 = convertarrLL(arr2);

    // cout << "Before\n";
    // printLL(head);
    // cout << "\nAfter\n";
    // head = mergerwosortedlists(head, head2);
    // printLL(head);

    return 0;
}
