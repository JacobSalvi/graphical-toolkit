#pragma once
#include "eventDispatcher.hpp"

EventDispatcher* EventDispatcher::ed = 0;

EventDispatcher* EventDispatcher::Instance(){
    if(ed == 0){
        ed = new EventDispatcher();
    }
    return ed;
}
