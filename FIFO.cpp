#include <iostream>
using namespace std;

int main() {
    int referenceString[25], frames[10], pageFaults = 0, numFrames;

    cout << "Enter the length of the reference string: ";
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input for the length of the reference string.\n";
        return 1; // Exit with an error code
    }

    cout << "Enter the reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> referenceString[i];
    }

    cout << "Enter the number of frames: ";
    cin >> numFrames;

    if (numFrames <= 0) {
        cout << "Invalid input for the number of frames.\n";
        return 1; // Exit with an error code
    }

    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
    }

    int count = 0; // Initialize the frame index

    cout << "\nPage Replacement Process:\n";
    for (int i = 0; i < n; i++) {
        int page = referenceString[i];
        bool pageFound = false;

        for (int k = 0; k < numFrames; k++) {
            if (frames[k] == page) {
                pageFound = true;
                break;
            }
        }

        if (!pageFound) {
            frames[count] = page;
            count = (count + 1) % numFrames; // Update the frame index
            pageFaults++;
        }

        for (int j = 0; j < numFrames; j++) {
            cout << "\t" << frames[j];
        }

        if (!pageFound) {
            cout << "\tPF No. " << pageFaults;
        }
        cout << endl;
    }

    cout << "\nThe number of Page Faults using FIFO is: " << pageFaults << endl;

    return 0;
}
