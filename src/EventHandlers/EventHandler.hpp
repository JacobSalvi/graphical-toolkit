#pragma once

#include <map>

#include "../Events/Event.hpp"

enum class EventType{
    ButtonDown,
    ButtonUp,
    KeyDown,
    KeyUp,
    MouseEnter,
    MouseLeave,
    Exposed,
};

class Widget;

class EventHandler{
    public:
        EventHandler() = delete;

        EventHandler(Widget* widget);

        virtual void add_listener(EventType et, void (*foo)(Event, Widget*)) = 0;

        virtual void call(EventType et, Event& event) = 0;

        virtual ~EventHandler() {};
};
