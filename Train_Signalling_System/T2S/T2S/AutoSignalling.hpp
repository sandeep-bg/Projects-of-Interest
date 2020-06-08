//
//  AutoSignalling.hpp
//  T2S
//
//  Created by SANDEEP GANGADHARAIAH on 19/03/20.
//  Copyright © 2020 SANDEEP GANGADHARAIAH. All rights reserved.
//

#ifndef AutoSignalling_hpp
#define AutoSignalling_hpp

#include <stdio.h>

class SignalControl
{
public:
    void SignalProcessTask();
    bool SetStopSignal();
    bool SetProceedSignal();
    bool SetCautionSignal();
    
};

#endif /* AutoSignalling_hpp */
