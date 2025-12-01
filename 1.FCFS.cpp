#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> at(n), bt(n), ft(n), tat(n), wt(n);

    for (int i = 0; i < n; i++) {
        cout << "Arrival time for P" << i+1 << ": ";
        cin >> at[i];
        cout << "Burst time for P" << i+1 << ": ";
        cin >> bt[i];
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 1);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[j] < at[i]) {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    ft[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        ft[i] = max(ft[i - 1], at[i]) + bt[i];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ft[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout << "P  AT  BT  FT  TAT  WT\n";
    for (int i = 0; i < n; i++)
        cout << p[i] << "  " << at[i] << "  " << bt[i]
             << "  " << ft[i] << "  " << tat[i] << "  " << wt[i] << "\n";

    return 0;
}
