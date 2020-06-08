//
//  T2SElements.hpp
//  T2S
//
//  Created by SANDEEP GANGADHARAIAH on 19/03/20.
//  Copyright © 2020 SANDEEP GANGADHARAIAH. All rights reserved.
//

#ifndef T2SElements_hpp
#define T2SElements_hpp

#include <stdio.h>
#include "TrackSegment.hpp"

class T2SElements
{
public:
    bool AddTrackSegment(TrackSegment); //Add new Track segments into the DB
    bool AddJunction(TrackSegment); //Add new Junctions to the DB
    
    
};
#endif /* T2SElements_hpp */
