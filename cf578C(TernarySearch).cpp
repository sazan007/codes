#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define si(n) scanf("%d",&n);
#define PI acos(-1.0)
#define sl(n) scanf("%lld",&n);
#define sf(n) scanf("%lf",&n);
#define ss(n) scanf("%s",n);
#define for0(i,n) for(ll i=0;i<n;i++)
#define for1(i,n) for(ll i=1;i<=n;i++)
#define forc(i,j,n) for(ll i=j;i<n;i++)
#define pb push_back
#define sor(n) sort(n.begin(),n.end())
#define sorcmp(n) sort(n.begin(),n.end(),cmp)
#define rev(n) reverse(n.begin(),n.end())
#define pi(x)  printf("%d",x);
#define pl(x)  printf("%lld",x);
#define pf(x)  printf("%.10lf",x);
#define ps(x)  printf("%s",x);
#define en() printf("\n");
#define random_shuffle(r...)random_shuffle(r,[](int _){return rand()%_;})
#define SQR(a) (a)*(a)
#define sp(x) fixed<<setprecision(x)
#define mod 1000000007
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define bug cout<<"Here"<<endl
#define eps 1e-11
void fastio(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
ll powmod(ll a, ll b){ll ans = 1;while(b){if(b&1) ans = ans*a%mod;a = a*a%mod;b >>= 1;}return ans;}

int n;
double arr[200005];


double solve(double x) {
    ll i, j;
    double c, res(0.0);
    double brr[200005];
    for(int i=1;i<=n;i++)
    {
        brr[i]=arr[i];
        brr[i]-=x;
    }
    double sum=0;

    for(int i=1;i<=n;i++)
    {

    sum+=brr[i];
    if(sum>res)
    {
        res=sum;
    }
    if(sum<0)
        sum=0;

    }
    for(int i=1;i<=n;i++)
    {
        brr[i]*=-1;
    }

      sum=0.0;
      for(int i=1;i<=n;i++)
    {

     sum+=brr[i];
    if(sum>res)
    {
        res=sum;
    }
    if(sum<0)
        sum=0;


    }


    return res;
}



int main(){

   fastio();


       cin>>n;
       for(int i=1;i<=n;i++) cin>>arr[i];


       double lo=-1e5,hi=1e5;
       double ans=0.0;
       while(hi-lo>eps)
       {
           double m1=lo+(hi-lo)/3.0;
           double m2=hi-(hi-lo)/3.0;
           double f1=solve(m1);
           double f2=solve(m2);


         if(f1>f2)
         {
             ans=f2;
             lo=m1;
         }
         else
         {
             ans=f1;
             hi=m2;
         }


       }


       cout<<sp(10)<<ans<<endl;











return 0;
}
