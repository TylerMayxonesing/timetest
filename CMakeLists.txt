cmake_minimum_required(VERSION 3.14)
project(timetest)

set(CMAKE_CXX_STANDARD 14)

add_executable(timetest timetest.cpp CPUTimer.h
        CursorList.cpp CursorList.h
        dsexceptions.h
        filecreate.cpp
        LinkedList.cpp LinkedList.h
        QueueAr.cpp QueueAr.h
        QueueLL.cpp QueueLL.h
        SkipList.cpp SkipList.h
        StackAr.cpp StackAr.h
        StackLi.cpp StackLi.h
        vector.cpp vector.h)