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

TEST(DLLTest, DeleteAtIndexWorks) {
    DynamicLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    EXPECT_TRUE(list.delete_at_index(1)); // removes 20
    EXPECT_FALSE(list.delete_at_index(5)); // out of bounds

    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 30);
}
TEST(DLLTest, UpdateElementWorks) {
    DynamicLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    EXPECT_TRUE(list.update_element(20, 25)); // Should update
    EXPECT_EQ(list.get(1), 25);

    EXPECT_FALSE(list.update_element(100, 200)); // Non-existent value
}
TEST(DLLTest, UpdateElementAtIndexWorks) {
    DynamicLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    EXPECT_TRUE(list.update_element_at_index(1, 99));
    EXPECT_EQ(list.get(1), 99);

    EXPECT_FALSE(list.update_element_at_index(5, 42)); // Out of bounds
}
TEST(DLLTest, FindElementWorks) {
    DynamicLinkedList list;
    list.insert(5);
    list.insert(15);
    list.insert(25);

    EXPECT_TRUE(list.find(15));
    EXPECT_FALSE(list.find(100));
}