#include <bits/stdc++.h>
using namespace std;

#include <map>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key;
        int value;
        Node *next;
        Node *prev;

        Node(int key1, int value1)
        {
            key = key1;
            value = value1;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node *head;
    Node *tail;
    int capacity;
    map<int, Node *> hmap;

    LRUCache(int capacity)
    {
        this->capacity = capacity;

       
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *newNode)
    {
        Node *temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        if (temp)
        {
            temp->prev = newNode;
        }
    }

    void deleteNode(Node *delNode)
    {
        Node *prevNode = delNode->prev;
        Node *nextNode = delNode->next;

        if (prevNode)
        {
            prevNode->next = nextNode;
        }
        if (nextNode)
        {
            nextNode->prev = prevNode;
        }
    }

    int get(int key)
    {
        if (hmap.find(key) != hmap.end())
        {
            Node *targetNode = hmap[key];
            int result = targetNode->value;

            deleteNode(targetNode);
            addNode(targetNode);
            hmap[key] = head->next;

            return result;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (hmap.find(key) != hmap.end())
        {

            Node *existingNode = hmap[key];
            deleteNode(existingNode);
            hmap.erase(key);
        }

        if (hmap.size() == capacity)
        {

            hmap.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node *newNode = new Node(key, value);
        addNode(newNode);
        hmap[key] = newNode;
    }
};
