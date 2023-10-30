#include<bits/stdc++.h>

using namespace std;

struct process{
    int at, bt, pr, pno;
};

bool compare(process a, process b){
    if(a.at == b.at){
        return a.pr < b.pr;
    }else{
        return a.at < b.at;
    }
}

void findWaitingTime(process proc[], int n, int wt[]){
    int service[50];
    service[0] = proc[0].at;
    wt[0] = 0;

    for(int i = 1; i < n; i++){
        service[i] = service[i-1] + proc[i-1].bt;
        wt[i] = service[i] - proc[i].at;
        if(wt[i] < 0) wt[i] = 0; 
    }
}

void findTurnAroundTime(process proc[], int n, int wt[], int tat[]){
    for(int i = 0; i < n; i++){
        tat[i] = proc[i].bt + wt[i];
    }
}


void findAvgTime(process proc[], int n){
    int wt[50], tat[50];

    findWaitingTime(proc, n, wt);

    findTurnAroundTime(proc, n, wt, tat);

    int stime[50], ctime[50];
    double wavg = 0, tavg = 0;
    stime[0] = proc[0].at;
    ctime[0] = stime[0] + tat[0];

    for(int i = 1; i < n; i++){
        stime[i] = ctime[i-1];
        ctime[i] = stime[i] + tat[i] - wt[i];
    }

    cout<<"process no."<<" start time "<<" completion time "<<" wait time "<<" turn around time \n";
    for(int i = 0; i < n; i++){
        wavg = wavg + wt[i];
        tavg = tavg + tat[i];

        cout<<proc[i].pno<<" \t "<<stime[i]<<" \t "<<ctime[i]<<" \t "<<wt[i]<<" \t "<<tat[i]<<endl;
    }
    cout<<"Average wait time: "<<(wavg/(double)n)<<endl;
    cout<<"Average turn around time: "<<(tavg/(double)n)<<endl;
}

int main(){
    int n;
    cout<<"Enter the total number of processes: ";
    cin>>n;
    process proc[n];

    for(int i = 0; i < n; i++){
        cout<<"Enter the Arrival time, burst time and priority respectively for process "<<(i+1)<<" ";
        cin>>proc[i].at>>proc[i].bt>>proc[i].pr;
        proc[i].pno = i+1;
    }

    findAvgTime(proc, n);
    

return 0;
}
