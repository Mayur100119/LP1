#include <iostream>
using namespace std;

int main() {
    int p[20], bt[20], pri[20], wt[20], tat[20], n, temp;
    float wtavg = 0, tatavg = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        p[i] = i;
        cout << "Enter the Burst Time and Priority of Process " << i + 1 << ": ";
        cin >> bt[i] >> pri[i];
    }

    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if (pri[i] > pri[k]) {
                // Swap process id, burst time, and priority
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
            }
        }
    }

    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    cout << "\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
    for (int i = 0; i < n; i++) {
        cout << p[i] << "\t" << pri[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
    }

    cout << "Average Waiting Time is: " << wtavg / n << endl;
    cout << "Average Turnaround Time is: " << tatavg / n << endl;

    return 0;
}
