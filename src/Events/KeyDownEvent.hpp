#pragma once

#include "Event.hpp"
#include <X11/X.h>
#include <X11/Xlib.h>

class KeyDownEvent: public Event{
    private:
        KeySym sym;
        XKeyEvent* key_event;
    public:
        KeyDownEvent(XKeyEvent* key_event);
        char get_char();
};