#include <iostream>

#include "gl2d/include/radians.h"
#include "gtest/gtest.h"

namespace gl2d {

class RadiansTest : public ::testing::Test {
};

TEST_F(RadiansTest, Constructor) {
  Radians rad1(3.14);
  Radians rad2;
  
  EXPECT_DOUBLE_EQ(rad1.radians_, 3.14);
  EXPECT_DOUBLE_EQ(rad2.radians_, 0);
}

TEST_F(RadiansTest, DoubleAssignment) {
  Radians rad(0);
  rad = 3.14;

  EXPECT_DOUBLE_EQ(rad.radians_, 3.14);
}

}  // namespace gl2d
