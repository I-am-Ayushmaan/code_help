#include<bits/stdc++.h>
using namespace std;
  


#define fi first
#define se second
#define pb(x) push_back(x)
#define ll long long
#define f(i,n) for(int i=0; i<n; ++i)
#define show(a) for(auto &i : a) cout<<i<<" ";
#define vll vector<long long>
#define vvll vector<vector<long long>>

 class heap{
    public : 
     int arr[100], size;

    heap(){
        arr[0]=-1; size =0;
    }

    void push(int val){
        size=size+1;            //checking the new item with its 
        arr[size]=val;          // parent if new item>parent
       int index=size;          // swap them;
       while(index>1){          // 
         int parent  = index/2;
         if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
            parent =index;
         }
         else{
            return;
         }
       }
     }

   void pop(){
      if(size==0){cout<<"size is zero\n"; return;}
      
      arr[1]=arr[size];
      size--;
      int i=1;
      while(i<=size){
        
         if((2*i)<=size && arr[2*i]>arr[2*i+1]){
            swap(arr[i],arr[2*i]);
            i=2*i;
         }
         else if((2*i+1) <= size){
           swap(arr[i],arr[2*i+1]);
           i=2*i+1;
         }
         else{
            return;
         }
      }
   }

   void print(){
     for(int i =1; i<=size; ++i){
       cout<<arr[i]<<" ";
     }cout<<"\n";
   } 
 };




 int main(){
   heap h;

   h.push(15);
   h.push(10);
   h.push(12);
   h.push(6);
   h.push(7);
   h.push(8);
   h.push(5);
   //h.push(1);
   h.pop();
  
   h.print();
 }