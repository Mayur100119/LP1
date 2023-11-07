#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int numFrames, numPages, pageFaults = 0;

    cout << "Enter the number of frames: ";
    cin >> numFrames;

    cout << "Enter the number of pages: ";
    cin >> numPages;

    vector<int> referenceString(numPages);

    cout << "Enter the reference string: ";
    for (int i = 0; i < numPages; i++) {
        cin >> referenceString[i];
    }

    deque<int> frames;

    cout << "\nPage Replacement Process:\n";
    for (int i = 0; i < numPages; i++) {
        int page = referenceString[i];
        bool pageFound = false;

        for (int j = 0; j < frames.size(); j++) {
            if (frames[j] == page) {
                pageFound = true;
                break;
            }
        }

        if (!pageFound) {
            if (frames.size() < numFrames) {
                frames.push_back(page);
            } else {
                int replacedPage = frames.front();
                frames.pop_front();
                frames.push_back(page);
                cout << "Page " << replacedPage << " replaced by Page " << page << endl;
            }
            pageFaults++;
        }

        cout << "Frames: ";
        for (int j = 0; j < frames.size(); j++) {
            cout << frames[j] << " ";
        }

        cout << "Page Faults: " << pageFaults << endl;
    }

    cout << "\nThe number of Page Faults using FIFO is: " << pageFaults << endl;

    return 0;
}
