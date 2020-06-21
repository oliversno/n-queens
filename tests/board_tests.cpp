#include<vector>

#include <gtest/gtest.h>
#include "include/board.h"

TEST(BoardTests, InitRandom){
    Board b(3);
    SUCCEED();
}

TEST(BoardTests, InitNegative){
    EXPECT_ANY_THROW(Board b(-1));
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

TEST(BoardTest, at){
    std::vector<int> v{2,3,4,1};
    Board b(v);
    EXPECT_EQ(b.at(2), 4);
}

TEST(BoardTest, at_negative){
    std::vector<int> v{2,3,4,1};
    Board b(v);
    EXPECT_ANY_THROW(b.at(-2));
}

TEST(BoardTest, at_too_great){
    std::vector<int> v{2,3,4,1};
    Board b(v);
    EXPECT_ANY_THROW(b.at(10));
}

TEST(BoardTest, swap){
    std::vector<int> v{1,2};
    Board b{v};
    EXPECT_EQ(1, b.at(0));
    b.swap(0,1);
    EXPECT_EQ(2, b.at(0));
}

TEST(BoardTest, swap_out_of_range){
    std::vector<int> v{1,3,2};
    Board b{v};
    EXPECT_ANY_THROW(b.swap(-2,7));
}

TEST(BoardTest, swapOtherBoard){
    std::vector<int> v1{1,2};
    Board b1{v1};
    std::vector<int> v2{2,1};
    Board b2{v2};
    b1.swap(b2, 0);
    EXPECT_EQ(2, b1.at(0));
    EXPECT_EQ(2, b1.at(1));
    EXPECT_EQ(1, b2.at(0));
    EXPECT_EQ(1, b2.at(1));
}