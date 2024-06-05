#include <gtest/gtest.h>

// A simple test case
TEST(SampleTest, AssertionTrue) {
    EXPECT_EQ(1, 1);
}

// Another simple test case
TEST(SampleTest, AssertionFalse) {
    EXPECT_NE(1, 0);
}

// Main function for running all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
