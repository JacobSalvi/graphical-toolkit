#include "application.hpp"
#include "button.hpp"
#include "label.hpp"
#include "Input/Input.hpp"

class Application;

void test_fn(Event ev, Widget* widget){
    std::cout<<"alpaca"<<std::endl;
    Label* lbl = static_cast<Label*>(widget->get_parent()->get_children()[1]);
    lbl->change_text({"idk"});
}

int main(){
    Application app = Application();
    Button* btn = Button::create(app.get_main_widget());
    btn->add_event_listener(EventType::ButtonDown, *test_fn);
    app.add_widget(btn);

    Label* lbl = Label::create(app.get_main_widget(), {"alpaca"});
    app.add_widget(lbl);

    Input* inpt = Input::create(app.get_main_widget());
    app.add_widget(inpt);

    app.start();
}
