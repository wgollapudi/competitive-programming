#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll in[n];
    for (ll i = 0; i < n; i++) {
        cin >> in[i];
    }

    ll max = -1;

    for (ll i = 1; i < n - 1; i++) {
        ll offset = 1;
        while (true) {
            ll ihigh = i + offset;
            ll ilow = i - offset;
            if ((ihigh >= n) || (ilow < 0) || (in[ihigh]!=in[ilow]) || (in[ilow]>=in[ilow+1])) break;
            offset++;
        }
        ll count = 2*offset - 1;
        if ((count > 2) && (count > max)) max = count;
    }

    cout << max << '\n';
}
