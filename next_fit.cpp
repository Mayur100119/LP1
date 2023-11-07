#include <iostream>
#include <vector>
using namespace std;

void NextFit(vector<int>& blockSize, int n, vector<int>& processSize, int m) {
    vector<int> allocation(m, -1);
    int j = 0, t = n - 1;

    for (int i = 0; i < m; i++) {
        while (j < n) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                t = (j - 1) % n;
                break;
            }
            if (t == j) {
                t = (j - 1) % n;
                break;
            }
            j = (j + 1) % n;
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < m; i++) {
        cout << " " << i + 1 << "\t\t\t\t" << processSize[i] << "\t\t\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main() {
    vector<int> blockSize = {5, 10, 20};
    vector<int> processSize = {10, 20, 5};
    int n = blockSize.size();
    int m = processSize.size();

    NextFit(blockSize, n, processSize, m);

    return 0;
}
