#include <bits/stdc++.h>

#define mx 10000
#define mod 1000000007
#define ll long long

using namespace std;

void optimize()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void setupFileIO(string fin = "data/weak_typing_chapter_2_validation_input.txt", string fout = "data/A2Output.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

int moduloMultiplication(int a, int b)
{
    int res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }

    return res;
}

void solve()
{
    int ntc;
    cin >> ntc;

    for (int tc = 1; tc <= ntc; tc++)
    {
        int N;
        string W;
        cin >> N >> W;

        int nSwitch[N + 5], rSwitch[N + 5];
        for (int i = 0; i < N; i++)
        {
            nSwitch[i] = 0;
            rSwitch[i] = 0;
        }

        int prevI = -1, firstSwitch = -1, ans = 0;

        for (int i = 0; i < N; i++)
        {
            if (i > 0)
                nSwitch[i] = nSwitch[i - 1];

            if (W[i] == 'F')
                continue;

            if (prevI != -1 && W[prevI] != W[i])
            {
                nSwitch[i]++;
                rSwitch[prevI + 1]++;
                if (firstSwitch == -1)
                    firstSwitch = i;
            }

            prevI = i;
        }

        for (int i = 1; i < N; i++)
        {
            rSwitch[i] = (rSwitch[i] + rSwitch[i - 1]) % mod;
        }

        // for (int i = 1; i < N; i++)
        // {
        //     rSwitch[i] = (rSwitch[i] + rSwitch[i - 1]) % mod;
        // }

        for (int i = 1; i < N; i++)
        {
            // ans = (ans + ((1LL * i * nSwitch[i]) % mod - rSwitch[i - 1] % mod)) % mod;
            for (int j = 0; j < i; j++)
            {
                if (nSwitch[i] < rSwitch[j])
                    continue;
                ans = (0LL + ans + nSwitch[i] - rSwitch[j]) % mod;
                if (ans < 0)
                    ans %= mod;
            }
        }

        cout << "Case #" << tc << ": " << ans << "\n";
    }
}

int main()
{
    optimize();

    setupFileIO();

    solve();

    return 0;
}