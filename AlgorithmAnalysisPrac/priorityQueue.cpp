#include<bits/stdc++.h>
using namespace std;

class PriorityQueue{
    private:
    vector<int>heap;

    void heapUp(int i){
        while(i>0 && heap[(i-1)/2]<heap[i]){
            swap(heap[i],heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void heapDown(int i){
    int n = heap.size();
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && heap[left]>heap[largest]){
        largest=left;
    }
    if(right<n && heap[right]>heap[largest]){
        largest = right;
    }
    if(largest!=i){
        swap(heap[i],heap[largest]);
        heapDown(largest);
    }
}
 public:
 
 int Top(){
    if(heap.empty()){
        throw runtime_error("Heap is empty"); 
    }
    return heap[0];
 }

 void push(int val){
    heap.push_back(val);
    heapUp(heap.size()-1);
 }
 void pop(){
    if(heap.size()==0){
        return ;
    }
    heap[0]=heap.back();
    heap.pop_back();
    heapDown(0);
 }

 bool isEmpty(){
    return heap.size()==0;
 }

};
int main(){
     PriorityQueue pq;
    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(15);
    
    while(!pq.isEmpty()){
        cout << pq.Top() << " ";  // Output: 20 15 10 5
        pq.pop();
    }
    
    return 0;
}