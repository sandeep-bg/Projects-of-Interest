//
//  Track.hpp
//  T2S
//
//  Created by SANDEEP GANGADHARAIAH on 19/03/20.
//  Copyright © 2020 SANDEEP GANGADHARAIAH. All rights reserved.
//

#ifndef Track_hpp
#define Track_hpp

#include <stdio.h>
#include "TrackSegment.hpp"
//#include "Station.hpp"

class Track
{
    TrackSegment* startSegment;
    TrackSegment* endSegment;
    TrackStatus status;
//    Station startStn;
//    Station endStn;
    
public:
    TrackStatus isTrackEmpty();
    
};
#endif /* Track_hpp */
