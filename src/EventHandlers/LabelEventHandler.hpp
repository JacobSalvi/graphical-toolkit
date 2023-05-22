#pragma once

#include "EventHandler.hpp"
#include "../label.hpp"

class LabelEventHandler: public EventHandler{
    private:
        std::map<EventType, void(*)(Event, Widget*)> type_to_listener {};
        Label* lbl = 0;
    public:
        LabelEventHandler(Label* lbl);
        void add_listener(EventType et, void (*foo)(Event, Widget*)) override;

        void call(EventType et, Event& event) override;

};
