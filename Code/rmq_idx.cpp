int tr[4 * N], v[N];
void build(int node, int b, int e)
{
    if (b == e)
        tr[node] = b;
    else {
        build(2 * node, b, (b + e) / 2);
        build(2 * node + 1, (b + e) / 2 + 1, e);
        if (v[tr[2 * node]] <= v[tr[2 * node + 1]])
            tr[node] = tr[2 * node];
        else
            tr[node] = tr[2 * node + 1];
    }
}
int query(int node, int b, int e, int i, int j)
{
    int p1, p2;
    if (i > e or j < b) return -1;
    if (b >= i and e <= j) return tr[node];
    p1 = query(2 * node, b, (b + e) / 2, i, j);
    p2 = query(2 * node + 1, (b + e) / 2 + 1, e, i, j);
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    if (v[p1] <= v[p2]) return p1;
    return p2;
}

void atualiza(int node, int b, int e, int i, int val)
{
    if (i > e or i < b) return;
    if (e == b) {
        v[b] = val;
    }
    else {
        atualiza(2 * node, b, (b + e) / 2, i, val);
        atualiza(2 * node + 1, (b + e) / 2 + 1, e, i, val);
        if (v[tr[2 * node]] <= v[tr[2 * node + 1]])
            tr[node] = tr[2 * node];
        else
            tr[node] = tr[2 * node + 1];
    }
}
