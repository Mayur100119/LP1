#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Process {
    int id;
    int burstTime;
    int priority;
    int remainingTime;
};

struct ComparePriority {
    bool operator()(const Process& p1, const Process& p2) {
        return p1.priority > p2.priority;
    }
};

int main() {
    int n;
    float wtavg = 0, tatavg = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter Burst Time for Process " << processes[i].id << ": ";
        cin >> processes[i].burstTime;
        cout << "Enter Priority for Process " << processes[i].id << ": ";
        cin >> processes[i].priority;
        processes[i].remainingTime = processes[i].burstTime;
    }

    int currentTime = 0;
    priority_queue<Process, vector<Process>, ComparePriority> readyQueue;

    while (true) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0 && processes[i].priority > 0 && processes[i].priority < readyQueue.top().priority) {
                readyQueue.push(processes[i]);
                processes[i].priority = 0;
            }
        }

        if (!readyQueue.empty()) {
            Process currentProcess = readyQueue.top();
            readyQueue.pop();

            currentProcess.remainingTime--;

            if (currentProcess.remainingTime == 0) {
                int turnaroundTime = currentTime + 1;
                int waitingTime = turnaroundTime - currentProcess.burstTime;
                wtavg += waitingTime;
                tatavg += turnaroundTime;
            } else {
                readyQueue.push(currentProcess);
            }

            currentTime++;
        } else {
            // If the ready queue is empty, no processes can execute.
            bool allProcessesCompleted = true;
            for (int i = 0; i < n; i++) {
                if (processes[i].remainingTime > 0) {
                    allProcessesCompleted = false;
                    break;
                }
            }
            if (allProcessesCompleted) {
                break;
            } else {
                currentTime++;
            }
        }
    }

    cout << "PROCESS\tBURST TIME\tPRIORITY\tWAITING TIME\tTURNAROUND TIME\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t" << processes[i].burstTime << "\t" << processes[i].priority << "\t"
             << processes[i].burstTime - processes[i].remainingTime << "\t" << processes[i].burstTime - processes[i].remainingTime + (processes[i].burstTime - processes[i].remainingTime) << endl;
    }

    cout << "Average Waiting Time is: " << wtavg / n << endl;
    cout << "Average Turnaround Time is: " << tatavg / n << endl;

    return 0;
}
