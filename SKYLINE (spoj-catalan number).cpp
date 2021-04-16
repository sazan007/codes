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
#define mod 1000000
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define bug cout<<"Here"<<endl
void fastio(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
ll powmod(ll a, ll b){ll ans = 1;while(b){if(b&1) ans = ans*a%mod;a = a*a%mod;b >>= 1;}return ans;}

#define mxn 2005
int dp[mxn][mxn];

int func(int n,int r)
{

    if(n==r || r==0) return 1;

    if(dp[n][r]!=-1) return dp[n][r];

    return dp[n][r]=(func(n-1,r-1) %mod + func(n-1,r) %mod ) %mod;


}


int main()
{

    fastio();

	for(int i=0;i<mxn;i++)
    {
        for(int j=0;j<mxn;j++)
        {
            dp[i][j]=-1;
        }
    }
    int ans[1001];
    for(int i=1;i<=1000;i++)
    {
        int x=func(2*i,i);  //catalan number formula : (2n C n - 2n c n+1)

        int y=func(2*i,i+1);

        x-=y;

        x+=mod;

        x%=mod;

        ans[i]=x;

    }


    while(1)
    {
        int n;
        cin>>n;
        if(n==0) return 0;
        cout<<ans[n]<<endl;
    }





	return 0;
}

