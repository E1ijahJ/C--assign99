add_executable(LinkedList_tests LinkedLists_tests.cpp)

target_link_libraries(LinkedList_tests
    gtest
    gtest_main
    dll
    sll   
)

gtest_discover_tests(LinkedList_tests)