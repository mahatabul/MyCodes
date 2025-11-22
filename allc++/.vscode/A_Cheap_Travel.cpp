#include<iostream>
using namespace std;

int main(){
    long int n,m,a,b,tr,sum=0;

    cin>>n>>m>>a>>b;
    tr =n;
    // checking expense per travel , the cheaper the better
    if ((b/m)<a)
    {
      
       sum += (tr/m)*b;
       tr%=m;
       if (tr!=0)
       {
        
       if ((tr*a)<=b)
       {
        sum+=(tr*a);
       }
       else sum+=b;
       }
       
       
    }

    else{
      
      sum+=(tr*a);
    }

    
cout<<sum<<endl;
   

}