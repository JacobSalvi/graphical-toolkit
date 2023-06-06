#pragma once

#include <X11/X.h>
#include <string>

#include "../widget.hpp"

//NOTE: should we just extend Label instead?
class Input: public Widget{
    private:
        std::string content = "";

        // TODO: create classes for fonts and text.
        // TODO: classic X11 fonts kinda suck, look into fontconfig, freebidy, freetype, harfbuzz-ng
        XTextItem* text_item = 0;
        XFontStruct* font = 0;
    protected:
        void set_event_handler() override;

        Input(Widget* parent): Widget(parent, 0, 30, 40, 40){
            att.event_mask = att.event_mask | KeyPressMask;
            XSelectInput(display, window, att.event_mask);
            this->text_item = new XTextItem();
            font = XLoadQueryFont(display, "-misc-dejavu serif-medium-i-normal--0-0-0-0-p-0-iso8859-1");
            text_item->font = font->fid;
            set_event_handler();
        }

    public:
        void add_char(char c);

        static Input* create(Widget* parent);
};
