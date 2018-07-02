//
//  Scheduler.cpp
//  applianceRemoteHVAC
//
//  Created by sumitha on 7/1/18.
//  Copyright © 2018 Sumitha. All rights reserved.
//

#include "Scheduler.hpp"

int Scheduler::run()
{
    return 0;
}
int Scheduler::start()
{
    return 0;
}
int Scheduler::stop()
{
    return 0;
}
void Scheduler::setTaskInterval(int gapSecs)
{
    m_gapSec = gapSecs;
}

void Scheduler::add(Task* task, const char *name, int periodSecs, int durationSecs)
{
    //create a struct with the input values
    TaskDetails taskStruct = {task, name, periodSecs, durationSecs};
    auto delaySec = m_gapSec;
    int nextTime = 0;
    //nextTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    if(!m_taskMap.empty()) // if this is not the first entry
    {
        auto lastTime = m_taskMap.rbegin()->first; // last scheduled time
        if(periodSecs < durationSecs) // if T > P, wait for gapSec
            nextTime = lastTime + durationSecs + m_gapSec;
        else //next schedule is after P sec
            nextTime = lastTime + periodSecs;
    }
    taskStruct.delaySecs = nextTime;
    m_taskVector.push_back(taskStruct);
    
}
void Scheduler::remove(Task* task)
{
    
}
