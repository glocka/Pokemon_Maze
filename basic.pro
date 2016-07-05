TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    command.cpp \
    command_factory.cpp \
    cmd_load.cpp \
    command_controller.cpp \
    game.cpp \
    cmd_show.cpp \
    cmd_save.cpp \
    cmd_move.cpp \
    cmd_fastmove.cpp \
    invalid_move_exception.cpp \
    invalid_command_exception.cpp \
    vector2.cpp \
    cmd_reset.cpp \
    helper.cpp \
    direction.cpp \
    error.cpp

HEADERS += \
    command_factory.h \
    command.h \
    command_register.h \
    cmd_load.h \
    command_controller.h \
    game.h \
    cmd_show.h \
    cmd_save.h \
    cmd_move.h \
    cmd_fastmove.h \
    invalid_move_exception.h \
    invalid_command_exception.h \
    vector2.h \
    cmd_reset.h \
    helper.h \
    direction.h \
    field.h \
    error.h

