#include <bits/stdc++.h>

using namespace std;

long double prob(long double n, long double p, long double a) {
	long double ans = a*p/(n+a-p+1);
	for (int i = 0; i < p-1; i++)
		ans *= (n-i)/(n+a-i);
	return ans;
}

int main() {
	int n, p;
	cin >> n >> p;
	cout << setprecision(11) << fixed;
	cout << prob(n, p, n/(p-1)) << endl;
}

