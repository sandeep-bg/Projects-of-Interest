//
//  Station.hpp
//  T2S
//
//  Created by SANDEEP GANGADHARAIAH on 19/03/20.
//  Copyright © 2020 SANDEEP GANGADHARAIAH. All rights reserved.
//

#ifndef Station_hpp
#define Station_hpp

#include <stdio.h>
#include "TrackSegment.hpp"
#include "Track.hpp"

class Station
{
    Track* OutBoundTrack;
    Track* InBoundTracks;
    Track Platforms[];
    
public:
    void StationMasterTask();
    bool ConnectDestination(Station destStn); //Calculate route and allot to the train
    bool AllotPlatform(Track srcTrack, Station destStn); //Allot an empty platform or route for trains
};
#endif /* Station_hpp */
