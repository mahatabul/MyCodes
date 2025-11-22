#include<iostream>
#include<string>

using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--)
    {
        string a,b;
        cin>>a;
        cin>>b;
        int a_size = a.size()-1;
        int b_size = b.size()-1;

       if (!a.empty() && !b.empty())
       {
        // for L & M & S
        if (a[a_size]!= b[b_size])
        {
           if (a[a_size]=='L' && b[b_size]=='M')
        {
            cout<<">"<<endl;
        }
        else if (a[a_size]=='M' && b[b_size]=='L')
        {
            cout<<"<"<<endl;
        }
        else if (a[a_size]=='L' && b[b_size]=='S')
        {
            cout<<">"<<endl;
        }
        else if (a[a_size]=='S' && b[b_size]=='L')
        {
            cout<<"<"<<endl;
        }
        else if (a[a_size]=='M' && b[b_size]=='S')
        {
            cout<<">"<<endl;
        }
        else if (a[a_size]=='S' && b[b_size]=='M')
        {
            cout<<"<"<<endl;
        }
       
        }
        else {
            if (a[a_size]=='L' || a[a_size]=='M' || b[b_size]=='L' || b[b_size]=='M')
            {
               if (a_size>b_size)
            {
                cout<<">"<<endl;
            }
            if (a_size<b_size)
            {
                cout<<"<"<<endl;
            }
            if (a_size==b_size)
            {
                cout<<"="<<endl;
            }
            }

            if (a[a_size]=='S'|| b[b_size]=='S')
            {
                if (a_size>b_size)
            {
                cout<<"<"<<endl;
            }
            if (a_size<b_size)
            {
                cout<<">"<<endl;
            }
            if (a_size==b_size)
            {
                cout<<"="<<endl;
            }
            }
            
            
            
            
            
            
        }
        
        
        
        
        

       }
       
    }
    
}