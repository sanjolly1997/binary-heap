#include <iostream>
using namespace std;
#include <limits.h>
class minheap

{

int *arr;

int size;

int cap;

public:

minheap(int cap);

void minheapify(int);

 int parent(int i)

 {

 return (i-1)/2;

 }

int left(int i)

 {

 return ((2*i)+1);

 }

 int right(int i)

  {

   return ((2*i)+2);

 }

 int extractmin();

 void decreasevalue(int ,int );

int getmin()

  {

 return arr[0];

}

void deletevalue(int i);

 void insertvalue(int k);

};

minheap::minheap(int capacity)

{
    arr = new int [capacity];

   cap = capacity;

   size = 0;

}

void minheap::insertvalue(int k)
{

 if(size==cap)
{
cout<<"no more space"<<endl;
    return;
}

arr[size]=k;

int i=size;

 size++;

 while(i!=0 && arr[parent(i)]>arr[i])
{

   swap(arr[i],arr[parent(i)]);

   i=parent(i);

 }

}

void minheap::minheapify(int i)

{

 int l=left(i);
//cout<<l;
 int r=right(i);
//cout<<r;
 int smallest=i;

if(l<size && arr[l]<arr[smallest])

smallest=l;

if(r<size && arr[r]<arr[smallest])

smallest=r;

if(smallest!=i)

{

 swap(arr[i],arr[smallest]);

 minheapify(smallest);

}

}

int minheap::extractmin()

{
    if(size==0)


    { size--;
        return arr[0];
}

int r=arr[0];

  arr[0]=arr[size-1];

  size--;

minheapify(0);

return r;

}

void minheap::decreasevalue(int i,int n)

{
   arr[i] = n;

   while(i!=0 && arr[parent(i)]>arr[i])

    {
        swap(arr[parent(i)],arr[i]);
        i=parent(i);

 }
}

void minheap::deletevalue(int i)

{
    decreasevalue(i,INT_MIN);

  extractmin();

}

int main()
 {

// your code goes here

minheap heap(5);

 heap.insertvalue(2);
 heap.insertvalue(9);
heap.insertvalue(3);
 heap.insertvalue(1);
heap.insertvalue(5);

heap.deletevalue(1);

cout<<heap.extractmin()<<endl;
cout<<heap.extractmin()<<endl;



return 0;

}
