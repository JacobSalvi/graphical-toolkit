#pragma once

#include "widget.hpp"
#include "EventHandlers/BaseEventHandler.hpp"


Widget* Widget::create(int pos_x, int pos_y, int width, int height) {
    Widget* new_wgt = new Widget(pos_x, pos_y, width, height);
    new_wgt->set_event_handler();
    return new_wgt;
}

Widget * Widget::create(Widget* parent, int pos_x, int pos_y, int width, int height)
{
    Widget* new_wgt = new Widget(parent, pos_x, pos_y, width, height);
    new_wgt->set_event_handler();
    return new_wgt;
}


void Widget::set_event_handler()
{
    if(eh !=0 ){
        return;
    }
    eh = new BaseEventHandler(this);
    EventDispatcher::Instance()->add_event_handler(window, eh);
}


void Widget::set_wm_hints(){
    /* give the window manager hints*/
    sizeHints.flags = USPosition |USSize;
    XSetWMNormalHints(display, window, &sizeHints);
    wmHints.initial_state = NormalState;
    wmHints.flags = StateHint;
    XSetWMHints(display, window, &wmHints);
    XStringListToTextProperty(&window_name, 1, &windowName);
    XSetWMName(display, window, &windowName);
    XStringListToTextProperty(&icon_name, 1, &iconName);
    XSetWMIconName(display, window, &iconName);
}


void Widget::resize(int new_width, int new_height){
    width = new_width;
    height = new_height;
    XResizeWindow(display, window, width, height);
}



void Widget::add_widget(Widget* widget){
    // widget->set_event_handler();
    widgets.push_back(widget);
}


void Widget::render(){
    std::cout<<"window is: "<<window<<std::endl;
    XMapWindow(display, window);

    render_self();

    for(auto widget: widgets){
        widget->render();
    }
}
