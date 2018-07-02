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
class Task
{
public:
    virtual int run() = 0;
    virtual int start() = 0;
    virtual int stop() = 0;
    
};

#endif /* Task_hpp */
