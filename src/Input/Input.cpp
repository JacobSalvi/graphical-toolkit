#include "Input.hpp"
#include "../EventHandlers/InputEventHandler.hpp"

void Input::set_event_handler(){
    eh = new InputEventHandler(this);
    EventDispatcher::Instance()->add_event_handler(window, eh);
}

Input* Input::create(Widget* parent){
    Input* new_input = new Input(parent);
    new_input->set_event_handler();
    return new_input;
}
