//
//  Junction.hpp
//  T2S
//
//  Created by SANDEEP GANGADHARAIAH on 19/03/20.
//  Copyright © 2020 SANDEEP GANGADHARAIAH. All rights reserved.
//

#ifndef Junction_hpp
#define Junction_hpp

#include <stdio.h>
#include "TrackSegment.hpp"

enum TurnOutPos
{
    Forward = 1,
    Reverse
};

class Junction
{
    int id;
    TurnOutPos junction_status; //Junction switch position, forward or reverse
    TrackSegment* fwd_track;
    TrackSegment* rev_track;
    TrackSegment* curr_track;
    
public:
    bool ConnectForward();
    bool ConnectReverse();
};

#endif /* Junction_hpp */
