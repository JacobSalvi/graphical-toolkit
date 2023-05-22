#pragma once

#include "Event.hpp"


class ButtonDownEvent: public Event{
    private:
        const int x;
        const int y;
    public:
        ButtonDownEvent(const int x, const int y): x(x), y(y){}
};
