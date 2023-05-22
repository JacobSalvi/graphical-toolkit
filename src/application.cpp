#include "application.hpp"


void Application::add_widget(Widget* widget){
    main_widget->add_widget(widget);
}

void Application::start(){
    main_widget->render();
    EventDispatcher* ed = EventDispatcher::Instance();
    ed->set_display(main_widget->get_display());
    while(true) {
        ed->listen();
    }
}

Widget* Application::get_main_widget(){
    return main_widget;
}
