#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

void optimize()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void setupFileIO(string fin = "data/second_hands_validation_input.txt", string fout = "data/A_output.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

void solve()
{
    int ntc;
    cin >> ntc;

    for (int tc = 1; tc <= ntc; tc++)
    {
        int N, K;
        cin >> N >> K;

        vector<int> freq(101, 0);
        bool isPossible = true;

        for (int i = 0; i < N; i++)
        {
            int style;
            cin >> style;

            freq[style]++;

            if (freq[style] > 2)
            {
                isPossible = false;
            }
        }

        if (isPossible and N <= 2 * K)
            cout << "Case #" << tc << ": "
                 << "YES"
                 << "\n";
        else
            cout << "Case #" << tc << ": "
                 << "NO"
                 << "\n";
    }
}

int main()
{
    optimize();

    setupFileIO();

    solve();

    return 0;
}