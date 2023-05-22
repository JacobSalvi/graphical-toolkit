#pragma once
#include <vector>
#include <string>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "eventDispatcher.hpp"
#include "widget.hpp"
#include <iostream>

class Application{
    protected:
        Widget* main_widget = 0;
    private:
    public:
        Application(){
            main_widget = Widget::create(0, 0, 100, 100);
        }

        ~Application(){
            delete main_widget;
        }

        void add_widget(Widget* widget);

        void start();

        Widget* get_main_widget();
};
