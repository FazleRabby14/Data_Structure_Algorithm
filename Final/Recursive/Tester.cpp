#include<iostream>
using namespace std;

int fib(int n){

if(n<=1){
    return n;
}
else{
    return fib(n-1)+fib(n-2);
}

}

int factorial(int n){

if(n==0){
    return 1;
}
else{
    return n*factorial(n-1);
}

}

int sumOfDigit(int x)
{
    if(x<10){
        return x;
    }
    else{
        return x%10+sumOfDigit(x/10);
    }
}

int decToBin(int x){

if(x==0){
    return 0;
}

else{
    return (x%2)+10*decToBin(x/2);
}

}


int main()
{
    int a=fib(5);
    cout<<a<<endl;

    int b=factorial(8);
    cout<<b<<endl;

    int c=sumOfDigit(180);
    cout<<c<<endl;

    int d=decToBin(20);
    cout<<d<<endl;


}
