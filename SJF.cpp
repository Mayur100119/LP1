#include <iostream>
using namespace std;

int main() {
    int p[20], bt[20], wt[20], tat[20], n, temp;
    float wtavg = 0, tatavg = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        p[i] = i + 1;  // Start process numbering from 1
        cout << "Enter Burst Time for Process " << p[i] << ": ";
        cin >> bt[i];
        if (bt[i] < 0) {
            cout << "Invalid input. Burst time must be non-negative.\n";
            return 1; // Exit with an error code
        }
    }

    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if (bt[i] > bt[k]) {
                // Swap burst time and process ID
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
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
        cout << "P" << p[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
    }

    cout << "Average Waiting Time: " << wtavg / n << endl;
    cout << "Average Turnaround Time: " << tatavg / n << endl;

    return 0;
}
