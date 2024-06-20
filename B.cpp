#include <iostream>
#include <cstring>
using namespace std;

struct Process {
    char name[11];
    int burstTime;
    int completionTime;
};

class Queue {
private:
    Process* processes;
    Process* readyQueue;
    int head;
    int tail;
    int size;
    int queueSize;
public:
    Queue(){
        processes = NULL;
        readyQueue = NULL;
        head = 0;
        tail = 0;
        size = 0;
        queueSize = 0;
    }

    ~Queue() {
        delete[] processes;
        delete[] readyQueue;
    }

    void read_inputs(const int& n) {
        processes = new Process[n];
        readyQueue = new Process[n];
        for (int i = 0; i < n; i++) {
            cin >> processes[i].name;
            cin >> processes[i].burstTime;
            processes[i].completionTime = 0;
        }
        size = n;
    }

    void enqueue(Process* process) {
        readyQueue[tail] = process;
        tail = (tail + 1) % size;
        queueSize++;
    }

    Process* dequeue() {
        Process* process = readyQueue[head];
        head = (head + 1) % size;
        queueSize--;
        return process;
    }

    bool isEmpty() {
        return queueSize == 0;
    }

    Process* time(const int& n, const int& q) {
        int currentTime = 0;
        int finishedCount = 0;
        Process* finishedList = new Process[n];

        // Initialize ready queue with all processes
        for (int i = 0; i < n; i++) {
            enqueue(&processes[i]);
        }

        while (finishedCount < n) {
            Process* currentProcess = dequeue();

            int remainBurst = (currentProcess->burstTime > q) ? q : currentProcess->burstTime;
            currentTime += remainBurst;
            currentProcess->burstTime -= remainBurst;

            if (currentProcess->burstTime == 0) {
                currentProcess->completionTime = currentTime;
                finishedList[finishedCount] = *currentProcess;
                finishedCount++;
            } else {
                enqueue(currentProcess);
            }
        }

        return finishedList;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    Queue roundQueue;
    roundQueue.read_inputs(n);
    Process* finished_list = roundQueue.time(n, q);
    for (int i = 0; i < n; i++) {
        cout << finished_list[i].name << " " << finished_list[i].completionTime << endl;
    }
    delete[] finished_list;
    return 0;
}