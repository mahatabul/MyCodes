#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    string data;
    Node *next;
    Node *back;
    Node()
    {
        data = "";
        next = nullptr;
        back = nullptr;
    }
    Node(string data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
    Node(string data1, Node *next1)
    {
        data = data1;
        next = next1;
        back = nullptr;
    }
    Node(string data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
};

class Browser
{
    Node* currentpage;
    public:
    
    Browser(string &homepage)
    {
        // Write you code here
        currentpage=new Node(homepage);
        

    }

    void visit(string &url)
    {
        // Write you code here
        Node* newpage=new Node(url);
        currentpage->next=newpage;
        newpage->back=currentpage;
        currentpage=newpage;

        
    }

    string back(int steps)
    {
        // Write you code here
        while (steps)
        {
            if (currentpage->back)
            {
                currentpage=currentpage->back;
                steps--;
            }
            else break;
            
        }
        return currentpage->data;
    }

    string forward(int steps)
    {
        // Write you code here
         while (steps)
        {
            if (currentpage->next)
            {
                currentpage=currentpage->next;
                steps--;
            }
            else break;
            
        }
        return currentpage->data;
    }
};