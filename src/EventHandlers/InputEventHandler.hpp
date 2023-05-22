#pragma once
#include "EventHandler.hpp"
#include "../Input/Input.hpp"

class InputEventHandler: public EventHandler{
    private:
        std::map<EventType, void(*)(Event, Widget*)> type_to_listener {};
        Input* input = 0;
    public:

        InputEventHandler(Input* input);

        void add_listener(EventType et, void (*foo)(Event, Widget*)) override;

        void call(EventType et, Event& event) override;
};
