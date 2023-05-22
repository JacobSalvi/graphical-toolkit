#pragma once

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <vector>

#include "./EventHandlers/EventHandler.hpp"
#include "eventDispatcher.hpp"
#include "Events/Event.hpp"

class Widget{
    private:
    protected:
        Window window;
        Display* display;
        int screen_num;
        unsigned long valueMask;
        XSetWindowAttributes att;
        XSizeHints sizeHints;
        XWMHints wmHints;
        XEvent events;
        XTextProperty windowName, iconName;
        char * window_name = "Window name";
        char * icon_name = "Icone name";
        GC gc;

        std::vector<Widget*> widgets;

        Widget* parent = 0;
        int pos_x, pos_y;
        int width, height;

        EventHandler* eh = 0;


        void set_wm_hints();

        virtual void render_self() {}

        virtual void set_event_handler();


         Widget(int pos_x, int pos_y, int width, int height):
        pos_x(pos_x), pos_y(pos_y), width(width), height(height){
            display = XOpenDisplay("");
            screen_num = DefaultScreen(display);
            att.background_pixel = WhitePixel(display, screen_num);
            att.border_pixel = BlackPixel(display, screen_num);
            att.event_mask = ExposureMask;
            valueMask = CWBackPixel| CWBorderPixel | CWEventMask;
            window = XCreateWindow(display, RootWindow(display, screen_num),
            pos_x, pos_y, width, height, 2,
            DefaultDepth(display, screen_num),
            InputOutput, DefaultVisual(display, screen_num),
            valueMask, &att);
            std::cout<<"app window is"<<window<<std::endl;

            set_wm_hints();
        }

        Widget(Widget* parent, int pos_x, int pos_y, int width, int height):
        parent(parent), pos_x(pos_x), pos_y(pos_y), width(width), height(height){
            display = parent->get_display();
            screen_num = parent->get_screen_num();
            att.background_pixel = WhitePixel(display, screen_num);
            att.border_pixel = BlackPixel(display, screen_num);
            att.event_mask = ExposureMask;
            valueMask = CWBackPixel| CWBorderPixel | CWEventMask;
            window = XCreateWindow(display, parent->get_window(), pos_x, pos_y, width, height, 2,
                DefaultDepth(display, screen_num), InputOutput,
                DefaultVisual(display, screen_num), valueMask, &att);
            std::cout<<"widget window is"<<window<<std::endl;

            set_wm_hints();
            XGCValues gc_values;
            gc_values.background = WhitePixel(display, screen_num);
            gc_values.foreground = BlackPixel(display, screen_num);
            valueMask = GCForeground | GCBackground;
            gc = XCreateGC(display, window, valueMask, &gc_values);
        }

    public:
        void resize(int new_width, int new_height);

        // TODO: something like onload() is needed
        Widget() = delete;

        virtual ~Widget(){
            delete eh;
        }

        static Widget* create(int pos_x, int pos_y, int width, int height);

        static Widget* create(Widget* parent, int pos_x, int pos_y, int width, int height);

        Display* get_display(){
            return display;
        }


        void add_widget(Widget* widget);

        // utility function to convert colours found on stack overflow
        unsigned long _RGB(int r, int g, int b);

        Window get_window(){
            return window;
        }

        EventHandler* get_event_handler(){
            return eh;
        }

        void add_event_listener(EventType et, void (*foo)(Event, Widget*)){
            eh->add_listener(et, foo);
        }

        Widget* get_parent(){
            return parent;
        }

        std::vector<Widget*> get_children(){
            return widgets;
        }


        int get_screen_num(){
            return screen_num;
        }

        void hide(){
            XUnmapWindow(display, window);
        }

        void render();
};
