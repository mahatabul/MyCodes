// #include<stdio.h>
// int main(){
//     printf("Hello World\n");

//     int x;
//     scanf("%d",&x);
//     printf("your number is this: %d",x);
//     return 0;
// }

// #include<stdio.h>

// int main(){
//     int x,y,z,m;
//     scanf("%d %d %d",&x,&y,&z);
//     m = x;

//     if (m>=y)
//     {
//         m=y;
//     }
//     if (m>=z)
//     {
//         m=z;
//     }

//     printf("minimum : %d",m);
//     return 0;

// }

// #include <stdio.h>
// #include <ctype.h>

// int main() {
//     char c;

//     printf("Enter a character: ");
//     scanf(" %c", &c);
//     char d = tolower(c);

//     if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u') {
//         printf("Vowel\n");
//     } else {
//         printf("Consonant\n");
//     }

//     return 0;
// }
// #include <stdio.h>

// int main() {
//     int i;

//     char name[] = "Mahatab";

//     for (i = 0; i < 10; i++) {
//         printf("%s\n", name);
//     }

//     return 0;
// }
// #include <stdio.h>

// int main() {
//     for (int i = 1; i <= 100; i++) {
//         printf("%d\n", i);
//     }

//     return 0;
// }
// #include <stdio.h>

// int main() {
//     char start = 'A';
//     char end = 'Z';

//     for (char ch = start; ch <= end; ch++) {
//         printf("%c ", ch);
//     }

//     printf("\n");

//     return 0;
// }
// #include<stdio.h>

// int main(){
//     for (int i = 1; i > 0; i++)
//     {
//         printf("Mahatab\n");
//     }
//     return 0;
// }
// #include<stdio.h>

// int main(){
//     for(int i=1;i<=100;i++){
//         if(100 % i == 0){
//             printf("%d\n",i);
//         }
//     }
//     return 0;
// }

// #include <stdio.h>

// int main() {
//     for (int i = 1; i <= 5; ++i) {
//
//         for (int j = 1; j <= i; ++j) {
//             printf("#");
//         }
//
//         printf("\n");
//     }

//     return 0;
// }

// #include <stdio.h>

// int main() {
//     for (int i = 5; i >= 1; --i) {

//         for (int j = 1; j <= i; ++j) {
//             printf("# ");
//         }

//         printf("\n");
//     }

//     return 0;
// }

// #include<stdio.h>
// #include<math.h>

// int main(){
//     int number,digit,sum=0,count=0;
//     printf("Enter a number: ");
//     scanf("%d",&number);

//     int original_num = number;

//     while(number !=0 ){
//         number/=10;
//         count++;

//     }
//     printf("count of digits = %d\n",count);

//     number = original_num;

//     for (int  i = 0; i < count; i++)
//     {
//         digit = number % 10;
//         sum = sum + pow(digit, count);
//         number /= 10;

//     }

//     printf("sum = %d\n",sum);
//     printf("original number = %d\n",original_num);

//    if (sum == original_num)
//    {
//     printf("%d is an armstrong number.\n",original_num);

//    }
//    else{
//     printf("False\n");
//    }

//     return 0;
// }
// #include<stdio.h>

// int main(){

//    int n,result=1;
//    printf("Print a number: ");
//    scanf("%d",&n);

//    for(int i=1;i<=n;i++){
//        result*=i;
//    }
//    printf("%d\n",result);
//    return 0;
//}

/*
#include<stdio.h>

int main(){
    long int n,count=0,remain=0,digit;

    printf("Print a number: ");
    scanf("%ld",&n);

    long int number= n;

    do{
        number/=10;
        count++;
    }while(number != 0);

    number= n;
    for(int i=0;i<count;i++){
        digit = number %10;
        remain = remain*10+digit;
        number /=10;

    }
    long int final_result = remain;
    printf("%ld\n",final_result);

    return 0;
}


#include<stdio.h>

int main(){

    int n;
    printf("print a number: ");
    scanf("%d",&n);

    for(int i=10;i>=1;i--){
        printf("%d x %d = %d\n",n,i,n*i);
    }
    return 0;
}


#include<stdio.h>

int main(){

    int s,e,sum=0;
    printf("print start number: ");
    scanf("%d",&s);
    printf("print end number: ");
    scanf("%d",&e);

    for(int i=s;i<=e;i++){
       sum+=i;
    }

    printf("%d\n",sum);
    return 0;
}


#include<stdio.h>

int main(){
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;

}


#include<stdio.h>

int main(){

    int s,e;

    printf("Enter start: ");
    scanf("%d",&s);
    printf("\nEnter end: ");
    scanf("%d",&e);
    for(int i=s;i<=e;i++){
        printf("%d\n",i);
    }

    return 0;
}


#include<stdio.h>
#include<math.h>

float digitcount(int n);
double armcheck(int m, float n );


int main(){
    int n;

    printf("Print a number: ");
    scanf("%d",&n);

    float number_of_digits = digitcount(n);
    double sum = armcheck(n,number_of_digits);

    if(sum == n){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;


}

float digitcount(int n){
    float count =0.0;
    while(n != 0){
        n/=10;
        count++;
    }

    return count;
}
double armcheck(int m, float n ){
    double sum =0.0;
    int digit;
    for(float i=0;i<n;i++){
        digit = m%10;
        sum += pow(digit,n);
        m/=10;
    }

    return sum;

}


#include<stdio.h>
#include<math.h>

void areaofsquare();
void areaofcircle();

int main(){
    int n;

     printf(" 1.area_of_square\n 2.area_of_circle\n Enter an option:  ");

     scanf("%d",&n);
     if(n==1){
        areaofsquare();
     }
     if(n==2){
        areaofcircle();
     }
     return 0;


}
void areaofsquare(){
    double n;
    printf("Print a side of square: ");
    scanf("%lf",&n);

    double result = pow(n,2);
    printf("Area of Square: %lf",result);
}

void areaofcircle(){
    printf("Enter the radius: ");
    double r;
    scanf("%lf",&r);

    double result = 3.14 * r;
    printf("%lf",result);
}



#include<stdio.h>

int main(){
    int n,n1=0,n2=1;
    printf("Enter a number: ");
    scanf("%d",&n);

    printf("%d %d ",n1,n2);
    int next = n1+n2;
    for(int i=2;i<n;i++){
        printf("%d ",next);
        n1=n2;
        n2=next;
        next = n1+n2;
    }


    return 0;
}


#include<stdio.h>

void sum(int n);
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    sum(n);
    return 0;

}
void sum(int n){
    int org,sum=0,count =0,remain;
    org=n;
    while(n!=0){
        n/=10;
        count++;

    }
    n=org;
    for(int i=0;i<count;i++){
         remain = n%10;
         sum+=remain;
         n/=10;
    }

    printf("sum of digits:%d",sum);

}

#include<stdio.h>
double pow(double m,double n);
int main(){
    double m,n;

    printf("Enter base: ");
    scanf("%lf",&m);

    printf("Enter exponent: ");
    scanf("%lf",&n);

    double result = pow(m,n);
    printf("result = %lf",result);
    return 0;

}
double pow(double m,double n){
    if(n<0){
        m= (1/m);
        n= -n;
    }
    double r=1;

    for(double i=1;i<=n;i++){

        r*=m;


    }
    return r;
}


#include<stdio.h>

void square_root(int n);

int main(){
    int n;
    scanf("%d",&n);
    square_root(n);

    return 0;


}
void square_root(int n){
    for(int i=0;i<n;i++){
        if(i*i==n){
            printf("%d",i);}
        }
    }
*/
// #include <stdio.h>

// double mySqrt(double x) {
//     if (x < 0) {
//         printf("Error: Cannot find the square root of a negative number.\n");
//         return -1.0; // Or any other value to indicate an error
//     }

//     double epsilon = 0.000001; // Small value for precision
//     double guess = x / 2.0; // Initial guess, can be any reasonable value

//     while (fabs(guess * guess - x) > epsilon) {
//         guess = 0.5 * (guess + x / guess);
//     }

//     return guess;
// }

// int main() {
//     double num, result;

//     printf("Enter a number: ");
//     scanf("%lf", &num);

//     result = mySqrt(num);

//     if (result != -1.0) {
//         printf("Square root of %.2lf = %.4lf\n", num, result);
//     }

//     return 0;
// }

// #include<stdio.h>

// int sum(int n);

// int main(){
//     int n;
//     printf("Enter: ");
//     scanf("%d",&n);

//     int s =sum(n);

//     printf("result = %d",s);

//     return 0;
// }

// int sum(int n){

//     if(n==1){
//         return 1;
//     }

//     int sm1 = sum(n-1);
//     int smn = sm1 + n;

//     return smn;
// }

// #include<stdio.h>

// int fact(int n);

// int main(){
//     int n;
//     printf("Enter: ");
//     scanf("%d",&n);

//     int f= fact(n);

//     printf("factorial of %d is %d",n,f);

//     return 0;
// }

// int fact(int n){
//     if(n==0){
//         return 1;
//     }
//     int r=1;
//     for(int i=n;i>=1;i--){
//         r*=i;

//     }
//     return r;
// }

// #include<stdio.h>

// int main(){
//     int age = 22;
//     int *p = &age;
//     int _age = *p;

//     printf("%d\n",age);
//     printf("%p\n",&age);
//     printf("%p\n",p);
//     printf("%d\n",_age);

//     return 0;
// }
// #include<stdio.h>

// int main(){
//     int x=2;
//     int *p=&x;

//     *p=22;

//     printf("%d\n",x);
//     printf("%p\n",&x);

//     printf("%d\n",*p);
//     printf("%p\n",p);
// }

// #include<stdio.h>

// int main(){
//     int x=2;
//     int *p;
//     int **pp = &p;

//     p = &x;

//     printf("%d\n",x);
//     printf("%p\n",&x);

//     printf("%d\n",*p);
//     printf("%p\n",&p);

//     printf("%d\n",**pp);
//     printf("%p\n",&pp);
// }
/*
#include<stdio.h>

void square(int n);
void anothersquare(int *n);

int main(){
    int n;
    printf("Enter : ");
    scanf("%d",&n);
    printf("number %d\n ",n);
    square(n);

    anothersquare(&n);
    printf("number %d\n ",n);

    return 0;





}

void square(int n){
    n*=n;

    printf("square = %d\n",n);
}
void anothersquare(int *n){
    (*n)=(*n) * (*n);

    printf("square = %d\n",*n);
}


#include<stdio.h>

int main(){
    int n;
    int m;
    int *np,*mp;

    printf("Enter n: ");
    scanf("%d",&n);

    printf("Enter m: ");
    scanf("%d",&m);
    printf("Before\n");

    printf("n : %d\n",n);
    printf("m : %d\n",m);

    np= &n;
    mp=&m;
    int temp=*np;
    *np=*mp;
    *mp = temp;
    printf("After\n");

    printf("n : %d\n",*np);
    printf("m : %d\n",*mp);

    return 0;
}



#include<stdio.h>

void doit(double a,double b,double *sum,double *prod,double *avg);

int main(){
    double a=1,b=2;
    double sum,prod,avg;

    doit(a,b,&sum,&prod,&avg);
    printf("sum = %lf prod = %lf avg = %lf",sum,prod,avg);
    return 0;


}
void doit(double a,double b,double *sum,double *prod,double *avg){
    *sum = a+b;
    *prod = a*b;
    *avg = (a+b)/2;
}


#include<stdio.h>

int main(){
    int n,m;
    int *np,*mp;

    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter m: ");
    scanf("%d",&m);
    np=&n;
    mp=&m;
    if(*np>*mp){
        printf("Maximum : %d",*np);

    }
    else{
        printf("Maximum : %d",*mp);
    }
    return 0;

}

#include<stdio.h>
#include<stdlib.h>

int main() {
    char* c;
    c = (char*)malloc(sizeof(char));
    *c = 'A';
    while (*c <= 'Z') {
        printf("%c\n", *c);
        *c = *c + 1;
    }
}


#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int* ptr = &arr[n - 1];

    for (int i = 0; i < n; i++) {
        printf("%d\n", *ptr);
        ptr--;
    }

    return 0;
}

#include<stdio.h>

int main(){
    float price[3];
    for(int i=0; i<3; i++){
        printf("Price No. %d: ",i+1);

        scanf("%f", &price[i]);
    }
    for(int i=0; i<3; i++){
        printf("Price No. %d: ",i+1);
        printf("%.4f (with gst)\n", (price[i]+(price[i]*0.18)));
    }
    return 0;
}

#include<stdio.h>

int main(){

    int n=2;
    int m=3;

    int *p=&n,*_p;


    printf("%p %p difference = %p\n",p,_p,p-_p);
    _p=&n;
    printf("compare = %u",p==_p);
}


#include<stdio.h>
void oddcount(int arr[],int n);

int main(){
    int arr[]={1,2,3,4,5,6,7};
    int n= sizeof(arr)/sizeof(arr[0]);
    oddcount(arr,n);


    return 0;
}
void oddcount(int arr[],int n){
    int c=0;

    for(int i=0;i<n;i++){
        if(arr[i]%2!=0){
            c++;
        }
    }
    printf("Odd numbers: %d",c);
}


#include<stdio.h>

void reverseArray(int arr[], int size);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    reverseArray(arr, size);

    printf("\nReversed Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        // Swap elements at start and end indices
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move towards the center
        start++;
        end--;
    }
}



#include<stdio.h>

int main(){
    int arr[2][10];

    for (int  i = 0; i < 1; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            arr[i][j]=2*(j+1);
        }
    }
    for (int  i = 1; i < 2; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            arr[i][j]=3*(j+1);
        }
    }

    printf("Displaying\n");

    for (int  i = 0; i < 2; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d\t",arr[i][j]);

        }
        printf("\n");

    }

    return 0;

}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    printf("Enter: ");
    scanf("%d", &n);
    int number = n;
    //Complete the code to calculate the sum of the five digits on n.
    int c=0,sum=0,digit;
    while (n!=0)
    {
        n/=10;
        c++;

    }

    n=number;

    for(int i=0;i<c;i++){
        digit = n%10;
        sum+=digit;
        n/=10;
    }

    printf("%d",c);



    return 0;
}
*/

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// //Complete the following function.

// void calculate_the_maximum(int n, int k) {
//   //Write your code here.
// }

// int main() {
//     int n, k;

//     scanf("%d %d", &n, &k);
//     calculate_the_maximum(n, k);

//     return 0;
// }

// #include<stdio.h>
// void count(int arr[],int n);

// int main(){
//     int arr[]={1,2,2,2,3,4,5,6,7};
//     int n= sizeof(arr)/sizeof(arr[0]);
//     count(arr,n);

//     return 0;
// }
// void count(int arr[],int n){
//     int c=0;

//     printf("Find = ");
//     int number;
//     scanf("%d",&number);

//     for(int i=0;i<n;i++){
//         if(arr[i]==number){
//             c++;
//         }
//     }
//     printf("number count : %d",c);
// }

// #include<stdio.h>
// void maximum(int arr[],int n);

// int main(){
//     int arr[]={1,2,2,2,3,4,5,6,7};
//     int n= sizeof(arr)/sizeof(arr[0]);
//     maximum(arr,n);

//     return 0;
// }
// void maximum(int arr[],int n){
//     int m = arr[0];

//     for(int i=1;i<n;i++){
//         if(arr[i]>m){
//             m=arr[i];
//         }
//     }
//     printf("maximum element : %d",m);
// }

// #include <stdio.h>

// // Function to insert an element at the end of the array
// void insertAtEnd(int arr[], int *size, int element) {
//     if (*size >= 0) {
//         arr[*size] = element;
//         (*size)++;
//     } else {
//         printf("Array size cannot be negative.\n");
//     }
// }

// int main() {
//     int size, i;

//     // Get the size of the array
//     printf("Enter the size of the array: ");
//     scanf("%d", &size);

//     // Check for a valid size
//     if (size < 0) {
//         printf("Invalid array size. Exiting the program.\n");
//         return 1;
//     }

//     int arr[size];

//     // Input array elements
//     printf("Enter the elements of the array:\n");
//     for (i = 0; i < size; i++) {
//         scanf("%d", &arr[i]);
//     }

//     // Display the original array
//     printf("Original array: ");
//     for (i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }

//     // Insert a new element at the end
//     int newElement;
//     printf("\nEnter the new element to insert at the end: ");
//     scanf("%d", &newElement);

//     insertAtEnd(arr, &size, newElement);

//     // Display the updated array
//     printf("Updated array: ");
//     for (i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// #include<stdio.h>

// int main(){
//     char name[10];
//     scanf("%s",name);

//     printf("%s",name);

//     return 0;
// }

// #include<stdio.h>

// int main(){
//     char name[10];
//     gets(name);

//     puts(name);

//     return 0;
// }

// #include<stdio.h>

// int main(){
//     char name[100];
//     fgets(name,100,stdin);

//     puts(name);

//     return 0;
// }

// #include<stdio.h>

// int main(){
//     char *ptr="Rozin";

//     puts(ptr);

//     ptr = "Safa";

//     puts(ptr);

//     return 0;
// }

// #include<stdio.h>

// int main(){

//     char c[100];

//     gets(c);
//     puts(c);

//     int n=0;
//     int i=0;

//     while (c[i]!='\0')
//     {
//         n++;
//         i++;
//     }

//     printf("\nLen= %d",n);

//     return 0;
// }

// #include<stdio.h>
// #include<string.h>

// int main(){

//     char c[100];

//     gets(c);
//     puts(c);

//     int n=strlen(c);

//     printf("\nLen= %d",n);

//     return 0;
// }

// #include<stdio.h>
// #include<string.h>

// int main(){

//     char name[100]="hello ";
//     char f[]="world";

//     //strcat(name,f);
//     //strcpy(name,f);

//     puts(name);

//     return 0;
// }

// #include<stdio.h>
// #include<string.h>

// int main(){

//     char name[100]="hello ";
//     char f[]="world";

//     //strcat(name,f);
//     //strcpy(name,f);

//     printf("%d",strcmp(name,f));

//     return 0;
// }

// #include<stdio.h>
// #include<string.h>

// int main(){

//     char name[100];

//     char str;
//     int i=0;
//     while (str != '\n')
//     {
//         scanf("%c",&str);
//         name[i]=str;
//         i++;
//     }

//     name[i]='\0';

//     puts(name);

// }

// slicing a string

// #include<stdio.h>
// #include<string.h>

// void slice(char arr[],int n,int m);

// int main(){
//     char str[]="HelloWorld";
//     printf("%s\n",str);
//     int n,m;
//     printf("Enter n & m: ");
//     scanf("%d %d",&n,&m);
//     slice(str,n,m);
//     return 0;
// }

// void slice(char arr[],int n,int m){
//     char sliced[100];
//     int j=0;
//     for( int i=n;i<=m;i++,j++){
//         sliced[j]=arr[i];
//     }
//     sliced[j]='\0';

//     puts(sliced);
// }

// removing blank spaces in a string

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char str[1000];
//     int i, k = 0;

//     printf("Enter the string: ");
//     gets(str);

//     for (i = 0; str[i]; i++) {
//         str[i] = str[i + k];
//         if (str[i] == ' ' || str[i] == '\\t') {
//             k++;
//             i--;
//         }
//     }

//     printf("String after removing all blank spaces: %s", str);
//     return 0;
// }

// highest frequency in a string

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char str[100], result;
//     int i, len;
//     int max = 0;
//     int freq[256] = {0};

//     printf("Enter the string: ");
//     fgets(str, 100, stdin);
//     len = strlen(str);

//     for (i = 0; i < len; i++) {
//         freq[str[i]]++;
//     }

//     for (i = 0; i < len; i++) {
//         if (max <= freq[str[i]]) {
//             max = freq[str[i]];
//             result = str[i];
//         }
//     }

//     printf("The highest frequency character in the string %s is '%c' with frequency %d.\n", str, result, max);
//     return 0;
// }

// structure

// #include<stdio.h>
// #include<string.h>

// struct student
// {
//     char name[100];
//     int roll;
//     float cgpa;
// };

// int main(){

// struct student s1;

// strcpy(s1.name,"Mahatab");
// s1.roll = 2302036;
// s1.cgpa = 8.00;

// printf("Name of the student : %s\nroll : %d\ncgpa : %f",s1.name,s1.roll,s1.cgpa);

// struct student cse[4];

// cse[0].roll=11;
// cse[0].cgpa =8.00;
// strcpy(cse[0].name,"mahatab");

// cse[1].roll=12;
// cse[1].cgpa =8.10;
// strcpy(cse[1].name,"fahad");

// cse[2].roll=13;
// cse[2].cgpa =8.11;
// strcpy(cse[2].name,"nazmus");

// printf("Name of the student : %s\nroll : %d\ncgpa : %f\n",cse[0].name,cse[0].roll,cse[0].cgpa);
// printf("Name of the student : %s\nroll : %d\ncgpa : %f\n",cse[1].name,cse[1].roll,cse[1].cgpa);
// printf("Name of the student : %s\nroll : %d\ncgpa : %f\n",cse[2].name,cse[2].roll,cse[2].cgpa);

// struct student cse1={"Mahatab",11,8.00};
// struct student cse2={"fahad",22,8.12};
// struct student cse3={"ankur",33,8.13};

// printf("Name of the student : %s\nroll : %d\ncgpa : %f\n",cse1.name,cse1.roll,cse1.cgpa);
//  printf("Name of the student : %s\nroll : %d\ncgpa : %f\n",cse2.name,cse2.roll,cse2.cgpa);
//  printf("Name of the student : %s\nroll : %d\ncgpa : %f\n",cse3.name,cse3.roll,cse3.cgpa);

//     return 0;
// }

// #include<stdio.h>
// #include<string.h>

// struct student
// {
//     char name[100];
//     int roll;
//     float cgpa;
// };

// int main(){

//     struct student cse1={"Mahatab",11,8.00};
//     struct student cse2={"fahad",22,8.12};
//     struct student cse3={"ankur",33,8.13};

//     struct student *p;

//     p = &cse1;
//     printf("Name of the student : %s\nroll : %d\ncgpa : %f\n",cse1.name,cse1.roll,cse1.cgpa);
//     printf("after\n");
//     printf("Name of the student : %s\nroll : %d\ncgpa : %f\n",(*p).name,(*p).roll,(*p).cgpa);

//     return 0;
// }

// #include<stdio.h>
// #include<string.h>

// struct student
// {
//     char name[100];
//     int roll;
//     float cgpa;
// };

// int main(){

//     struct student cse1={"Mahatab",11,8.00};

//     struct student *p;

//     p = &cse1;
//     printf("With Pointer\n");
//     printf("roll : %d\n",(*p).roll);
//     printf("Without Pointer\n");
//     printf("roll : %d\n",p->roll);

//     return 0;
// }

/*
#include <stdio.h>

void printPattern(int n) {
    // Calculate the size of the matrix
    int size = 2 * n - 1;

    // Loop to iterate over rows
    for (int i = 0; i < size; i++) {
        // Loop to iterate over columns
        for (int j = 0; j < size; j++) {
            // Find the minimum value at the current position
            int minValue = (i < j) ? i : j;
            minValue = (minValue < size - i) ? minValue : size - i - 1;
            minValue = (minValue < size - j - 1) ? minValue : size - j - 1;

            // Print the number at the current position
            printf("%d ", n - minValue);
        }
        // Move to the next line after each row
        printf("\n");
    }
}

int main() {
    int n;
    // Input the value of n
    scanf("%d", &n);

    // Call the function to print the pattern
    printPattern(n);

    return 0;
}



#include <stdio.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);

    int marks[n + 1];

    for (int i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
    }

    char gender;
    // Add a space before %c to consume any leading whitespace characters
    scanf(" %c", &gender);

    for (int i = 0; i < n; i++) {
        if (gender == 'g') {
            if (i % 2 != 0) {
                sum += marks[i];
            }
        } else {
            if (i % 2 == 0) {
                sum += marks[i];
            }
        }
    }

    printf("\n%d", sum);

    return 0;
}

*/

// #include<stdio.h>

// int main(){

//     FILE *ptr;

//     ptr = fopen("text.txt","w");

//     char ch;

//     fprintf(ptr,"%c",'M');
//     fprintf(ptr,"%c",'a');
//     fprintf(ptr,"%c",'n');
//     fprintf(ptr,"%c",'g');
//     fprintf(ptr,"%c",'o');

//     fscanf(ptr,"%d",&ch);
//     printf("%d\n",ch);
//     fscanf(ptr,"%d",&ch);
//     printf("%d\n",ch);
//     fscanf(ptr,"%d",&ch);
//     printf("%d\n",ch);
//     fscanf(ptr,"%d",&ch);
//     printf("%d\n",ch);
//     fscanf(ptr,"%d",&ch);
//     printf("%d\n",ch);

//     if(ptr == NULL){
//         printf("File doesnot exist");
//     }
//     else{
//         fclose(ptr);
//     }

//     fclose(ptr);

// }

// #include<stdio.h>

// int main(){
//     FILE *ptr;

//     ptr = fopen("text.txt","r");

//     char c;
//     c= fgetc(ptr);

//     while (c!=EOF)
//     {
//         printf("%c",c);
//         c= fgetc(ptr);

//     }

// char name[100];
// int roll;
// float cgpa;

// printf("Enter Student Name: ");
// scanf("%s",name);
//  printf("Enter Student roll: ");
// scanf("%d",&roll);
//  printf("Enter Student cgpa: ");
// scanf("%f",&cgpa);

// fprintf(ptr,"Student name: %s\n",name);
// fprintf(ptr,"Student roll: %d\n",roll);
// fprintf(ptr,"Student cgpa: %f\n",cgpa);

// printf("%c\n",fgetc(ptr));
// printf("%c\n",fgetc(ptr));
// printf("%c\n",fgetc(ptr));
// printf("%c\n",fgetc(ptr));

// fputc('H',ptr);
// fputc('q',ptr);
// fputc('o',ptr);
// fputc('w',ptr);

//     fclose(ptr);
//     return 0;

// }

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX_HEIGHT 41

// struct box
// {
// 	int length;
//     int width;
//     int height;
// };

// typedef struct box box;

// int get_volume(box b) {
// 	/**
// 	* Return the volume of the box
// 	*/
//     int volume = b.length*b.width*b.height;
//     return volume;
// }

// int is_lower_than_max_height(box b) {
// 	/**
// 	* Return 1 if the box's height is lower than MAX_HEIGHT and 0 otherwise
// 	*/
//     if (b.height < MAX_HEIGHT)
//     {
//        return 1;
//     }
//     else
//     {
//         return 0;
//     }

// }

// int main()
// {
// 	int n;
// 	scanf("%d", &n);
// 	box *boxes = malloc(n * sizeof(box));
// 	for (int i = 0; i < n; i++) {
// 		scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
// 	}
// 	for (int i = 0; i < n; i++) {
// 		if (is_lower_than_max_height(boxes[i])) {
// 			printf("%d\n", get_volume(boxes[i]));
// 		}
// 	}
// 	return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int num, *arr, i;
//     scanf("%d", &num);
//     arr = (int*) malloc(num * sizeof(int));
//     for(i = 0; i < num; i++) {
//         scanf("%d", arr + i);
//     }

//     /* Write the logic to reverse the array. */

//     for(i = 0; i < num; i++)
//         printf("%d ", *(arr + i));
//     return 0;
// }

// #include<stdio.h>

// int main(){
//     int n;
//     scanf("%d",&n);
//     int arr[n];

//     for (int  i = 0; i < n; i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     int *p= &arr[n-1];

//     for (int i = 0; i < n; i++)

//     {
//         printf("%d ",*p);
//         p--;
//     }

//     return 0;

// }

// #include<stdio.h>
// #include<string.h>

// int main(){
//     char s[100];

//     gets(s);
//     int count = strlen(s);

//     for (int i = 0; i < count; i++)
//     {
//         printf("%c",s[i]);
//         if(s[i]==' '){
//             printf("\n");
//         }
//     }

//     return 0;
// }

// #include<stdio.h>
// #include<string.h>

// int main(){
//     char s[1000];

//     fgets(s,sizeof(s),stdin);

//     int count = strlen(s);

//     int sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0,sum7=0,sum8=0,sum9=0,sum0=0;

// for (int i = 0; i < count; i++) {
//         if (s[i] == '0') {
//             sum0++;
//         }
//         if (s[i] == '1') {
//             sum1++;
//         }
//         if (s[i] == '2') {
//             sum2++;
//         }
//         if (s[i] == '3') {
//             sum3++;
//         }
//         if (s[i] == '4') {
//             sum4++;
//         }
//         if (s[i] == '5') {
//             sum5++;
//         }
//         if (s[i] == '6') {
//             sum6++;
//         }
//         if (s[i] == '7') {
//             sum7++;
//         }
//         if (s[i] == '8') {
//             sum8++;
//         }
//         if (s[i] == '9') {
//             sum9++;
//         }
//     }

//      printf("%d %d %d %d %d %d %d %d %d %d", sum0, sum1, sum2, sum3, sum4, sum5, sum6, sum7, sum8, sum9);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int *total_number_of_books;
// int **total_number_of_pages;

// int main()
// {
//     int total_number_of_shelves;
//     scanf("%d", &total_number_of_shelves);

//     int total_number_of_queries;
//     scanf("%d", &total_number_of_queries);

//     total_number_of_books = (int *)malloc(total_number_of_shelves * sizeof(int));
//     total_number_of_pages = (int **)malloc(total_number_of_shelves * sizeof(int *));

//     for (int i = 0; i < total_number_of_shelves; i++)
//     {
//         total_number_of_books[i] = 0;
//         total_number_of_pages[i] = (int *)malloc(sizeof(int));
//     }

//     while (total_number_of_queries--)
//     {
//         int type_of_query;
//         scanf("%d", &type_of_query);

//         if (type_of_query == 1)
//         {

//             int x, y;
//             scanf("%d %d", &x, &y);
//             total_number_of_books[x]+=1;
//             total_number_of_pages[x] = realloc(total_number_of_pages[x], total_number_of_books[x] * sizeof(int));
//             total_number_of_pages[x][total_number_of_books[x] - 1] = y;
//         }
//         else if (type_of_query == 2)
//         {
//             int x, y;
//             scanf("%d %d", &x, &y);
//             printf("%d\n", total_number_of_pages[x][y]);
//         }
//         else
//         {
//             int x;
//             scanf("%d", &x);
//             printf("%d\n", total_number_of_books[x]);
//         }
//     }

//     if (total_number_of_books)
//     {
//         free(total_number_of_books);
//     }

//     for (int i = 0; i < total_number_of_shelves; i++)
//     {
//         if (total_number_of_pages[i])
//         {
//             free(total_number_of_pages[i]);
//         }
//     }

//     if (total_number_of_pages)
//     {
//         free(total_number_of_pages);
//     }

//     return 0;
// }

// HOMEWORK
// 1
// 1 2
// 1 2 3
// 1 2 3 4

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for(row=1;row<=n;row++){
//         for ( col = 1; col <= row; col++)
//         {

//             printf("%d ",col);

//         }
//         printf("\n");

//     }
//     return 0;
// }

// 1
// 2 2
// 3 3 3

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n=");
//     scanf("%d",&n);
//     int i=1;

//     for(row=1;row<=n;row++){
//         for(col=1;col<=row;col++){
//             printf("%d ",i);
//         }
//         i+=1;
//         printf("\n");
//     }

//     return 0;
// }

// 1
// 1 0
// 1 0 1
// 1 0 1 0
// 1 0 1 0 1

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n=");
//     scanf("%d",&n);

//     for(row=1;row<=n;row++){
//         for(col=1;col<=row;col++){
//             printf("%d ",col%2);
//         }

//         printf("\n");
//     }

//     return 0;
// }

// 1
// 0 0
// 1 1 1

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n=");
//     scanf("%d",&n);

//     for(row=1;row<=n;row++){
//         for(col=1;col<=row;col++){
//             printf("%d ",row%2);
//         }

//         printf("\n");
//     }

//     return 0;
// }

// A
// A B
// A B C

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n=");
//     scanf("%d",&n);

//     for(row=1;row<=n;row++){
//         for(col=1;col<=row;col++){
//             printf("%c ",col+64);
//         }

//         printf("\n");
//     }

//     return 0;
// }

// A
// B B
// C C C
// D D D D

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n=");
//     scanf("%d",&n);

//     for(row=1;row<=n;row++){
//         for(col=1;col<=row;col++){
//             printf("%c ",row+64);
//         }

//         printf("\n");
//     }

//     return 0;
// }

// 1 2 3
// 1 2
// 1

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for(row=n;row>=1;row--){
//         for ( col = 1; col <= row; col++)
//         {

//             printf("%d ",col);

//         }
//         printf("\n");

//     }
//     return 0;
// }

// 3 3 3
// 2 2
// 1

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for(row=n;row>=1;row--){
//         for ( col = 1; col <= row; col++)
//         {

//             printf("%d ",row);

//         }
//         printf("\n");

//     }
//     return 0;
// }

// 1 0 1 0
// 1 0 1
// 1 0
// 1

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n=");
//     scanf("%d",&n);

//     for(row=n;row>=1;row--){
//         for(col=1;col<=row;col++){
//             printf("%d ",col%2);
//         }

//         printf("\n");
//     }

//     return 0;
// }

// 0 0 0 0
// 1 1 1
// 0 0
// 1

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n=");
//     scanf("%d",&n);

//     for(row=n;row>=1;row--){
//         for(col=1;col<=row;col++){
//             printf("%d ",row%2);
//         }

//         printf("\n");
//     }

//     return 0;
// }

// A B C D E
// A B C D
// A B C
// A B
// A

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n=");
//     scanf("%d",&n);

//     for(row=n;row>=1;row--){
//         for(col=1;col<=row;col++){
//             printf("%c ",col+64);
//         }

//         printf("\n");
//     }

//     return 0;
// }

// a b c d
// a b c
// a b
// a

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n=");
//     scanf("%d",&n);

//     for(row=n;row>=1;row--){
//         for(col=1;col<=row;col++){
//             printf("%c ",col+96);
//         }

//         printf("\n");
//     }

//     return 0;
// }

// d d d d
// c c c
// b b
// a

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n=");
//     scanf("%d",&n);

//     for(row=n;row>=1;row--){
//         for(col=1;col<=row;col++){
//             printf("%c ",row+96);
//         }

//         printf("\n");
//     }

//     return 0;
// }

// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3
// 1 2
// 1

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for(row=1;row<=n;row++){
//         for ( col = 1; col <= row; col++)
//         {

//             printf("%d ",col);

//         }
//         printf("\n");

//     }

//     for(row=n-1;row>=1;row--){
//         for ( col = 1; col <= row; col++)
//         {

//             printf("%d ",col);

//         }
//         printf("\n");

//     }

//     return 0;
// }

// 1
// 2 2
// 3 3 3
// 4 4 4 4
// 3 3 3
// 2 2
// 1

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for(row=1;row<=n;row++){
//         for ( col = 1; col <= row; col++)
//         {

//             printf("%d ",row);

//         }
//         printf("\n");

//     }

//     for(row=n-1;row>=1;row--){
//         for ( col = 1; col <= row; col++)
//         {

//             printf("%d ",row);

//         }
//         printf("\n");

//     }

//     return 0;
// }

// A
// A B
// A B C
// A B C D
// A B C
// A B
// A

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for(row=1;row<=n;row++){
//         for ( col = 1; col <= row; col++)
//         {

//             printf("%c ",col+64);

//         }
//         printf("\n");

//     }

//     for(row=n-1;row>=1;row--){
//         for ( col = 1; col <= row; col++)
//         {

//             printf("%c ",col+64);

//         }
//         printf("\n");

//     }

//     return 0;
// }

// A
// B B
// C C C
// D D D D
// E E E E E
// D D D D
// C C C
// B B
// A

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for(row=1;row<=n;row++){
//         for ( col = 1; col <= row; col++)
//         {

//             printf("%c ",row+64);

//         }
//         printf("\n");

//     }

//     for(row=n-1;row>=1;row--){
//         for ( col = 1; col <= row; col++)
//         {

//             printf("%c ",row+64);

//         }
//         printf("\n");

//     }

//     return 0;
// }

// *
// * *
// * * *
// * * * *
// * * *
// * *
// *

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for(row=1;row<=n;row++){
//         for ( col = 1; col <= row; col++)
//         {

//             printf("* ");

//         }
//         printf("\n");

//     }

//     for(row=n-1;row>=1;row--){
//         for ( col = 1; col <= row; col++)
//         {

//             printf("* ");

//         }
//         printf("\n");

//     }

//     return 0;
// }

//     1
//    12
//   123
//  1234
// 12345

// #include<stdio.h>

// int main(){

//     int n,row,col;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for (int row = 1; row<=n; row++)
//     {
//         for(col=1;col<=n-row;col++){
//             printf(" ");
//         }
//         for(col=1;col<=row;col++){
//             printf("%d",col);
//         }
//         printf("\n");
//     }
//     return 0;
// }

//      1
//     1 2
//    1 2 3
//   1 2 3 4
//  1 2 3 4 5
// 1 2 3 4 5 6

// #include<stdio.h>

// int main(){

//     int n,row,col;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for (int row = 1; row<=n; row++)
//     {
//         for(col=1;col<=n-row;col++){
//             printf(" ");
//         }
//         for(col=1;col<=row;col++){
//             printf("%d ",col);
//         }
//         printf("\n");
//     }
//     return 0;
// }

//    #
//   ##
//  ###
// ####

// #include<stdio.h>

// int main(){

//     int n,row,col;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for (int row = 1; row<=n; row++)
//     {
//         for(col=1;col<=n-row;col++){
//             printf(" ");
//         }
//         for(col=1;col<=row;col++){
//            printf("#");
//         }
//         printf("\n");
//     }
//     return 0;
// }

//     A
//    AB
//   ABC
//  ABCD
// ABCDE

// #include<stdio.h>

// int main(){

//     int n,row,col;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for (int row = 1; row<=n; row++)
//     {
//         for(col=1;col<=n-row;col++){
//             printf(" ");
//         }
//         for(col=1;col<=row;col++){
//             printf("%c",col+64);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// 12345
//  1234
//   123
//    12
//     1

// #include<stdio.h>

// int main(){

//     int n,row,col;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for (int row = n; row>=1; row--)
//     {
//         for(col=1;col<=n-row;col++){
//             printf(" ");
//         }
//         for(col=1;col<=row;col++){
//             printf("%d",col);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// 1010
//  101
//   10
//    1

// #include<stdio.h>

// int main(){

//     int n,row,col;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for (int row = n; row>=1; row--)
//     {
//         for(col=1;col<=n-row;col++){
//             printf(" ");
//         }
//         for(col=1;col<=row;col++){
//             printf("%d",col%2);
//         }
//         printf("\n");
//     }
//     return 0;
// }

//    1
//   12
//  123
// 1234
//  123
//   12
//    1

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n:");
//     scanf("%d",&n);

//     for(row = 1; row<=n;row++){
//         for(col=1;col<=n-row;col++){
//             printf(" ");
//         }
//         for(col=1;col<=row;col++){
//             printf("%d",col);
//         }
//         printf("\n");
//     }

//     for(row = n-1; row>=1;row--){
//         for(col=1;col<=n-row;col++){
//             printf(" ");
//         }
//         for(col=1;col<=row;col++){
//             printf("%d",col);
//         }
//         printf("\n");
//     }
// }

// 1 2 3 4
// 1 2 3 4
// 1 2 3 4
// 1 2 3 4

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n= ");
//     scanf("%d",&n);

//     for ( row = 1; row <= n; row++)
//     {
//        for(col=1;col<=n;col++){
//         printf("%d ",col);
//        }
//        printf("\n");
//     }

// }

// # # # #
// # # # #
// # # # #
// # # # #

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n= ");
//     scanf("%d",&n);

//     for ( row = 1; row <= n; row++)
//     {
//        for(col=1;col<=n;col++){
//         printf("# ");
//        }
//        printf("\n");
//     }

// }

// 1 1 1 1
// 2 2 2 2
// 3 3 3 3
// 4 4 4 4

// #include<stdio.h>

// int main(){
//     int n,row,col;

//     printf("Enter n= ");
//     scanf("%d",&n);

//     for ( row = 1; row <= n; row++)
//     {
//        for(col=1;col<=n;col++){
//         printf("%d ",row);
//        }
//        printf("\n");
//     }

// }

// 1
// 2 4
// 3 6 9
// 4 8 12 16
// 5 10 15 20 25

// #include<stdio.h>

// int main(){
//     int n,row,col;
//     printf("Enter n: ");
//     scanf("%d",&n);

//     for(row=1;row<=n;row++){
//         for(col=1;col<=row;col++){
//             printf("%d ",col*row);
//         }

//         printf("\n");
//     }

//     return 0;
// }

//      1
//     123
//    12345
//   1234567
//  123456789
// 1234567891011

// #include<stdio.h>

// int main(){
//     int col,row,n;

//     printf("enter n: ");
//     scanf("%d",&n);

//     for (int row = 1; row <= n; row++)
//     {
//         for (int col = 1; col <= n-row; col++)
//         {
//             printf(" ");
//         }
//         for(int col=1;col<=2*row-1;col++){
//             printf("%d",col);

//         }
//         printf("\n");
//     }

//     return 0;

// }

//     #
//    ###
//   #####
//  #######
// #########

// #include<stdio.h>

// int main(){
//     int col,row,n;

//     printf("enter n: ");
//     scanf("%d",&n);

//     for (int row = 1; row <= n; row++)
//     {
//         for (int col = 1; col <= n-row; col++)
//         {
//             printf(" ");
//         }
//         for(int col=1;col<=2*row-1;col++){
//             printf("#");

//         }
//         printf("\n");
//     }

//     return 0;

// }

/*
#include<stdio.h>

int main(){
    int col,row,n;

    printf("enter n: ");
    scanf("%d",&n);

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n-row; col++)
        {
            printf(" ");
        }
        for(int col=1;col<=row;col++){
            printf("%d ",col);

        }
        printf("\n");
    }

    return 0;

}
*/

// #include<stdio.h>

// int main(){
//     int col,row,n;

//     printf("enter n: ");
//     scanf("%d",&n);

//     for ( row = n; row >=1; row--)
//     {
//         for (int col = 1; col <= n-row; col++)
//         {
//             printf(" ");
//         }
//         for(int col=1;col<=2*row-1;col++){
//             printf("%d",col);

//         }
//         printf("\n");
//     }

//     return 0;

// }

// #include<stdio.h>

// int main(){
//     int col,row,n;

//     printf("enter n: ");
//     scanf("%d",&n);

//     for ( row = n; row >=1; row--)
//     {
//         for (int col = 1; col <= n-row; col++)
//         {
//             printf(" ");
//         }
//         for(int col=1;col<=2*row-1;col++){
//             printf("#");

//         }
//         printf("\n");
//     }

//     return 0;

// }

//      #
//     # #
//    # # #
//   # # # #
//  # # # # #
//   # # # #
//    # # #
//     # #
//      #

// #include<stdio.h>

// int main(){
//     int row,col,n;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for ( row = 1; row <= n; row++)
//     {
//          for (int col = 1; col <= n-row; col++)
//         {
//             printf(" ");
//         }
//         for(int col=1;col<=row;col++){
//            printf(" #");

//         }
//         printf("\n");
//     }

//     for ( row = n-1; row >= 1; row--)
//     {
//          for (int col = 1; col <= n-row; col++)
//         {
//             printf(" ");
//         }
//         for(int col=1;col<=row;col++){
//            printf(" #");

//         }
//         printf("\n");
//     }
//     return 0;
// }

//      A
//     A B
//    A B C
//   A B C D
//  A B C D E
//   A B C D
//    A B C
//     A B
//      A

// #include<stdio.h>

// int main(){
//     int row,col,n;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for ( row = 1; row <= n; row++)
//     {
//          for (int col = 1; col <= n-row; col++)
//         {
//             printf(" ");
//         }
//         for(int col=1;col<=row;col++){
//            printf(" %c",col+64);

//         }
//         printf("\n");
//     }

//     for ( row = n-1; row >= 1; row--)
//     {
//          for (int col = 1; col <= n-row; col++)
//         {
//             printf(" ");
//         }
//         for(int col=1;col<=row;col++){
//           printf(" %c",col+64);

//         }
//         printf("\n");
//     }

// }

// *****
// *   *
// *   *
// *   *
// *****

// #include<stdio.h>

// int main(){
//     int row,col,n;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for ( row = 1; row <= n; row++)
//     {
//         for(col=1;col<=n;col++){
//             if(row==1 || row==n || col==1 || col==n){
//                 printf("*");
//             }
//             else{
//                 printf(" ");
//             }
//         }
//         printf("\n");
//     }
//     return 0;
// }

// *
// **
// * *
// *  *
// *   *
// *    *
// *     *
// *      *
// *       *
// *        *
// *         *
// *          *
// *           *
// *            *
// *             *
// *              *
// *****************

// #include<stdio.h>

// int main(){
//     int row,col,n;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for ( row = 1; row <= n; row++)
//     {
//         for(col=1;col<=n;col++){
//             if(col==1 || row==n || row==col){
//                 printf("*");
//             }
//             else{
//                 printf(" ");
//             }
//         }
//         printf("\n");
//     }
//     return 0;
// }

// *                *
//  *              *
//   *            *
//    *          *
//     *        *
//      *      *
//       *    *
//        *  *
//         **
//         **
//        *  *
//       *    *
//      *      *
//     *        *
//    *          *
//   *            *
//  *              *
// *                *

// #include<stdio.h>

// int main(){
//     int row,col,n;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for ( row = 1; row <= n; row++)
//     {
//         for(col=1;col<=n;col++){
//             if(col==row || row+col==n+1){
//                 printf("*");
//             }
//             else{
//                 printf(" ");
//             }
//         }
//         printf("\n");
//     }
//     return 0;
// }

// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
// 16 17 18 19 20 21

// #include<stdio.h>

// int main(){
//     int row,col,n,count=0;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for(row=1;row<=n;row++){
//         for(col=1;col<=row;col++){
//             printf("%d ",++count);
//         }
//         printf("\n");
//     }

//     return 0;
// }

//     1
//    121
//   12321
//  1234321
// 123454321

// #include<stdio.h>

// int main(){
//     int row,col,n;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for ( row = 1; row <= n; row++)
//     {
//        for(col=1;col<=n-row;col++)printf(" ");
//        for(col=1;col<=row;col++)printf("%d",col);
//        for(col=row-1;col>=1;col--)printf("%d",col);

//        printf("\n");
//     }

//     return 0;
// }

//  1234321
//   12321
//    121
//     1

// #include<stdio.h>

// int main(){
//     int row,col,n;

//     printf("Enter n: ");
//     scanf("%d",&n);

//     for ( row = n-1; row >= 1; row--)
//     {
//        for(col=1;col<=n-row;col++)printf(" ");
//        for(col=1;col<=row;col++)printf("%d",col);
//        for(col=row-1;col>=1;col--)printf("%d",col);

//        printf("\n");
//     }

//     return 0;
// }

// taking input an array and displaying it
/*
#include<stdio.h>


int main(){
    int n;
    int arr[100];

    printf("Enter the number of elements you want to input: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter element # %d :",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Displaying array\n");
    printf("[");

    for(int i=0;i<n;i++){

        printf(" %d ",arr[i]);


    }
    printf("]");

    return 0;

}



//example of user defined function
#include<stdio.h>


int main(){
    int n1,n2;
    printf("Enter two number for summation: ");
    scanf("%d %d",&n1,&n2);
    sum(n1,n2);

    return 0;
}

void sum(int a,int b){
    int result = a+b;
    printf("sum of %d & %d is = %d",a,b,result);
}


#include<stdio.h>

void add(float a,float b);
void sub(float a,float b);
void division(float a,float b);
void mul(float a,float b);

int main(){
    float n1,n2;
    int n;
    printf("Enter two numbers: ");
    scanf("%f %f",&n1,&n2);

    printf("Now choose what operation you want to do.\nOptions are:\n[1]Addition\n[2]Substraction\n[3]Division\n[4]Multiplication\n");
    printf("Enter: ");
    scanf("%d",&n);

    if(n==1){
        add(n1,n2);
    }
    else if(n==2){
        sub(n1,n2);
    }
    else if(n==3){
        division(n1,n2);
    }
    else {
        mul(n1,n2);
    }

    return 0;
}

void add(float a,float b){
    printf("Result = %f\n",a+b);
}

void sub(float a,float b){
    printf("Result = %f\n",a-b);
}

void division(float a,float b){
    if(b != 0) {
        printf("Result = %f\n",a/b);
    } else {
        printf("Cannot divide by zero.\n");
    }
}

void mul(float a,float b){
    printf("Result = %f\n",a*b);
}



#include<stdio.h>


int main(){
    int n,x,count=0;
    int arr[100];

    printf("Enter the number of elements you want to input: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter element # %d :",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Displaying array\n");
    printf("[");

    for(int i=0;i<n;i++){

        printf(" %d ",arr[i]);


    }
    printf("]\n");

    printf("Enter the number that divides the elements in array:");
    scanf("%d",&x);
    for(int i=0;i<n;i++){

        if(arr[i]%x==0){
            count+=1;
        }



    }
    printf("Number of elements: %d",count);


    return 0;

}


#include<stdio.h>

int main(){
    int n,c=0;

    int arr[6]={11,22,33,44,55,66};

    printf("displaying\n");

    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Enter the number you want to find: ");
    scanf("%d",&n);


    for(int i=0;i<6;i++){
            if(arr[i]==n){
                c+=1;
                printf("%dth element is %d",i+1,arr[i]);
            }
    }
    if(c==0){
        printf("not found");
    }
    return 0;


}






#include<stdio.h>
//#include<string.h>

int main(){
    char c;
    scanf("%c",&c);

    char a;
    a= tolower(c);

    if(a>='a' && a<='z'){
        if(a=='a' || a=='e'|| a=='i'|| a=='o'||a=='u'){
            printf("%c is a vowel",c);
        }
        else
        {
            printf("%c is a consonant",a);
        }

    }


    else
    {
        printf("It is not an alphabet");
    }
    return 0;
}



#include<stdio.h>

int main(){
    int n1,n2;

    scanf("%d %d",&n1,&n2);

    int count=0;

    for(int i=n1;i<=n2;i++){
        if(i%2==0){
            printf("%d ",i);
            count++;
        }
    }
    printf("\n Count= %d",count);
    return 0;
}
*/

// #include<stdio.h>
// //#include<string.h>

// int main(){
//     char c;
//     scanf("%c",&c);

//     char a;
//     a= tolower(c);

//     if(a>='a' && a<='z'){
//         if(a=='a' || a=='e'|| a=='i'|| a=='o'||a=='u'){
//             printf("%c is a vowel",c);
//         }
//         else
//         {
//             printf("%c is a consonant",a);
//         }

//     }

//     else
//     {
//         printf("It is not an alphabet");
//     }
//     return 0;
// }

/* #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    printf("Hello, world! I am learning C programming language. ^_^\n");
    printf("Programming is fun and challenging. /\\/\\/\\ \n");
    printf("I want to give my 100%% dedication to learn!\tI will succeed one day.\n");
    return 0;
}

 */

/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d",&n);

    for (int i = 1; i <= n; i++)
    {
        if (i%3==0 && i%7==0)
        {
            printf("%d\n",i);
        }

    }

    return 0;
}
 */

/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d",&n);

    if (n>1000)
    {
        printf("I will buy Punjabi\n");
        n-=1000;
        if (n>=500)
    {
        printf("I will buy new shoes\n");
        printf("Alisa will buy new shoes\n");
        n-=500;
    }
    }

    else if (n<=1000)
    {
        printf("Bad luck!\n");
    }



    return 0;
}

 */
/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    for (int i = n-1; i >= 0; i--)
    {
       if (i%2!=0)
       {
        continue;
       }
       else
       {
        printf("%d ",a[i]);
       }


    }


    return 0;
}

 */

/*

#include <stdio.h>
#include <stdlib.h>

int *deleting(int *a, int n, int pos)
{
   int *b = (int *)malloc((n - 1) * sizeof(int));
   for (int i = 0; i < pos; i++)
   {
       b[i] = a[i];
   }
   for (int i = pos; i < n; i++)
   {
       b[i] = a[i + 1];
   }

   free(a);
   a = NULL;
   return b;
}
int main()
{
   int *a = (int *)malloc(10 * sizeof(int));

   for (int i = 0; i < 10; i++)
   {
       int n;
       scanf("%d", &n);
       a[i] = n;
   }
   printf("Displaying array\n");
   for (int i = 0; i < 10; i++)
   {
       printf("%d ", a[i]);
   }
   printf("\n");

   printf("Enter which position you want to delete: ");
   int pos;
   scanf("%d", &pos);

   a = deleting(a, 10, pos);
   printf("\nDisplaying array\n");
   for (int i = 0; i < 9; i++)
   {
       printf("%d ", a[i]);
   }

   free(a);
   a = NULL;

   return 0;
}
*/

// Linked List in C

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node
// {
//     int value;
//     Node* next;
// } Node;

// int main()
// {

//     Node* head = (Node*)malloc(sizeof(Node));

//     int array[] = {1, 2, 3, 4, 5, 6};
//     head->value = array[0];
//     head->next = NULL;

//     Node* temp = head;

//     for (int i = 1; i < 6; i++)
//     {

//         Node* new_node = (Node*)malloc(sizeof(Node));
//         if (new_node == NULL)
//         {
//             perror("Failed to allocate memory for new_node");
//             return 1;
//         }
//         new_node->value = array[i];
//         new_node->next = NULL;

//         temp->next = new_node;
//         temp = new_node;
//     }

//     Node* curr = head;
//     while (curr != NULL)
//     {
//         printf("%d ", curr->value);
//         curr = curr->next;
//     }
//     printf("\nProgram Ends\n");

//     curr = head;
//     while (curr != NULL)
//     {
//         Node* next = curr->next;
//         free(curr);
//         curr = next;
//     }

//     return 0;
// }

// Deleting from an array

#include <stdio.h>

int main()
{
    int arr[] = {1, 2,3, 4};

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    int el = 3;
    int i = 0;

    while (i<4)
    {
        if (arr[i]==el)
        {
            break;
        }
        
        i++;
    }
    

    while (i < 3)
    {
        arr[i] = arr[i + 1];
        i++;
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    int pos = 2;

    i=3;

    while (i>pos)
    {
        arr[i+1]=arr[i];
        i--;
    }
    arr[pos]=el;
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    
}
