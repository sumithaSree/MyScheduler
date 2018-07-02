//
//  Scheduler.cpp
//  applianceRemoteHVAC
//
//  Created by sumitha on 7/1/18.
//  Copyright © 2018 Sumitha. All rights reserved.
//

#include "Scheduler.hpp"

Scheduler::Scheduler()
{
    m_isRunning = false;
                         
}
void Scheduler::run()
{
    m_isRunning = false;
   
}
void Scheduler::start()
{
    if(m_taskVector.empty()) // if task list is  empty
    {
        cout << "No tasks are added in the queue";
        return;
    }
    int index =0;
    for (auto it = m_taskVector.begin(); it < m_taskVector.end();it++)
    {
        auto curTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
        m_taskMap[index * m_gapSec + curTime] = index ; // first loop spawns task with m_gapSec gap
        index++;
    }
    // for the first loop add the current time to get spawn time
    auto it = m_taskMap.begin();
    while(!m_taskMap.empty() && m_isRunning)  //wait for threads to join and then spawn again after the given delay
    {
        index = (*it).second;
        TaskDetails *curTaskDetail = &m_taskVector[index];
        int curDel = (*curTaskDetail).delaySecs;
        Task *curTask = (*curTaskDetail).task;
        // wait until its time to spawn the new task
        auto curTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
        this_thread::sleep_for (std::chrono::seconds((*it).first - curTime));
        // if the thread for this task is currently running wait for it to join back
        if ((*curTaskDetail).taskThread.joinable())
            (*curTaskDetail).taskThread.join();
        // run the task
        (*curTaskDetail).taskThread = thread(&Task::run, curTask);
        // remove this task entry from the map and enter with new spawn time
        auto tmp = it;
        it++;
        m_taskMap.erase(tmp);
        curTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
        m_taskMap[curDel + curTime] = index ;
        
        //check for the conditional signal from a volatile memory location TODO
        
    }
    
    
}
void Scheduler::stop()
{
    m_isRunning = false;
    // if any of the threads are running, wait for them to join back
}
void Scheduler::setTaskInterval(int gapSecs)
{
    m_gapSec = gapSecs;
}

void Scheduler::add(Task* task, const char *name, int periodSecs, int durationSecs)
{
    if (!m_isRunning)
    {
        //create a struct with the input values
        TaskDetails taskStruct = {task, name, periodSecs, durationSecs};
        int nextTime = 0;
        if(periodSecs < durationSecs) // if T > P, wait for gapSec
            nextTime = durationSecs + m_gapSec;
        else //next schedule is after P sec
            nextTime = periodSecs;
        taskStruct.delaySecs = nextTime;
        m_taskVector.push_back(taskStruct);
        int lastIndex = m_taskVector.size() -1;
       
    }
    
}
void Scheduler::remove(Task* task)
{
    if(!m_isRunning)
    for (auto it = m_taskVector.begin(); it < m_taskVector.end();it++)
    {
        if((*it).task == task)
            m_taskVector.erase(it);
    }

}
