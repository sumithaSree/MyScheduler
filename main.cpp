//
//  main.cpp
//  applianceRemoteHVAC
//
//  Created by Pranav Sreejayan on 7/1/18.
//  Copyright © 2018 Sumitha. All rights reserved.
//

#include <iostream>
#include "Task.hpp"
#include "Scheduler.hpp"

int main(int argc, const char * argv[]) {
    
    std::cout << "Appliance !!!\n";
    Scheduler* sched = new Scheduler();
    sched->add(new Task(), "BACNet Collector", 300, 10);

    sched->add(new Task(), "LONWorks Collector", 400, 15);
    sched->start();
    // conditional signal
    sched->stop();
    return 0;
}
