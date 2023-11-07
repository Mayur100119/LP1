#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Process {
    int id;
    int burstTime;
    int arrivalTime;
    int remainingTime;
};

int main() {
    int n;
    float wtavg = 0, tatavg = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes;
    for (int i = 0; i < n; i++) {
        Process p;
        p.id = i + 1;
        cout << "Enter Arrival Time for Process " << p.id << ": ";
        cin >> p.arrivalTime;
        cout << "Enter Burst Time for Process " << p.id << ": ";
        cin >> p.burstTime;
        p.remainingTime = p.burstTime;
        processes.push_back(p);
    }

    int currentTime = 0;
    int completed = 0;

    while (completed < n) {
        int shortestIndex = -1;
        int shortestBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime < shortestBurst && processes[i].remainingTime > 0) {
                shortestIndex = i;
                shortestBurst = processes[i].remainingTime;
            }
        }

        if (shortestIndex == -1) {
            currentTime++;
        } else {
            Process& currentProcess = processes[shortestIndex];
            currentProcess.remainingTime--;
            currentTime++;

            if (currentProcess.remainingTime == 0) {
                completed++;
                int turnaroundTime = currentTime - currentProcess.arrivalTime;
                int waitingTime = turnaroundTime - currentProcess.burstTime;

                wtavg += waitingTime;
                tatavg += turnaroundTime;

                cout << "Process " << currentProcess.id << " completed. Turnaround Time: " << turnaroundTime << " Waiting Time: " << waitingTime << endl;
            }
        }
    }

    cout << "Average Waiting Time: " << wtavg / n << endl;
    cout << "Average Turnaround Time: " << tatavg / n << endl;

    return 0;
}
