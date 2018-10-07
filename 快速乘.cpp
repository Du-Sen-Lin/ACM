//快速乘学会了新姿势，论如何从底层优化算法
//O(log)快速乘
inline ll quick_mul(ll a,ll n,ll MOD){
    ll ans=0;
    while(n){
        if(n&1) ans=(ans+a)%MOD;
        a=(a<<1)%MOD;
        n>>=1;
    }
    return ans;
}
//o(1)快速乘
inline ll qmul(ll x, ll y, ll mod)
{
    ll t = (x * y - (ll)((long double)x / mod * y + 1.0e-8) * mod);
    return t < 0 ? t + mod : t;
}

//杜教的板子
//资料：
//https://en.wikipedia.org/wiki/Montgomery_modular_multiplication#Modular_arithmetic_and_Montgomery_form
//博客 日文 https://min-25.hatenablog.com/entry/2017/08/20/171214
//在32位上也能实现，缺点是结果很难让人相信。
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

typedef unsigned long long u64;
typedef __int128_t i128;
typedef __uint128_t u128;
int _,k;

struct Mod64 {
	Mod64():n_(0) {}
	Mod64(u64 n):n_(init(n)) {}
	static u64 init(u64 w) { return reduce(u128(w) * r2); }
	static void set_mod(u64 m) {
		mod=m; assert(mod&1);
		inv=m; rep(i,0,5) inv*=2-inv*m;
		r2=-u128(m)%m;
	}
	static u64 reduce(u128 x) {
		u64 y=u64(x>>64)-u64((u128(u64(x)*inv)*mod)>>64);
		return ll(y)<0?y+mod:y;
	}
	Mod64& operator += (Mod64 rhs) { n_+=rhs.n_-mod; if (ll(n_)<0) n_+=mod; return *this; }
	Mod64 operator + (Mod64 rhs) const { return Mod64(*this)+=rhs; }
	Mod64& operator -= (Mod64 rhs) { n_-=rhs.n_; if (ll(n_)<0) n_+=mod; return *this; }
	Mod64 operator - (Mod64 rhs) const { return Mod64(*this)-=rhs; }
	Mod64& operator *= (Mod64 rhs) { n_=reduce(u128(n_)*rhs.n_); return *this; }
	Mod64 operator * (Mod64 rhs) const { return Mod64(*this)*=rhs; }
	u64 get() const { return reduce(n_); }
	static u64 mod,inv,r2;
	u64 n_;
};
u64 Mod64::mod,Mod64::inv,Mod64::r2;

u64 pmod(u64 a,u64 b,u64 p) {
	u64 d=(u64)floor(a*(long double)b/p+0.5);
	ll ret=a*b-d*p;
	if (ret<0) ret+=p;
	return ret;
}


void bruteforce() {
	u64 ans=1;
	for (int i=0;i<=k;i++) {
		ans=pmod(ans,A0,M);
		u64 A2=pmod(M0,A1,M)+pmod(M1,A0,M)+C;
		while (A2>=M) A2-=M;
		A0=A1; A1=A2;
	}
	printf("%llu\n",ans);
}

int main()
{
	u64 a, b, c;
	Mod64::set_mod(M);

	Mod64 a0(a), b0(b), ans(0);
	scanf("%llu%llu", &a, &b);
	ans = ans + a0 + b0;

	printf("%llu\n",ans.get());
}
//题目：电音之王
//传送门：https://www.nowcoder.com/acm/contest/205/B
//o(logn)不能过掉此题，常数太大
//
//方法一：O(1)快速乘 能勉强卡过此题，
//但是重现赛时数据增强就不能了，并且本题正解并不是O(1),
//而是Montgomery modular multiplication
//Runtime
#include<bits/stdc++.h>
#define ll long long
using namespace std;
//快速乘
inline ll qmul(ll x, ll y, ll mod)
{
    ll t = (x * y - (ll)((long double)x / mod * y + 1.0e-8) * mod);
    return t < 0 ? t + mod : t;
}
int main(){
    int t;
    scanf("%d",&t);
    ll ans;
    ll a0,a1,m0,m1,c,M,k;
    while(t--){
        scanf("%lld%lld%lld%lld%lld%lld%lld",&a0,&a1,&m0,&m1,&c,&M,&k);
        ans=qmul(a0,a1,M);
        for(int i=2;i<=k;i++){
            ll cnt1=a1;
            ll cnt2=qmul(m0,a1,M)%M;
            ll cnt3=qmul(m1,a0,M)%M;
            ll cnt4=(cnt2+cnt3+c)%M;
            ans=qmul(ans,cnt4,M)%M;
            a1=cnt4;
            a0=cnt1;
        }
        cout<<ans<<endl;
    }
return 0;
}
//正解：
//AC
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
//const ll mod=1000000007;
ll mod;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

typedef unsigned long long u64;
typedef __int128_t i128;
typedef __uint128_t u128;
int _,k;

struct Mod64 {
    Mod64():n_(0) {}
    Mod64(u64 n):n_(init(n)) {}
    static u64 init(u64 w) { return reduce(u128(w) * r2); }
    static void set_mod(u64 m) {
        mod=m; assert(mod&1);
        inv=m; rep(i,0,5) inv*=2-inv*m;
        r2=-u128(m)%m;
    }
    static u64 reduce(u128 x) {
        u64 y=u64(x>>64)-u64((u128(u64(x)*inv)*mod)>>64);
        return ll(y)<0?y+mod:y;
    }
    Mod64& operator += (Mod64 rhs) { n_+=rhs.n_-mod; if (ll(n_)<0) n_+=mod; return *this; }
    Mod64 operator + (Mod64 rhs) const { return Mod64(*this)+=rhs; }
    Mod64& operator -= (Mod64 rhs) { n_-=rhs.n_; if (ll(n_)<0) n_+=mod; return *this; }
    Mod64 operator - (Mod64 rhs) const { return Mod64(*this)-=rhs; }
    Mod64& operator *= (Mod64 rhs) { n_=reduce(u128(n_)*rhs.n_); return *this; }
    Mod64 operator * (Mod64 rhs) const { return Mod64(*this)*=rhs; }
    u64 get() const { return reduce(n_); }
    static u64 mod,inv,r2;
    u64 n_;
};
u64 Mod64::mod,Mod64::inv,Mod64::r2;

u64 pmod(u64 a,u64 b,u64 p) {
    u64 d=(u64)floor(a*(long double)b/p+0.5);
    ll ret=a*b-d*p;
    if (ret<0) ret+=p;
    return ret;
}




int main()
{
    u64 a, b;

    u64 a0,a1,m0,m1,c,M;
    int k;
    //Mod64 a0(a), b0(b), ans(0);
    int t;
    scanf("%d",&t);

    while(t--){
    Mod64 ans(0);
    scanf("%llu%llu%llu%llu%llu%llu%d",&a0,&a1,&m0,&m1,&c,&M,&k);
    Mod64::set_mod(M);
    Mod64 x(a0),y(a1),z(m0),w(m1),t1(0),t2(0),t3(0);
    Mod64 t0(0);
    Mod64 u(0);
    ans=x*y;
    for(int i=2;i<=k;i++){
        t0=y;
        t1=(z*y);
        t2=(w*x);
        t3=(t1+t2+c);
        u=t3;
        ans=(ans*u);
        y=t3;
        x=t0;
    }
        printf("%llu\n",ans.get());
    }
    return 0;
}
