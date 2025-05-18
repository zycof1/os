#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid, bt, at, priority, ct, tat, wt;
};

bool cmpAT(Process a, Process b) { return a.at < b.at; }
bool cmpBT(Process a, Process b) { return a.bt < b.bt; }
bool cmpPriority(Process a, Process b) { return a.priority < b.priority; }

void calcTimes(Process p[], int n) {
    p[0].ct = p[0].at + p[0].bt;
    for (int i = 1; i < n; i++)
        p[i].ct = max(p[i - 1].ct, p[i].at) + p[i].bt;
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}

void printTable(Process p[], int n) {
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
        cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t"
             << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << endl;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter AT, BT, Priority for P" << i + 1 << ": ";
        cin >> p[i].at >> p[i].bt >> p[i].priority;
    }

    int choice;
    cout << "\nChoose Scheduling Algorithm:\n1.FCFS\n2.SJF\n3.Priority\nChoice: ";
    cin >> choice;

    sort(p, p + n, cmpAT);  // FCFS base

    if (choice == 2)
        sort(p, p + n, cmpBT);
    else if (choice == 3)
        sort(p, p + n, cmpPriority);

    calcTimes(p, n);
    printTable(p, n);
}
