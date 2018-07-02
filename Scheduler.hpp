//
//  Scheduler.hpp
//  applianceRemoteHVAC
//
//  Created by sumitha on 7/1/18.
//  Copyright © 2018 Sumitha. All rights reserved.
//

#ifndef Scheduler_hpp
#define Scheduler_hpp

#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>

#include "Task.hpp"
using namespace std;
struct TaskDetails
{
    Task *task;
    const char *name;
    int periodSecs;
    int durationSecs;
    int delaySecs;
    thread taskThread;
};
class Scheduler: public Task
{
    int m_gapSec;
    vector<TaskDetails> m_taskVector;
    map<int,int> m_taskMap; // map with scheduled time in sec and the index of task in vector
    thread* m_thread;
    bool m_isRunning;
public:
    Scheduler();
    void run() ;
    void start();
    void stop();
    void setTaskInterval(int gapSecs);
    void add(Task* task, const char *name, int periodSecs, int durationSecs);
    void remove(Task* task);
    
};

#endif /* Scheduler_hpp */
