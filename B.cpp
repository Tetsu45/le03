#include <iostream>
#include <cstring>
using namespace std;
struct Process
{
    char* name[10];
    int time;
}Process;
class Queue{
    private:
    Process* processes;
    int num_process;
    int quantum;
    int front;
    public:
    Queue(){
        processes = NULL;
        num_process = 0;
        quantum  =0;
        front  = -1;
    }
    ~Queue(){
        delete[] processes;
    }
    void read_inputs(){
        std:cin >> num_process >> quantum;
        for(int i = 0; i < num_process;i++){
            char* name;int num;
            std::cin >> name >> num;
            enqueue(&i,name,num);
        }
    }
    void enqueue(int* index,char* temp,int a){
        if(num_process > 0 ) {
            processes = new Process[num_process];
        }
        std::strcpy(processes[*index]name,temp);
        processes[*index].time = a;
    }
    bool check_queue(int a){
        if(a > num_process-1){
            return false;
        }
        else return true;
    }
    Process* de_queue(int* index){
        Process temp;
        strcpy(temp.name,processes[*index].name);
        temp.time =  processes[*index].time;
        return &temp;
    }
}
int main(){
    return 0;
}