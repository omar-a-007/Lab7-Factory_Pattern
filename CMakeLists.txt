CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(calculator
    src/main.cpp
    src/factory_calculator.cpp
)

#ADD_EXECUTABLE(test
#    tests/unit_test.cpp
#    src/facttory_calculator.cpp
#)

#TARGET_LINK_LIBRARIES(test gtest)
#TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
