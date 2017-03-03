// Chinese remainder theorem (special case): find z such that // z % m1 = r1, z
// % m2 = r2. Here, z is unique modulo M = lcm(m1, m2). // Return (z, M). On
// failure, M = -1;
ii chinese_remainder_theorem(int m1, int r1, int m2, int r2)
{
  int s, t;
  int g = extended_euclid(m1, m2, s, t);
  if (r1 % g != r2 % g) return mp(0, -1);
  return mp(mod(s * r2 * m1 + t * r1 * m2, m1 * m2) / g, m1 * m2 / g);
}
// Chinese remainder theorem: find z such that // z % m[i] =
// r[i] for all i
//    .Note that the solution is   unique modulo M = lcm_i (m[i]).
//    Return(z, M)
//    .On  // failure, M = -1. Note that we do not require the a[i]’s
// to be relatively prime.
ii chinese_remainder_theorem(const vi &m, const vi &r)
{
  ii ret = make_pair(r[0], m[0]);
  for (int i = 1; i < m.size(); i++) {
    ret = chinese_remainder_theorem(ret.second, ret.first, m[i], r[i]);
    if (ret.second == -1) break;
  }
  return ret;
}
