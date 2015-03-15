#include <iostream>
#include "gtest/gtest.h"
#include "Converter.h"
#include <memory>

using namespace std;

class ConversionTests : public ::testing::Test 
{
public:
   unique_ptr<Converter> m_converter;

   ConversionTests():
      m_converter(make_unique<Converter>())
   {
   }
      
};

TEST_F(ConversionTests, converter_reads_and_outputs_right_hex_value)
{
   // Given
   const string hexString = "CAFE";
   const vector<bool> expectedData = { 1,1,0,0,1,0,1,0,1,1,1,1,1,1,1,0 };
   
   m_converter->SetValueHex(hexString);

   //When
   //Then
   ASSERT_EQ(expectedData,m_converter->GetValueBinary());
   ASSERT_EQ(hexString,m_converter->GetValueHex());
}

TEST_F(ConversionTests, b64_encoding)
{
   const string firstRangeChar = "S";
   vector<bool> firstRangeBin { 0, 1, 0, 0, 1, 0 };
   const string secondRangeChar = "b";
   vector<bool> secondRangeBin { 0, 1, 1, 0, 1, 1 };
   const string thirdRangeChar = "1";
   vector<bool> thirdRangeBin = {1,1,0,1,0,1};


   m_converter->SetValueB64(firstRangeChar);
   EXPECT_EQ(firstRangeBin,m_converter->GetValueBinary());
   EXPECT_EQ(firstRangeChar,m_converter->GetValueB64());

   m_converter->SetValueB64(secondRangeChar);
   EXPECT_EQ(secondRangeBin,m_converter->GetValueBinary());
   EXPECT_EQ(secondRangeChar,m_converter->GetValueB64());

   m_converter->SetValueB64(thirdRangeChar);
   EXPECT_EQ(thirdRangeBin,m_converter->GetValueBinary());
   EXPECT_EQ(thirdRangeChar,m_converter->GetValueB64());
}

TEST_F(ConversionTests, converter_reads_and_outputs_right_b64_value)
{
   // Given
   const string b64String = "SSdt";
   const vector<bool> expectedData = {0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1,0,1,1,0,1};

   m_converter->SetValueB64(b64String);
   //When
   //Then
   EXPECT_EQ(expectedData,m_converter->GetValueBinary());
   EXPECT_EQ(b64String,m_converter->GetValueB64());
}

TEST_F(ConversionTests, converter_passes_cryptopals_challenge)
{
   // Given
   const string hexString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
   const string expectedb64String = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

   // When
   m_converter->SetValueHex(hexString);

   // Then
   ASSERT_EQ(expectedb64String,m_converter->GetValueB64());
}
