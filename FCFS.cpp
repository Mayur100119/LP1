#include <iostream>
using namespace std;

int main() {
    int bt[20], wt[20], tat[20], n;
    float wtavg = 0, tatavg = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process " << i + 1 << ": ";
        cin >> bt[i];
        if (bt[i] < 0) {
            cout << "Invalid input. Burst time must be non-negative.\n";
            return 1; // Exit with an error code
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    cout << "\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << "Average Waiting Time: " << wtavg / n << endl;
    cout << "Average Turnaround Time: " << tatavg / n << endl;

    return 0;
}
