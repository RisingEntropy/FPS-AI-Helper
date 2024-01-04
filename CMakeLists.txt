cmake_minimum_required(VERSION 3.26)

project(CFAIHelper C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
#file(GLOB CFAIHELPER_EXECUTABLES "*.c" "*.cpp" "*.h" "AIBackend/*.h" "AIBackend/*.cpp" "AIBackend/*.c" "UI/*.c" "UI/*.cpp" "UI/*.h")
set(CFAIHELPER_EXECUTABLES main.cpp AIBackend/YoloEngine.cpp AIBackend/YoloEngine.h
        Control/ActionExecutor.h Control/FrameSource.h Control/ActionDecider.h
        Control/ControlModel.h Control/ControlModel.cpp Control/SoftwareSimulateExecutor.cpp Control/SoftwareSimulateExecutor.h
        UI/FPSHelperWindow.cpp UI/FPSHelperWindow.h
        Control/OBSFrameSource.h
        Control/OBSFrameSource.cpp

        Control/RifleDecider.cpp
        Control/RifleDecider.h
        Control/ActionDecider.cpp
        Control/ActionExecutor.cpp
        Control/FrameSource.cpp
        Control/FileFrameSource.cpp
        Control/FileFrameSource.h)
add_executable(${PROJECT_NAME} ${CFAIHELPER_EXECUTABLES})
include(${CMAKE_CURRENT_LIST_DIR}/UI/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/AIBackend/CMakeLists.txt)


set(CFAIHELPER_VERSION 0)
configure_file(BuildConfig.h.in BuildConfig.h)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})