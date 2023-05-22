#pragma once

#include <X11/X.h>
#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <map>

#include "EventHandlers/EventHandler.hpp"
#include "Events/Event.hpp"
#include "Events/ButtonDownEvent.hpp"
#include "Events/KeyDownEvent.hpp"


class EventDispatcher{
    private:
        Display* display = 0;
        XEvent events;
        static EventDispatcher* ed;
        std::map<Window, EventHandler*> window_to_event_handler {};
    protected:
        EventDispatcher() {}
    public:

        void set_display(Display* disp){
            EventDispatcher::ed->display = disp;
        }

        static EventDispatcher* Instance();

        void add_event_handler(Window win, EventHandler* et){
            window_to_event_handler[win] = et;
        }

        void listen(){
            XNextEvent(display, &events);
            std::cout<<events.type<<std::endl;
            Window w = events.xclient.window;
            if(window_to_event_handler.find(w) == window_to_event_handler.end()){
                        return;
            }
            Event ev;
            switch (events.type){
                case Expose:
                    std::cout<<"Exposure"<<std::endl;
                    window_to_event_handler.at(w)->call(EventType::Exposed, ev);
                    break;
                case ButtonPress:
                    ev = ButtonDownEvent(events.xbutton.x, events.xbutton.y);
                    window_to_event_handler.at(w)->call(EventType::ButtonDown, ev);
                    break;
                case KeyPress:
                    std::cout<<"Keypress"<<std::endl;
                    // const int BUFFER_LENGTH = 8;
                    // char buffer[BUFFER_LENGTH];
                    // KeySym sym;
                    // int x = XLookupString(&events.xkey, buffer, BUFFER_LENGTH, &sym, NULL);
                    // std::cout<<"dispatcher: "<<buffer<<std::endl;
                    XKeyEvent xkey = events.xkey;
                    KeyDownEvent ev = KeyDownEvent(&xkey);
                    window_to_event_handler.at(w)->call(EventType::KeyDown, ev);
                    break;
                
            }
        }
};
