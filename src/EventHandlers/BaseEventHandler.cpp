#include "BaseEventHandler.hpp"


BaseEventHandler::BaseEventHandler(Widget* widget): EventHandler(widget), widget(widget) {};


void BaseEventHandler::add_listener(EventType et, void (*foo)(Event, Widget*)){
    type_to_listener[et] = foo;
}


void BaseEventHandler::call(EventType et, Event& event){
    if(type_to_listener.find(et) == type_to_listener.end()){
        return;
    }
    type_to_listener.at(et)(event, widget);
}
