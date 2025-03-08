#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1e15 + 7;
int n;
struct matrix
{
    ll F[4][4];
};
ll mulNumber(ll a, ll b)
{
    if (b == 0)
        return 0;
    ll ans = mulNumber(a, b / 2);
    ans = (ans + ans) % mod;
    if (b % 2 == 1)
        ans = (ans + a) % mod;
    return ans;
}
matrix operator*(matrix a, matrix b)
{
    matrix c;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            c.F[i][j] = 0;
            for (int k = 0; k < 4; k++)
            {
                c.F[i][j] = (c.F[i][j] + mulNumber(a.F[i][k], b.F[k][j])) % mod;
            }
        }
    }
    return c;
}
matrix powMod(matrix a, int n)
{
    if (n == 1)
        return a;
    matrix x = powMod(a, n / 2);
    x = x * x;
    if (n % 2 != 0)
        x = x * a;
    return x;
}
ll x[] = {6, 3, 2, 1};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (!n)
            cout << 0 << endl;
        else if (n == 1)
            cout << 1 << endl;
        else if (n == 2)
            cout << 3 << endl;
        else if (n == 3)
            cout << 6 << endl;
        else
        {
            matrix a, res;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    a.F[i][j] = 0;
                }
            }
            a.F[0][0] = a.F[0][1] = a.F[0][2] = a.F[0][3] = a.F[1][1] = a.F[1][2] = a.F[1][3] = a.F[2][1] = a.F[3][2] = 1;
            res = powMod(a, n - 3);
            ll ans = 0;
            for (int i = 0; i < 4; ++i)
                ans = (ans + mulNumber(res.F[0][i], x[i])) % mod;
            cout << ans << endl;
        }
    }
}