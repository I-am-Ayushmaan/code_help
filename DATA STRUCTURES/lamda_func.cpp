#include <bits/stdc++.h>
using namespace std;


#define fi first
#define se second
#define pb(x) push_back(x)
#define ll long long
#define f(i,n) for(int i=0; i<n; ++i)
#define show(a) for(auto &i : a) cout<<i<<" ";
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vector<int>>
//#define pop pop_back
#define deb(x) cout<<x<<"###\n";


int main()
{
  /* case #1 - compiler deduces return type */
  cout << [](int n) {return n*n;} (5);
  cout << endl;
  /* case #2 - explicit return type */
  cout << [](int n)->int {return n*n;} (5);
cout<<endl;
  vector<int>dp{0,1000000000,6,3,0,0,1000000000};   // must ===>   dp[0]=0 

  // lamda function returns maximum except 1000000000
     

  int ans = *max_element(begin(dp),end(dp),[](int &a,int &b){
          if(b==1000000000 || a==1000000000){return false;}
          return a<b;
      });
cout<<ans;

  return 0;
}



