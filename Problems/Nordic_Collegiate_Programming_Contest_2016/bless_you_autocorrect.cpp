#include <bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define imprime(x, Y)                               \
	for (int X = 0; X < Y; X++) cerr << x[X] << " "; \
cerr << endl;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 7;
const int N=1e6+10;
const int M=26;
int to[N][M],sz=1,tab[N],pai[N],dp[N];
vi graph[N];
void add_str(string &s){
	int v=0;
	for(int i=0;i<s.size();i++) s[i]-='a';
	for(char c: s){
		if(!to[v][c]) to[v][c]=sz++;
		int x=v;
		v=to[v][c];
		pai[v]=x;
	}
	int onde=v;
	v=0;
	for(char c: s){
		v=to[v][c];
		if(tab[v]==0)
			tab[v]=onde;
	}
}
void process()
{
	queue<int> q;
	memset(dp,INF,sizeof(dp));
	q.push(0);dp[0]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<M;i++){
			int x=to[u][i];
			if(dp[x]==INF) {
				dp[x]=dp[u]+1;
				q.push(x);
			}
		}
		if(dp[tab[u]]==INF){
			dp[tab[u]]=dp[u]+1;
			q.push(tab[u]);
		}
		if(dp[pai[u]]==INF){
			dp[pai[u]]=dp[u]+1;
			q.push(pai[u]);
		}
	}
}
int answer(string &s){
	for(int i=0;i<s.size();i++) s[i]-='a';
	int ret=s.size();
	int v=0;
	for(int i=0;i<s.size();i++){
		int c=s[i];
		if(!to[v][c]) break;
		v=to[v][c];
		ret=min(ret,(int)s.size()-i-1+dp[v]);
	}
	return ret;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		add_str(s);
	}
	process();
	for(int i=0;i<m;i++){
		string s;
		cin>>s;
		cout<<answer(s)<<endl;
	}
	return 0;
}

