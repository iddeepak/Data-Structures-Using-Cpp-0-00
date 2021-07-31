#include <iostream>
using namespace std;

void inplaceHeapSort(int pq[], int n){
    
    //Build the heap input array;
    for(int i=1; i<n;i++){
        
        int childIndex = i;
        while(childIndex >0){
            
            int parentIndex = (childIndex-1)/2;
            
            if(pq[childIndex] <pq[parentIndex]){
                int temp = pq[childIndex];
                pq[parentIndex] = temp;
            }else{
                break;
            }
            
            childIndex = parentIndex;
        }
    }
    
    
    //remove elem
    
    int size = n;
    
    while(size>1){
        int temp =  pq[0];
        pq[0] = pq[size-1];
        pq[size-1] = temp;
        
        size--;
        
        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex+1;
        int rightChildIndex = leftChildIndex +1;  
        
        while(leftChildIndex <size){
            int minIndex = parentIndex;
            if(pq[minIndex] >pq[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            if(pq[minIndex] >pq[rightChildIndex]  &&  rightChildIndex <size){
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex){
                break;
            }
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[minIndex];
            pq[minIndex] = temp;
            
            parentIndex = minIndex;
            leftChildIndex = 2*parentIndex+1;
            rightChildIndex = 2*parentIndex+2;
        }
    }
}

int main() {
    int n;
    cout<<"Enter the size of an Array\n";
    cin>>n;
    int* a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<endl;
    inplaceHeapSort(a,n);
    cout<<"sorted Array\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }
    cout<<endl;
    delete [] a;
    return 0;
}
