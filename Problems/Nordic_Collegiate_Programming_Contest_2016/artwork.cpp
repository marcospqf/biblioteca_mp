#include <cassert>
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
const int N = 1010;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, q;
int tab[N][N], us[N][N], cor = 1;
const int M = 1000100;
int p[M], Rank[M];
void init()
{
	memset(Rank, 0, sizeof(Rank));
	for (int i = 0; i < M; i++) p[i] = i;
}
int findSet(int i)
{
	if (p[i] == i) return i;
	return p[i] = findSet(p[i]);
}
bool sameSet(int i, int j) { return (findSet(i) == findSet(j)); }
void unionSet(int i, int j)
{
	if (!sameSet(i, j)) {
		int x = findSet(i), y = findSet(j);
		if (Rank[x] > Rank[y])
			p[y] = x;
		else {
			p[x] = y;
			if (Rank[x] == Rank[y]) Rank[y]++;
		}
	}
}

inline bool inside(int x, int y)
{
	return (x >= 1 and x <= n and y <= m and y >= 1);
}

void bfs(ii b)
{
	queue<ii> q;
	q.push(b);
	us[b.first][b.second] = cor;
	while (!q.empty()) {
		ii topo = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = topo.first + dx[i];
			int y = topo.second + dy[i];
			if (!inside(x, y)) continue;
			if (!us[x][y] and tab[x][y] == 0) {
				us[x][y] = cor;
				q.push({x, y});
			}
		}
	}
}
vector<pair<ii, ii> > query;

inline void lin(int idx, int b, int e)
{
	for (int i = b; i <= e; i++) tab[idx][i]++;
}
inline void col(int idx, int b, int e)
{
	for (int i = b; i <= e; i++) tab[i][idx]++;
}
bool cu=false;
inline int arrumalin(int idx, int b, int e)
{
	int ret = 0;
	set<int> vizinhos;
	bool foi = false;
	for (int i = b; i <= e; i++) {
		if (tab[idx][i] != 1) continue;
		for (int j = 0; j < 4; j++) {
			foi = true;
			int x = idx + dx[j];
			int y = i + dy[j];
			if (inside(x, y) and tab[x][y] == 0) {
				vizinhos.insert(us[x][y]);
			}
		}
	}
	if (vizinhos.size() == 0 and foi) {
		ret++;
		for (int i = b; i <= e; i++) {
			tab[idx][i]--;
			if (tab[idx][i] == 0) {
				us[idx][i] = cor;
			}
		}
		cor++;
	}
	else {
		for (int i = b; i <= e; i++) tab[idx][i]--;

		if (!foi) return 0;
		for (int i = b; i <= e; i++)
			if (tab[idx][i] == 0) us[idx][i] = *vizinhos.begin();
		for (int x : vizinhos)
			if (!sameSet(x, *vizinhos.begin()))
				ret--, unionSet(x, *vizinhos.begin());
	}
	return ret;
}

inline int arrumacol(int idx, int b, int e)
{
	int ret = 0;
	set<int> vizinhos;
	bool foi = false;
	for (int i = b; i <= e; i++) {
		if (tab[i][idx] != 1) continue;
		for (int j = 0; j < 4; j++) {
			foi = true;
			int y = idx + dy[j];
			int x = i + dx[j];
			if (inside(x, y) and tab[x][y] == 0)
				vizinhos.insert(findSet(us[x][y]));
		}
	}
	if (vizinhos.size() == 0 and foi) {
		ret++;
		for (int i = b; i <= e; i++) {
			tab[i][idx]--;
			if (tab[i][idx] == 0) {
				us[i][idx] = cor;
			}
		}
		cor++;
	}
	else {
		for (int i = b; i <= e; i++) tab[i][idx]--;
		if (!foi) return 0;
		for (int i = b; i <= e; i++) {
			if (tab[i][idx] == 0) us[i][idx] = *vizinhos.begin();
		}
		for (int x : vizinhos)
			if (!sameSet(x, *vizinhos.begin()))
				ret--, unionSet(x, *vizinhos.begin());
	}
	return ret;
}
vii arruma(int idx, int b, int e)
{
	vii ret;
	int L = b;
	assert(idx<=n);
	assert(e<=m);
	for (int i = b; i <= e; i++) {
		if (tab[idx][i] == 1)
			continue;
		else {
			ret.pb({L, i});
			L = i + 1;
		}
	}
	if (L <= e) {
		ret.pb({L, e});
	}
	return ret;
}

vii arruma2(int idx, int b, int e)
{
	vii ret;
	int L = b;
	for (int i = b; i <= e; i++) {
		if (tab[i][idx] == 1)
			continue;
		else {
			ret.pb({L, i});
			L = i + 1;
		}
	}
	if (L <= e) {
		ret.pb({L, e});
	}
	return ret;
}

int main()
{
	sc3(m, n, q);
	for (int i = 0; i < q; i++) {
		int x, y, x2, y2;
		sc2(y, x);
		sc2(y2, x2);
		query.pb({{x, y}, {x2, y2}});
	}
	for (int i = 0; i < q; i++) {
		if (query[i].first.first == query[i].second.first) {
			lin(query[i].first.first, query[i].first.second,
					query[i].second.second);
		}
		else {
			col(query[i].first.second, query[i].first.first,
					query[i].second.first);
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (tab[i][j] == 0 and !us[i][j]) {
				bfs({i, j});
				cor++;
			}
	vi resp;
	int reg = cor - 1;
	resp.pb(reg);
	init();
	for (int i = q - 1; i >= 1; i--) {
		if (query[i].first.first == query[i].second.first) {
			vii inter = arruma(query[i].first.first, query[i].first.second,
					query[i].second.second);
			for (ii x : inter){
				reg += arrumalin(query[i].first.first, x.first, x.second);
			}
		}
		else {
			vii inter = arruma2(query[i].first.second, query[i].first.first,
					query[i].second.first);
			for (ii x : inter)
				reg += arrumacol(query[i].first.second, x.first, x.second);
		}
		assert(reg >= 0);
		resp.pb(reg);
	}
	reverse(resp.begin(), resp.end());
	for (int x : resp) pri(x);
	return 0;
}

