#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#define Max_Size 100

int main(){

    int stack[Max_Size];
    int top=-1;

    char exp[Max_Size];

    printf("Enter Postfix expression: ");
    scanf("%[^\n]",exp);

    
    int itr = 0;
    while(exp[itr]!='\0'){
        if (isdigit(exp[itr])){
            int num=0;
            while(isdigit(exp[itr])){
                num = num*10+(exp[itr]-'0');
                itr++;
            }
            stack[++top]=num;

        }
        else if(exp[itr]==' '){
            itr++;
        }
        else{
            int num = 0;
            int val1 = stack[top--];
            int val2 = stack[top--];

            switch(exp[itr]){
                case '+':
                num = val2+val1;
                break;
                case '-':
                num = val2-val1;
                break;
                case '*':
                num = val2*val1;
                break;
                case '/':
                if(val2==0){printf("Error division by zero\n"); return 1;}
                num = val2/val1;
                break;
                default:
                printf("Incorrect operator\n");
                break;
            }
            stack[++top]=num;
            itr++;
        }
       
    }

    printf("The result of (%s) is : %d \n",exp,stack[top]);

    return 0;


}