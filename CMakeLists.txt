cmake_minimum_required(VERSION 3.26)


project(gt)

add_subdirectory(src/EventHandlers/)
add_subdirectory(src/Events/)

find_package(X11 REQUIRED)

add_executable(gt src/main.cpp
                    src/label.cpp
                    src/widget.cpp
                    src/button.cpp
                    src/eventDispatcher.cpp
                    src/application.cpp
                    src/Input/Input.cpp)

target_link_libraries(gt event_handlers)
target_link_libraries(gt events)
target_link_libraries(gt ${X11_LIBRARIES})
