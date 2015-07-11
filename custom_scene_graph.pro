# QT Modules
QT += qml quick

# Target
TARGET = custom_scene_graph
TEMPLATE = app

# Extra Configs
CONFIG(release, debug|release) {
    DEFINES += QT_NO_DEBUG_OUTPUT
}

# Source Files
INCLUDEPATH += src
HEADERS += \
    src/ring.h

SOURCES += \
    src/main.cpp \
    src/ring.cpp

# Qml Files
OTHER_FILES += qml/main.qml

# Resources
RESOURCES += custom_scene_graph.qrc
QMAKE_RESOURCE_FLAGS += -no-compress

# Objects Pathes
DESTDIR = bin
UI_DIR = build
MOC_DIR = build
RCC_DIR = build
OBJECTS_DIR = build
