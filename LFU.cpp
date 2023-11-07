#include <iostream>
using namespace std;

int main() {
    int referenceString[50], frames[20], counters[20], m, numFrames, min, pageFaults = 0;

    cout << "Enter the number of page references: ";
    cin >> m;

    if (m <= 0) {
        cout << "Invalid input for the number of page references.\n";
        return 1; // Exit with an error code
    }

    cout << "Enter the reference string: ";
    for (int i = 0; i < m; i++) {
        cin >> referenceString[i];
    }

    cout << "Enter the available number of frames: ";
    cin >> numFrames;

    if (numFrames <= 0) {
        cout << "Invalid input for the number of frames.\n";
        return 1; // Exit with an error code
    }

    for (int i = 0; i < numFrames; i++) {
        counters[i] = 0;
        frames[i] = -1;
    }

    cout << "\nPage Replacement Process:\n";
    for (int i = 0; i < m; i++) {
        int page = referenceString[i];
        bool pageFound = false;

        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == page) {
                pageFound = true;
                counters[j]++;
                break;
            }
        }

        if (!pageFound) {
            min = 0;
            for (int k = 1; k < numFrames; k++) {
                if (counters[k] < counters[min]) {
                    min = k;
                }
            }
            frames[min] = page;
            counters[min] = 1;
            pageFaults++;
        }

        for (int j = 0; j < numFrames; j++) {
            cout << "\t" << frames[j];
        }

        cout << "\tPage Fault No. " << pageFaults << endl;
    }

    cout << "\nTotal number of page faults: " << pageFaults << endl;

    return 0;
}
