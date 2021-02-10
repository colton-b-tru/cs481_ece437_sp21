#include <stdio.h>
#include <stdlib.h>
#include "jobs.h"
#include "scheduler.h"

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
}


