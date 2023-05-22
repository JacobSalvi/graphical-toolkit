#pragma once

#include "EventHandler.hpp"

class BaseEventHandler: public EventHandler
{
    private:
        std::map<EventType, void(*)(Event, Widget*)> type_to_listener {};
        Widget* widget = 0;
    public:
        BaseEventHandler(Widget* widget);

        void add_listener(EventType et, void (*foo)(Event, Widget*)) override;

        void call(EventType et, Event& event) override;

        ~BaseEventHandler() {}
};

