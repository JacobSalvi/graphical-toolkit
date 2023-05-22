#pragma once
#include "widget.hpp"
#include <iostream>

class Button: public Widget{
    private:
    protected:
        Button(Widget* parent): Widget(parent, 0, 40, 10, 10){
            att.background_pixel = BlackPixel(display, screen_num);
            XSetWindowBackground(display, window, BlackPixel(display, screen_num));
            att.event_mask = att.event_mask | ButtonPressMask;
            XSelectInput(display, window, att.event_mask);
        }
    public:
        static Button* create(Widget* parent);
};
