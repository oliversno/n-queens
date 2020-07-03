#include <gtest/gtest.h>
#include "include/chromosone.h"

TEST(ChromosoneTests, ctor){
    std::vector<int> v{2,3,1};
    Board b{v};
    chromosone c{b};
    SUCCEED();
}

TEST(ChromosoneTests, nCk_0_groups){
    EXPECT_EQ(chromosone::nCk(1,0), 1);
    EXPECT_EQ(chromosone::nCk(5,0), 1);
    EXPECT_EQ(chromosone::nCk(18,0), 1);
}

TEST(ChromosoneTests, nCk_1_group){
    EXPECT_EQ(chromosone::nCk(1,1), 1);
    EXPECT_EQ(chromosone::nCk(5,1), 5);
    EXPECT_EQ(chromosone::nCk(18,1), 18);
}

TEST(ChromosoneTests, nCk_2_groups){
    EXPECT_EQ(chromosone::nCk(7,2), 21);
    EXPECT_EQ(chromosone::nCk(18,2), 153);
    EXPECT_EQ(chromosone::nCk(4,2), 6);
    EXPECT_EQ(chromosone::nCk(8,2), 28);
}

TEST(ChromosoneTests, calculateFitness_noConflict){
    std::vector<int> v{1, 3, 5, 7, 2, 0, 6, 4};
    Board b{v};
    chromosone c{b};
    EXPECT_EQ(c.get_board().get_n(), 8);
    c.calculateFitness();
    EXPECT_EQ(c.get_fitness(), chromosone::nCk(8,2));
}

TEST(ChromosoneTests, calculateFitness_someConflict){
    std::vector<int> v{0, 2, 1, 3};
    Board b{v};
    chromosone c{b};
    EXPECT_EQ(c.get_board().get_n(), 4);
    c.calculateFitness();
    EXPECT_EQ(c.get_fitness(), chromosone::nCk(4,2)-2);
}

TEST(ChromosoneTests, calculateFitness_allConflict){
    std::vector<int> v{1, 1, 1};
    Board b{v};
    chromosone c{b};
    EXPECT_EQ(c.get_board().get_n(), 3);
    c.calculateFitness();
    EXPECT_EQ(c.get_fitness(), 0);
}

TEST(ChromosoneTests, mutate){
    std::vector<int> v{1, 3, 5, 7, 2, 0, 6, 4};
    Board b{v};
    chromosone c{b};
    c.mutate(100);
    EXPECT_NE(b, c.get_board());
}

TEST(ChromosoneTests, crossover){
    std::vector<int> v1{1, 3, 5, 7, 2, 0, 6, 4};
    std::vector<int> v2{3, 2, 6, 5, 4, 1, 0, 7};
    Board b1{v1};
    Board b2{v2};
    chromosone c1{b1};
    chromosone c2{b2};
    c1.crossover(c2);
    EXPECT_NE(b1, c1.get_board());
    EXPECT_NE(b2, c2.get_board());
}

TEST(ChromosoneTests, getBoard){
    std::vector<int> v{2,3,1};
    Board b{v};
    chromosone c{b};
    EXPECT_EQ(b, c.get_board());
}

