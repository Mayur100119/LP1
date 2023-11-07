#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nb, nf;
    cout << "\n\tMemory Management Scheme - Worst Fit" << endl;
    cout << "Enter the number of blocks:";
    cin >> nb;
    cout << "Enter the number of files:";
    cin >> nf;

    vector<int> b(nb);  
    vector<int> f(nf);  
    vector<int> frag(nf, 0);
    vector<int> bf(nb, 0);
    vector<int> ff(nf, -1);  

    cout << "\nEnter the size of the blocks:-" << endl;
    for (int i = 0; i < nb; i++) {
        cout << "Block " << i << ":";
        cin >> b[i];
    }

    cout << "Enter the size of the files :-" << endl;
    for (int i = 0; i < nf; i++) {
        cout << "File " << i << ":";
        cin >> f[i];
    }

    for (int i = 0; i < nf; i++) {
        int highest = -1;
        for (int j = 0; j < nb; j++) {
            if (bf[j] == 0) {
                int temp = b[j] - f[i];
                if (temp >= 0 && temp > highest) {
                    ff[i] = j;
                    highest = temp;
                }
            }
        }
        if (ff[i] != -1) {
            frag[i] = highest;
            bf[ff[i]] = 1;
        }
    }

    cout << "\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragment" << endl;
    for (int i = 0; i < nf; i++) {
        cout << i << "\t\t" << f[i] << "\t\t";
        if (ff[i] != -1) {
            cout << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i] << endl;
        } else {
            cout << "Not Allocated\t\t-1\t\t-1" << endl;
        }
    }

    return 0;
}
