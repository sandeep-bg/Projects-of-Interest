//
//  TrackSegment.hpp
//  Train Signalling System
//
//  Created by SANDEEP GANGADHARAIAH on 18/03/20.
//

#ifndef TrackSegment_hpp
#define TrackSegment_hpp

#include <stdio.h>

enum SignalStatus
{
    Stop = 1,
    Caution,
    Proceed
};

enum TrackStatus
{
    Occupied = 1,
    empty
};

class Signal
{
    SignalStatus forwardSignal;
    SignalStatus reverseSignal;
    
public:
    bool SetSignal(SignalStatus status);
    SignalStatus ReadFSignal();
    SignalStatus ReadRSignal();
};

class TrackSegment
{
    int id;
    Signal track_signal;
    TrackStatus track_status; //Train circuit: detect if train is present on track
    TrackSegment* next_track;
    TrackSegment* prev_track;
    
public:
    bool ConnectTrack(TrackSegment next, TrackSegment prev);
    bool isTrackOccupied();
    int getTrackSegmentid();
};

#endif /* TrackSegment_hpp */


