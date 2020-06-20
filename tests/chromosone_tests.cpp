#include <gtest/gtest.h>
#include "include/chromosone.h"


TEST(ChromosoneTests, getBoard){
    std::vector<int> v{2,3,1};
    Board b{v};
    chromosone c{b};
    EXPECT_EQ(b, c.get_board());
}

