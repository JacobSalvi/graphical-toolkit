#pragma once

#include <string>
#include <string.h>
#include <iostream>
#include "widget.hpp"


class Label: public Widget{
    private:
        // TODO: create classes for fonts and text.
        // TODO: classic X11 fonts kinda suck, look into fontconfig, freebidy, freetype, harfbuzz-ng
        XTextItem* text_item = 0;
        XFontStruct* font = 0;

    protected:
        void set_event_handler() override;

        Label(Widget* parent, std::string label_text): Widget(parent, 0, 0, 10, 10){
            this->text_item = new XTextItem();
            text_item->chars = (char *) malloc(sizeof(char)*label_text.size());
            text_item->chars = strcpy(text_item->chars, label_text.c_str());
            text_item->nchars = label_text.size();
            font = XLoadQueryFont(display, "-misc-dejavu serif-medium-i-normal--0-0-0-0-p-0-iso8859-1");

            int text_width = XTextWidth(font, text_item->chars, label_text.size());
            int text_height = font->ascent + font->descent;

            const int padding_x = 5;
            const int padding_y = 2;
            resize(text_width+padding_x, text_height+padding_y);

            text_item->font = font->fid;
            set_event_handler();
        }

    public:

        static Label* create(Widget* parent, std::string label_text);

        void show_text(){
            XDrawText(display, window, gc, 0, 10, text_item, 1);
        }

        void change_text(std::string new_text);


        ~Label(){
            delete text_item;
            delete font;
        }

};
