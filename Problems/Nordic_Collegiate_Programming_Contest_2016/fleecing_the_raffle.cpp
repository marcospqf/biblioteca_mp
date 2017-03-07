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
typedef vector<vii> vvii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 9;
int n, p;
ld calc()
{
	ld resp = (ld)p;
	int k=1e7;
	ld last=-1;
	for (int i = 1; i <= (n + k); i++) {
		if (i <= n) resp *= i;
		if (i <= (n - p + 1)) resp /= i;
		if (i <= n - p) resp *= i;
		resp /= i;
		if(i>n){
			if(last==0) last=resp*(i-n)*(i-p);
			else if(last<resp*(i-n)*(i-p)){
				last=resp*(i-n)*(i-p);
			}
			else{
				break;
			}
			resp*=(i-p);
		}
	}
	return last;
}
int main()
{
	BUFF;
	cin >> n >> p;
	cout << fixed << setprecision(16);
	ld resp=calc(); 
	cout << resp << endl;
	return 0;
}

