#include <string.h>

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

void Input::add_char(char c){
    content += c;
    XClearWindow(display, window);
    delete text_item;
    text_item = new XTextItem();
    text_item->chars = (char *) malloc(sizeof(char)*content.size());
    text_item->chars = strcpy(text_item->chars, content.c_str());
    text_item->nchars = content.size();

    XDrawText(display, window, gc, 0, 10, text_item, 1);
}