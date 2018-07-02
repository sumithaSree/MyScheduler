//
//  Task.cpp
//  applianceRemoteHVAC
//
//  Created by Sumitha on 7/1/18.
//  Copyright © 2018 Sumitha. All rights reserved.
//

#include "Task.hpp"

void Task::run()
{
    auto timeNow = std::chrono::system_clock::now();
    std::cout << "Task started now";
    this_thread::sleep_for (std::chrono::seconds(m_durationSec));
    
}
void Task::start()
{
    
}
void Task::stop()
{
    
}

void Task::init(int dur)
{
    m_durationSec = dur;
}
