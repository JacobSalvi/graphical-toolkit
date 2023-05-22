#include "label.hpp"
#include "EventHandlers/LabelEventHandler.hpp"


Label* Label::create(Widget* parent, std::string label_text){
    Label* new_lbl = new Label(parent, label_text);
    new_lbl->set_event_handler();
    return new_lbl;
}


void Label::set_event_handler(){
    std::cout<<"lbl constructor"<<std::endl;
    if(eh !=0 ){
        return;
    }
    eh = new LabelEventHandler(this);
    EventDispatcher::Instance()->add_event_handler(window, eh);
}


void Label::change_text(std::string new_text){
    XClearWindow(display, window);
    delete text_item;
    text_item = new XTextItem();
    text_item->chars = (char *) malloc(sizeof(char)*new_text.size());
    text_item->chars = strcpy(text_item->chars, new_text.c_str());
    text_item->nchars = new_text.size();

    int text_width = XTextWidth(font, text_item->chars, new_text.size());
    int text_height = font->ascent + font->descent;

    const int padding_x = 5;
    const int padding_y = 2;
    resize(text_width+padding_x, text_height+padding_y);
    XDrawText(display, window, gc, 0, 10, text_item, 1);
}
