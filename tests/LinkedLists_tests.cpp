#include <gtest/gtest.h>
#include "dll.h"

TEST(DLLTest, InsertAtTailWorks) {
    DynamicLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 20);
    EXPECT_EQ(list.get(2), 30);
}

TEST(DLLTest, InsertAtIndexWorks) {
    DynamicLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert_at_index(1, 15);

    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 15);
    EXPECT_EQ(list.get(2), 20);
}