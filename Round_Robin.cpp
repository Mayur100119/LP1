#include <iostream>
using namespace std;

int main() {
    int n, t;
    float awt = 0, att = 0;

    cout << "Enter the number of processes: ";
    cin >> n;
    int bu[n], wa[n], tat[n], ct[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time for process " << i + 1 << ": ";
        cin >> bu[i];
        ct[i] = bu[i];
    }

    cout << "Enter the time slice (quantum): ";
    cin >> t;

    int max = bu[0];
    for (int i = 1; i < n; i++) {
        if (max < bu[i]) {
            max = bu[i];
        }
    }

    int temp = 0;
    for (int j = 0; j < (max / t) + 1; j++) {
        for (int i = 0; i < n; i++) {
            if (bu[i] != 0) {
                if (bu[i] <= t) {
                    tat[i] = temp + bu[i];
                    temp += bu[i];
                    bu[i] = 0;
                } else {
                    bu[i] -= t;
                    temp += t;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wa[i];
    }

    cout << "The Average Turnaround time is: " << att / n << endl;
    cout << "The Average Waiting time is: " << awt / n << endl;

    cout << "\nPROCESS\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t " << ct[i] << "\t\t " << wa[i] << "\t\t " << tat[i] << endl;
    }

    return 0;
}
