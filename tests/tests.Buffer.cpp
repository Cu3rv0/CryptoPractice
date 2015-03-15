#include <iostream>
#include "gtest/gtest.h"
#include "Buffer.h"
#include <memory>

using namespace std;

class ConversionTests : public ::testing::Test 
{
public:
   unique_ptr<Buffer> m_buffer;

   ConversionTests():
      m_buffer(make_unique<Buffer>())
   {
   }
      
};

TEST_F(ConversionTests, buffer_reads_and_outputs_right_hex_value)
{
   // Given
   const string hexString = "CAFE";
   const vector<bool> expectedData = { 1,1,0,0,1,0,1,0,1,1,1,1,1,1,1,0 };
   
   m_buffer->SetValueHex(hexString);

   //When
   //Then
   ASSERT_EQ(expectedData,m_buffer->GetValueBinary());
   ASSERT_EQ(hexString,m_buffer->GetValueHex());
}

TEST_F(ConversionTests, b64_encoding)
{
   const string firstRangeChar = "S";
   vector<bool> firstRangeBin { 0, 1, 0, 0, 1, 0 };
   const string secondRangeChar = "b";
   vector<bool> secondRangeBin { 0, 1, 1, 0, 1, 1 };
   const string thirdRangeChar = "1";
   vector<bool> thirdRangeBin = {1,1,0,1,0,1};


   m_buffer->SetValueB64(firstRangeChar);
   EXPECT_EQ(firstRangeBin,m_buffer->GetValueBinary());
   EXPECT_EQ(firstRangeChar,m_buffer->GetValueB64());

   m_buffer->SetValueB64(secondRangeChar);
   EXPECT_EQ(secondRangeBin,m_buffer->GetValueBinary());
   EXPECT_EQ(secondRangeChar,m_buffer->GetValueB64());

   m_buffer->SetValueB64(thirdRangeChar);
   EXPECT_EQ(thirdRangeBin,m_buffer->GetValueBinary());
   EXPECT_EQ(thirdRangeChar,m_buffer->GetValueB64());
}

TEST_F(ConversionTests, buffer_reads_and_outputs_right_b64_value)
{
   // Given
   const string b64String = "SSdt";
   const vector<bool> expectedData = {0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1,0,1,1,0,1};

   m_buffer->SetValueB64(b64String);
   //When
   //Then
   EXPECT_EQ(expectedData,m_buffer->GetValueBinary());
   EXPECT_EQ(b64String,m_buffer->GetValueB64());
}

TEST_F(ConversionTests, buffer_passes_cryptopals_challenge)
{
   // Given
   const string hexString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
   const string expectedb64String = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

   // When
   m_buffer->SetValueHex(hexString);

   // Then
   ASSERT_EQ(expectedb64String,m_buffer->GetValueB64());
}
