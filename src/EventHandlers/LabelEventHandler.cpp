#include "LabelEventHandler.hpp"
#include <iostream>


LabelEventHandler::LabelEventHandler(Label* lbl): EventHandler(lbl), lbl(lbl)
{
}

void LabelEventHandler::add_listener(EventType et, void (*foo)(Event, Widget*)){
    type_to_listener[et] = foo;
}


void LabelEventHandler::call(EventType et, Event& event){
    if(et == EventType::Exposed){
        lbl->show_text();
    }

    if(type_to_listener.find(et) == type_to_listener.end()){
        return;
    }
    type_to_listener.at(et)(event, lbl);
}
