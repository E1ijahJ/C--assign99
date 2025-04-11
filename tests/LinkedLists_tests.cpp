#include <gtest/gtest.h>
#include "dll.h"

TEST(DLLTest, InsertAtTailWorks) {
    DLL list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 20);
    EXPECT_EQ(list.get(2), 30);
}