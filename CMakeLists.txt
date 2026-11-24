cmake_minimum_required(VERSION 3.16)
project(Lab9Refactoring LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(lab9
    Book.cpp
    InMemoryBookRepository.cpp
    ConsoleNotificationService.cpp
    Library.cpp
    Rational.cpp
    FractionApproximator.cpp
)

add_executable(lab9_demo main.cpp)
target_link_libraries(lab9_demo PRIVATE lab9)

add_executable(lab9_tests tests.cpp)
target_link_libraries(lab9_tests PRIVATE lab9)

enable_testing()
add_test(NAME lab9_tests COMMAND lab9_tests)
