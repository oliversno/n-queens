#include<vector>

#include <gtest/gtest.h>
#include "include/board.h"

TEST(BoardTests, InitRandom){
    Board b(3);
    SUCCEED();
}

TEST(BoardTests, InitFromVector){
    std::vector<int> v{1,2,3};
    Board b(v);
    SUCCEED();
}

TEST(BoardTest, get_n_one){
    Board b(5);
    EXPECT_EQ(b.get_n(), 5);
}

TEST(BoardTest, get_n_two){
    std::vector<int> v{4,5,6,7};
    Board b(v);
    EXPECT_EQ(b.get_n(), 4);
}