#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

class EventLess {
public:
    bool operator()(const Event* lhs, const Event* rhs) const {
        if (lhs->time > rhs->time){
            return false;
        }else{
            return true;
        }
    }
};
	
#endif
