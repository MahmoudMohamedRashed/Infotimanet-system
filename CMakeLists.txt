cmake_minimum_required(VERSION 3.20)
project(InfoScreen VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Qt auto tools ----
###################################
# Enable automatic Meta-Object Compiler (moc) for Qt's signals/slots and Q_OBJECT macros
set(CMAKE_AUTOMOC ON)
# Enable automatic User Interface Compiler (uic) for .ui files from Qt Designer
set(CMAKE_AUTOUIC ON)
# Enable automatic Resource Compiler (rcc) for .qrc resource files
set(CMAKE_AUTORCC ON)
# include current binary dir so generated headers (e.g. protobuf) are found
set(CMAKE_INCLUDE_CURRENT_DIR ON)


# ---- find Qt ----
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Gui Widgets Quick QuickWidgets Qml)


# ---- Protobuf ----
find_package(Protobuf REQUIRED)

# Include standard installation directory variables (e.g., CMAKE_INSTALL_BINDIR, CMAKE_INSTALL_LIBDIR)
include(GNUInstallDirs)

# ---- find paho libs (adjust PATHS if needed) ----
find_library(PAHO_MQTTPP3 NAMES paho-mqttpp3 PATHS /usr/lib /usr/lib/x86_64-linux-gnu /usr/local/lib)
find_library(PAHO_MQTT3AS  NAMES paho-mqtt3as  PATHS /usr/lib /usr/lib/x86_64-linux-gnu /usr/local/lib)

# ---- protobuf generation if .proto exists ----
set(PROTO_FILE ${CMAKE_SOURCE_DIR}/protobuf/weather.proto)
set(GENERATED_PROTO_SRCS "")
set(GENERATED_PROTO_HDRS "")
if(EXISTS ${PROTO_FILE})
    # generate protobuf file .pb.cc , .pb.h if file existing
    protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILE})
    list(APPEND GENERATED_PROTO_SRCS ${PROTO_SRCS})
    list(APPEND GENERATED_PROTO_HDRS ${PROTO_HDRS})
else()
    message(STATUS "No .proto found at ${PROTO_FILE} — using pre-generated protobuf/weather.pb.cc if present")
endif()

# ---- sources / headers / ui / resources / qml ----
set(SOURCES
    Controller/cabintempcontrol.cpp
    Controller/doorlockcontrol.cpp
    Controller/fancontrol.cpp
    Controller/gaugecontrol.cpp
    Controller/lightcontrol.cpp
    Controller/motortempcontrol.cpp
    Controller/seatbeltcontrol.cpp
    Controller/signallightcontrol.cpp
    Controller/tripinfocontrol.cpp
    Controller/warningcontrol.cpp
    Model/model.cpp
    main.cpp
    mainwindow.cpp
    protobuf/tempupdate.cpp
)

if(GENERATED_PROTO_SRCS)
    list(APPEND SOURCES ${GENERATED_PROTO_SRCS})
else()
    list(APPEND SOURCES protobuf/weather.pb.cc) # fallback if pre-generated exists
endif()

set(HEADERS
    Controller/cabintempcontrol.h
    Controller/doorlockcontrol.h
    Controller/fancontrol.h
    Controller/gaugecontrol.h
    Controller/lightcontrol.h
    Controller/motortempcontrol.h
    Controller/seatbeltcontrol.h
    Controller/signallightcontrol.h
    Controller/tripinfocontrol.h
    Controller/warningcontrol.h
    Model/model.h
    includeFils.h
    mainwindow.h
)

if(GENERATED_PROTO_HDRS)
    list(APPEND HEADERS ${GENERATED_PROTO_HDRS})
else()
    list(APPEND HEADERS protobuf/weather.pb.h) # fallback
endif()

set(UI_FILES
    mainwindow.ui
)

set(RESOURCES
    Image.qrc
    resource.qrc
)

set(QML_FILES
    FuelGauge.qml
    RpmGauge.qml
    SpeedGauge.qml
)

# ---- executable ----
qt_add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
    ${RESOURCES}
)


##################################
# Avoid name conflict between QML module dir and the executable name:
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)



# ---- bundle QML into app (Qt6) ----
if(Qt6_FOUND)
    qt_add_qml_module(${PROJECT_NAME}
        URI InfoScreen
        VERSION 1.0
        QML_FILES
            ${QML_FILES}
    )
endif()

# ---- includes (add build dir so generated headers are visible) ----
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/
        ${CMAKE_CURRENT_BINARY_DIR}     # << important: generated headers (proto) will be here
        ${Protobuf_INCLUDE_DIRS}
        /usr/local/include
        /usr/include
)

# ---- link libraries ----
if(TARGET protobuf::libprotobuf)
    set(PROTOBUF_LINK_TARGET protobuf::libprotobuf)
else()
    set(PROTOBUF_LINK_TARGET ${Protobuf_LIBRARIES})
endif()

set(EXTRA_LIBS ${PROTOBUF_LINK_TARGET})
if(PAHO_MQTTPP3)
    list(APPEND EXTRA_LIBS ${PAHO_MQTTPP3})
else()
    message(WARNING "paho-mqttpp3 not found via find_library(). You may need to install it or adjust PATHS.")
endif()
if(PAHO_MQTT3AS)
    list(APPEND EXTRA_LIBS ${PAHO_MQTT3AS})
else()
    message(WARNING "paho-mqtt3as not found via find_library(). You may need to install it or adjust PATHS.")
endif()

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Quick
        Qt6::QuickWidgets
        Qt6::Qml
        ${EXTRA_LIBS}
)

# ---- rpath ----
set_target_properties(${PROJECT_NAME} PROPERTIES
    INSTALL_RPATH "/usr/local/lib"
    BUILD_WITH_INSTALL_RPATH ON
)

# ---- install ----
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

