set(event_handlers_files
    EventHandler.cpp
    EventHandler.hpp
    BaseEventHandler.cpp
    BaseEventHandler.hpp
    LabelEventHandler.hpp
    LabelEventHandler.cpp
    InputEventHandler.hpp
    InputEventHandler.cpp
)
add_library(event_handlers ${event_handlers_files})
