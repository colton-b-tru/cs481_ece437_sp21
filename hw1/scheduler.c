#include <stdio.h>
#include <stdlib.h>
#include "jobs.h"
#include "scheduler.h"
//Note that in each test, the method is only called once.
//I don't think you have to worry about the array mutating from
//the outside.
// Priority Scheduling -- Jobs with highest priority (lowest number) run first
//   -- If two jobs with same priority, lower index runs first
void priority(int n_jobs, Job* jobs)
{
    qsort(jobs, n_jobs, sizeof(Job), jobcmp);
    while(n_jobs > 0){
        jobs->run_job(jobs->time);
        for(int i = 1; i < n_jobs ;i++){
            jobs[i-1] = jobs[i]; 
        }
        n_jobs--;
        
    }
}

// Priority Scheduling with Round Robin -- Jobs with highest priority (lowest number)
//    run first
//    -- If two jobs have same priority, run both in round robin 
//    -- Time slice for round robin passed as a parameter

void priority_rr(int n_jobs, Job* jobs, int time_slice)
{
    qsort(jobs, n_jobs, sizeof(Job), jobcmp);
    while(n_jobs > 0){
        int highestPriority = jobs[0].priority;
        int highestIndex = 0;
        for (int i = 0; i < n_jobs; i++){
            if ((jobs[i].priority) == highestPriority) highestIndex = i;
        }
        int numPriorityJobs = highestIndex + 1;
            for(int i = 0; numPriorityJobs != 0; i++){
                int realIndex = i % numPriorityJobs;
                if (jobs[realIndex].time < time_slice){
                    jobs[realIndex].run_job(jobs[realIndex].time);
                }
                else jobs[realIndex].run_job(time_slice);
                jobs[realIndex].time-=time_slice;
                if (jobs[realIndex].time <= 0) {
                    //remove finished job by shoving everything left and reducing counts
                    for(int j = realIndex; j < (n_jobs-1); j++){
                        jobs[j] = jobs[j+1];
                    }
                    n_jobs--;
                    numPriorityJobs--;
                }
            }
        
}
}


