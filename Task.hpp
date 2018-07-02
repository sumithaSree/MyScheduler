//
//  Task.hpp
//  applianceRemoteHVAC
//
//  Created by Sumitha on 7/1/18.
//  Copyright © 2018 Sumitha. All rights reserved.
//

#ifndef Task_hpp
#define Task_hpp

#include <stdio.h>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
class Task
{
    int m_durationSec;
public:
    virtual void run();
    virtual void start();
    virtual void stop();
    virtual void init(int dur);
    
};

#endif /* Task_hpp */
