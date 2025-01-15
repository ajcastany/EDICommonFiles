#include <gtest/gtest.h>
#include <string>
#include "FileHeader.h"
#include "StringUtils.h"

TEST(FileHeaderTest, ValidLength) {
  CommonFormatFile::FileHeader header {'A', "00000", "40", "AA", "25", 'S'};
  std::string result = header.getRow();
  EXPECT_EQ(result.size(), 194);
}

TEST(FileHeaderTest, ValidContent) {
  CommonFormatFile::FileHeader header {'A', "00000", "40", "AA", "25", 'S'};
  std::string result = header.getRow();
  EXPECT_EQ(result, rpad("A10000040AA25SQTCXX  0114"));
}

TEST(FileHeaderTest, DataTypeNotAE) {
  EXPECT_THROW(
               CommonFormatFile::FileHeader('F', "00000", "40", "AA", "25", 'S'),
               std::invalid_argument
               );
}

TEST(FileHeaderTest, CentreShortLength) {
  EXPECT_THROW(
               CommonFormatFile::FileHeader('A', "", "40", "AA", "25", 'S'),
               std::invalid_argument
               );
}

TEST(FileHeaderTest, CentreLongLength) {
  EXPECT_THROW(
               CommonFormatFile::FileHeader('A', "000000", "40", "AA", "25", 'S'),
               std::invalid_argument
               );
}

TEST(FileHeaderTest, CentreHasAlpha) {
  EXPECT_THROW(
               CommonFormatFile::FileHeader('A', "00A00", "40", "AA", "25", 'S'),
               std::invalid_argument
               );
}

TEST(FileHeaderTest, AOHasAlpha) {
  EXPECT_THROW(
               CommonFormatFile::FileHeader('A', "00000", "4A", "AA", "25", 'S'),
               std::invalid_argument
               );
}

TEST(FileHeaderTest, AOShortLength) {
  EXPECT_THROW(
               CommonFormatFile::FileHeader('A', "00000", "4", "AA", "25", 'S'),
               std::invalid_argument
               );
}

TEST(FileHeaderTest, AOLongLength) {
  EXPECT_THROW(
               CommonFormatFile::FileHeader('A', "00000", "4000", "AA", "25", 'S'),
               std::invalid_argument
               );
}

TEST(FileHeaderTest, ExamSeriesTooLong) {
  EXPECT_THROW(
               CommonFormatFile::FileHeader('A', "00000", "40", "AAA", "25", 'S'),
               std::invalid_argument
               );
}

TEST(FileHeaderTest, ExamSeriesTooShort) {
  EXPECT_THROW(
               CommonFormatFile::FileHeader('A', "00000", "40", "A", "25", 'S'),
               std::invalid_argument
               );
}

TEST(FileHeaderTest, ExamSeriesHasZero) {
  EXPECT_THROW(
               CommonFormatFile::FileHeader('A', "00000", "40", "A0", "25", 'S'),
               std::invalid_argument
               );
}

TEST(FileHeaderTest, ExamSeriesWrongLetter) {
  EXPECT_THROW(
               CommonFormatFile::FileHeader('A', "00000", "40", "ZA", "25", 'S'),
               std::invalid_argument
               );
}

TEST(FileHeaderTest, DistTypeNotSBM) {
  EXPECT_THROW(
               CommonFormatFile::FileHeader('A', "00000", "40", "AA", "25", 'J'),
               std::invalid_argument
               );
}
