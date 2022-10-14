#include<bits/stdc++.h>
using namespace std;
  


#define fi first
#define se second
#define pb(x) push_back(x)
#define ll long long
#define f(i,n) for(int i=0; i<n; ++i)
#define show(a) for(auto &i : a){ cout<<i<<" ";} cout<<"\n";
#define vi vector<int>
#define vvi vector<vector<int>>
#define deb(x) cout<<x<<"###\n";

// this sgmt tree stores sum, returns sum for range [L,R]
// we can make a sgmt tree which can stores minimum and return min in the range [L,R]
// can also make different types of sgmt trees with different functionality 
     void build(vector<long long>&t,vector<int>&v,int ind,int l,int h){
        if(l==h){
            t[ind]=v[l];
            return;
        }
        
        int mid = l+ (h-l)/2;
        build(t,v,2*ind+1,l,mid);
        build(t,v,2*ind+2,mid+1,h);
        
        t[ind]=(t[2*ind+1]+t[2*ind+2]);
    }
    
    void up(vector<long long>&t,int ind,int l,int h,int i,int val){
        if(l==h){
            t[ind]=val;
            return;
        }
        int mid = l + (h-l)/2;
        if(i<=mid){
            up(t,2*ind+1,l,mid,i,val);
        }
        else up(t,2*ind+2,mid+1,h,i,val);
        
        t[ind]=(t[2*ind+1]+t[2*ind+2]);
    }
    
    long long qu(vector<long long >&t, int ind, int l, int h, int L,int R){
        if(h<L || R<l){
            return 0;
        }
        if(l>=L && h<=R){
            return t[ind];
        }
        int mid = l + (h-l)/2;
        long long left = qu(t,2*ind+1,l,mid,L,R);
        long long right = qu(t,2*ind+2,mid+1,h,L,R);
        
        return left+right;
    }
    

    
    int main(){
        vi vec{1,2,5,6,1};
        long long tsize = vec.size()*4;
        vector<long long>t(tsize);
        build(t,vec,0,0,vec.size()-1);

        up(t,0,0,vec.size()-1,0,0);
        cout<<qu(t,0,0,vec.size()-1,0,3);

        
    }