#include <gtest/gtest.h>
#include <flexbuffer/flexbuffer.h>

namespace {

TEST(ProjectName, AnswerReturnsExpectedValue) {
  EXPECT_EQ(flexbuffer::Answer(), 42);
}

}  // namespace
