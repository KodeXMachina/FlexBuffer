#include <flexbuf/flexbuf.h>
#include <gtest/gtest.h>

namespace {

TEST(Flexbuf, AnswerReturnsExpectedValue) { EXPECT_EQ(flexbuf::Answer(), 42); }

}  // namespace
