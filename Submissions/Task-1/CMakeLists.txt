cmake_minimum_required(VERSION 4.3)
project(TemplatesAndCallbacks)

set(CMAKE_CXX_STANDARD 20)

add_executable(TemplatesAndCallbacks main.cpp
        BasicTemplate.h
        AdvancedTemplates.h
        CallbacksAndTemplates.h
        TemplateClassAndContextPointers.h)
