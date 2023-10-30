#include<bits/stdc++.h>

using namespace std;

void findWaitingTime(int n, int wt[], int at[], int bt[]){
    int service[50];
    service[0] = at[0];
    wt[0] = 0;    
    
    for(int i = 1; i < n; i++){
        service[i] = service[i-1] + bt[i-1];
        wt[i] = service[i] - at[i];
        if(wt[i] < 0)wt[i] = 0;
    }
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[]) {
    
    for(int i = 0; i < n; i++){
        tat[i] = bt[i] + wt[i]; 
    }
}

void findAvgTime(int n, int at[], int bt[]){
    int wt[n], tat[n];
    
    findWaitingTime(n, wt, at, bt);

    findTurnAroundTime(n, bt, wt, tat);

    int tavg=0,wavg = 0;

    cout<<"process no."<<" Arrival time "<<" Burst time "<<" Wait time "<<" Turn  Around time "<<endl;
    for(int i = 0; i < n; i++){
        wavg += wt[i];
        tavg += tat[i];
        
        cout<<(i+1)<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
    cout<<"Average Waiting time : "<<((float)wavg/(float)n)<<endl;
    cout<<"Average turn around time : "<<((float)tavg/(float)n);
}

int main(){
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;

    int at[n], bt[n];
    for(int i = 0; i < n; i++){
        cout<<"Enter the Arrival time and Burst time of the process "<<(i+1)<<": ";
        cin>>at[i]>>bt[i];
    }
    findAvgTime(n, at, bt);
return 0;
}