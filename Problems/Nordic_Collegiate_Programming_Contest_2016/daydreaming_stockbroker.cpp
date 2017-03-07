#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
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
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector< vii> vvii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 9;
const int N=366;
//comprar no dia i tendo j acoes, maior lucro; 
ll lucro[366][100011];
int main()
{
	int n;
	cin>>n;
	memset(lucro,-LINF,sizeof(lucro));
	lucro[0][0]=100;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		for(int j=0;j<=100000;j++){
			lucro[i][j]=lucro[i-1][j];
			if(j>0){
				if(lucro[i-1][j-1]>=x)
					lucro[i][j]=max(lucro[i-1][j-1]-x,lucro[i][j]);
				if(lucro[i][j-1]>=x)
					lucro[i][j]=max(lucro[i][j-1]-x,lucro[i][j]);
			}
		}
		for(int j=100000;j>=0;j--){
			lucro[i][j]=max(lucro[i-1][j+1]+x,lucro[i][j]);
			lucro[i][j]=max(lucro[i][j+1]+x,lucro[i][j]);
		}
	}
	cout<<lucro[n][0]<<endl;
	return 0;
}
