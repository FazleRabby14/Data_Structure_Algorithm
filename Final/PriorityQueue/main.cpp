#include "pqtype.cpp"
#include<iostream>
using namespace std;

int main()
{
    PQType<int>pq(15);

    pq.Enqueue(4);
    pq.Enqueue(9);
    pq.Enqueue(2);
    pq.Enqueue(7);
    pq.Enqueue(3);
    pq.Enqueue(11);
    pq.Enqueue(17);
    pq.Enqueue(0);
    pq.Enqueue(5);
    pq.Enqueue(1);

    if(pq.IsEmpty()){
       cout<<"priority Queue is empty";
    }
    else{
        cout<<"priority Queue is not empty"<<endl;
    }

    int item;
    pq.Dequeue(item);
    cout<<"Item is:"<<item<<endl;
    pq.Dequeue(item);
    cout<<"Item is:"<<item<<endl;

    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++)
    {
        int candies;
        cin>>candies;
        pq.Enqueue(candies);
    }

    int eatenCandies=0;

    while (k>0 && !pq.IsEmpty()){
        pq.Dequeue(item);
        eatenCandies+=item;
        k--;

        pq.Enqueue(item/2);
    }

    cout<<"Maximum number of eaten candies:"<<eatenCandies<<endl;

    return 0;

}
