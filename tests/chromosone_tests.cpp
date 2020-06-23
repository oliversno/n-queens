#include <gtest/gtest.h>
#include "include/chromosone.h"

TEST(ChromosoneTests, ctor){
    std::vector<int> v{2,3,1};
    Board b{v};
    chromosone c{b};
    SUCCEED();
}

TEST(ChromosoneTests, calculateFitness_noConflict){
    std::vector<int> v{1, 3, 5, 7, 2, 0, 6, 4};
    Board b{v};
    chromosone c{b};
    EXPECT_EQ(c.get_board().get_n(), 8);
    EXPECT_EQ(c.calculateFitness(), 28); //8C2
}

TEST(ChromosoneTests, calculateFitness_someConflict){
    std::vector<int> v{0, 2, 1, 3};
    Board b{v};
    chromosone c{b};
    EXPECT_EQ(c.get_board().get_n(), 4);
    EXPECT_EQ(c.calculateFitness(), 4); //4C2 - 2
}

TEST(ChromosoneTests, calculateFitness_allConflict){
    std::vector<int> v{1, 1, 1};
    Board b{v};
    chromosone c{b};
    EXPECT_EQ(c.get_board().get_n(), 3);
    EXPECT_EQ(c.calculateFitness(), 0);
}

TEST(ChromosoneTests, calculateFitness_noConflict){
    std::vector<int> v{1, 3, 5, 7, 2, 0, 6, 4};
    Board b{v};
    chromosone c{b};
    EXPECT_EQ(c.get_board().get_n(), 8);
    EXPECT_EQ(c.calculateFitness(), 28); //8C2
}

TEST(ChromosoneTests, getBoard){
    std::vector<int> v{2,3,1};
    Board b{v};
    chromosone c{b};
    EXPECT_EQ(b, c.get_board());
}

