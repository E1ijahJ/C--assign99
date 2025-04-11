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
TEST(DLLTest, DeleteElementWorks) {
    DynamicLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    EXPECT_TRUE(list.delete_element(2));
    EXPECT_FALSE(list.delete_element(4)); // not in list

    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(1), 3);
}