#include "button.hpp"

Button* Button::create(Widget* parent)
{
    Button* new_btn = new Button(parent);
    new_btn->set_event_handler();
    return new_btn;
}
