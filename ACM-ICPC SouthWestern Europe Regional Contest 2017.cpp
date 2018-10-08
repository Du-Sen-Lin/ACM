//A
//两个数组 找到第二个数组比第一个数组大的算差值，
//差值最多最小的即为所求。
//注意特殊情况，如果第二位全大于第一位输出为0。
/***
#include<bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int a[maxn],b[maxn];
map<int,int> mm;
int main()
{
    int n,m;
    mm.clear();
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=m; i++)
        scanf("%d",&b[i]);
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int chk = b[i] - a[j];
            if(chk>0)
                mm[chk]++;
        }
    }
    map<int,int>::iterator ite;
    int tim=-1,ans=1e9+10;
    for(ite=mm.begin(); ite!=mm.end(); ite++)
    {
        if(ite->second > tim)
        {
            tim = ite->second;
            ans = ite->first;
        }
        if(ite->second == tim)
        {
            ans = min(ite->first,ans);
        }
    }
    if(ans == 1e9+100)
        cout<<"0"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}
***/
//B unsloved

//C unsloved 递推+矩阵快速幂


//D unsolved

//E unsolved 01背包 拓扑预处理
/*
15 6
pizza_tomato pizza_base tomato 1 2
pizza_cheese pizza_base cheese 5 10
pizza_classic pizza_tomato cheese 5 5
pizza_classic pizza_cheese tomato 1 2
pizza_salami pizza_classic salami 7 6
pizza_spicy pizza_tomato chili 3 1
*/

//F 签到 ans+=x*y ; ans/w=L;

//G unsloved

//H unsloved

//I unsloved

//J 找到每个颜色的面积 暴力1e10会T 先分别处理A B
/***
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 100100;
ll a[3],b[3];
ll ans1,ans2,ans3;
int main()
{
    int x1,x2;
    ans1=ans2=ans3=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int n;

    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&x1);
        a[i%3]+=x1;
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&x2);
        b[i%3]+=x2;
    }
   ans1=a[0]*b[0]+a[1]*b[2]+a[2]*b[1];
   ans2=a[0]*b[1]+a[1]*b[0]+a[2]*b[2];
   ans3=a[0]*b[2]+a[2]*b[0]+a[1]*b[1];
   printf("%lld %lld %lld\n",ans1,ans2,ans3);
    return 0;
}
***/




//K 模板题 旋转卡壳，计算凸包的宽度
//题意：给定N个点，用矩形将所有点覆盖，要求矩形宽度最小。
//思路：裸题，旋转卡壳去rotate即可。
/***
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+100;
struct P{
    ll x,y;
    P(ll _x=0,ll _y=0){x=_x;y=_y;}
    P operator -(P b)const{
        return P(x - b.x, y - b.y);
    }
    ll operator ^(P b)const{  //计算叉积
        return x*b.y - y*b.x;
    }
}s[N],ch[N];
int top,n,m;
ll cs(P p0,P p1,P p2){  //向量p0->p1 叉乘  向量p0->p2
    return (p1.x-p0.x)*(p2.y-p0.y) - (p1.y-p0.y)*(p2.x-p0.x);
}
double pow2(double x){
    return x*x;
}
double dis(P p1,P p2){
    return sqrt(pow2(p1.x-p2.x)+pow2(p1.y-p2.y));
}
bool cmp(P p1,P p2){
    ll tmp = cs(s[0],p1,p2);
    if(tmp>0) return 1;
    if(tmp<0) return 0;
    return dis(s[0],p1)<dis(s[0],p2);
}
void init(){
    scanf("%d%d",&n,&m);
    P p0(0,1e9);
    int k;
    for(int i = 0;i < n;i ++){
        scanf("%lld%lld",&s[i].x,&s[i].y);
        if(p0.y>s[i].y||(p0.y==s[i].y&&p0.x>s[i].x)) p0 = s[i],k = i;
    }
    swap(s[0],s[k]);
    sort(s+1,s+n,cmp);  //极角排序，跳过第0个
}
void graham(){    //生成凸包,ch从0开始存放
    if(n==1) ch[top++] = s[0];
    else
        for(int i = 0;i < n;i ++){
            while(top>1&&cs(ch[top-2],ch[top-1],s[i])<=0) top --;
            ch[top++] = s[i];
        }
}
double len(P a,P b,P c){   //两点式情况下点到直线的距离
    double s = fabs(cs(a,b,c));
    return s/dis(a,b);
}
double cps(){     //旋转卡壳
    if(top<=2) return 0;   //判断凸包退化成线段的情况
    double ans = 9e18;
    int cur = 1;
    for(int i = 1;i <= top;i ++){
        P v = ch[i-1] - ch[i%top];
        while((v^(ch[(cur+1)%top]-ch[cur]))<0) cur = (cur+1)%top;
        ans = min(ans,len(ch[i-1],ch[i%top],ch[cur]));
    }
    return ans;
}
int main(){
    init();
    graham();
    printf("%.8f",cps());
    return 0;
}
***/

//待补
//旋转卡壳，计算凸包最长直径==长度
//poj 选美大赛 http://poj.org/problem?id=2187



//旋转卡壳，计算凸包最短直径

//旋转卡壳，找出所有直径

//两不相交的凸包的最大距离，最小距离




