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