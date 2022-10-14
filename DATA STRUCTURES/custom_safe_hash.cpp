#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(a) a.size()

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unordered_map<ll, ll, custom_hash> mp;
  deque<ll> a;
  ll n, k, d, m = 0;
  cin >> n >> k;

  for (auto i = 0; i < n; i++) {
    cin >> d;
    if (!mp[d]) {
      mp[d] = 1;
      a.emplace_front(d);
      if (sz(a) > k) {
        mp[a.back()] = 0;
        a.pop_back();
      }
    }
  }
  cout << sz(a) << "\n";
  while (!a.empty()) {
    cout << a.front() << " ";
    a.pop_front();
  }
  return 0;
}


/*
struct myhash
{
    static uint64_t fxn(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator ()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return fxn(x + FIXED_RANDOM);
    }
};

int main()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time, end_time;
    start_time = std::chrono::high_resolution_clock::now();

    #ifdef DHRUV_GHEEWALA
        freopen("INPUT.txt","r",stdin);
        freopen("OUTPUT.txt","w",stdout);
        freopen("DEBUG.txt","w",stderr);
    #endif
    
    fast;
    int n,k,x;
    test{

    cin>>n>>k;
    unordered_set<int, myhash> s;
    deque<int> q;

    rep(i,n)
    {
        cin>>x;
        if(exist(s,x))continue;

        if(q.size()==k)
        {
            int val=q.front();
            q.pop_front();
            s.erase(s.find(val));
        }
        q.pb(x);
        s.insert(x);
        d(s);
    }

    cout<<sz(q),nl;
    while(!q.empty())
        cout<<q.back()<<" ",q.pop_back();
    nl;

    fundri;
    }

    end_time = std::chrono::high_resolution_clock::now();
    ll elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
    o("\n\n======\n");
    if(elapsed_time<10000)
        o("Elapsed Time: "<<elapsed_time<<" ms\n");
    else
        o("Elapsed Time: "<<elapsed_time/1000<<" s\n");

    return 0;
}
*/