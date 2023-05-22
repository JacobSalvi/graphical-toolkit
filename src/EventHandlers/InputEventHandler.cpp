#include "InputEventHandler.hpp"
#include "EventHandler.hpp"

InputEventHandler::InputEventHandler(Input* input): EventHandler(input), input(input) {};


void InputEventHandler::add_listener(EventType et, void (*foo)(Event, Widget*)){
    type_to_listener[et] = foo;
}


void InputEventHandler::call(EventType et, Event& event){
    if(et == EventType::KeyDown){
        std::cout<<"inside call: "<<static_cast<KeyDownEvent&>(event).get_char()<<std::endl;
    }
    if(type_to_listener.find(et) == type_to_listener.end()){
        return;
    }
    type_to_listener.at(et)(event, input);
}
