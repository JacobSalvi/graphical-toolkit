#include "KeyDownEvent.hpp"
#include <X11/Xutil.h>
#include <iostream>

KeyDownEvent::KeyDownEvent(XKeyEvent* key_event): key_event(key_event){}

char KeyDownEvent::get_char(){
    // NOTE: I am like 200% sure this is not efficent
    const int BUFFER_LENGTH = 8;
    char buffer[BUFFER_LENGTH];
    int x = XLookupString(key_event, buffer, BUFFER_LENGTH, &sym, NULL);
    return buffer[0];
}