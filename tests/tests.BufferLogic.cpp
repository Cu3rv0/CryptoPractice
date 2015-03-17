#include <iostream>
#include "gtest/gtest.h"
#include "Buffer.h"
#include "BufferLogic.h"
#include <memory>

using namespace std;

class BufferLogicTests : public ::testing::Test 
{
public:
   unique_ptr<Buffer> m_bufferA;
   unique_ptr<Buffer> m_bufferB;

   BufferLogicTests():
      m_bufferA(make_unique<Buffer>()),
      m_bufferB(make_unique<Buffer>())
   {
   }
      
};

TEST_F(BufferLogicTests, buffer_reads_and_outputs_right_hex_value)
{
  m_bufferA->SetValueHex("1c0111001f010100061a024b53535009181c");
  m_bufferB->SetValueHex("686974207468652062756c6c277320657965");
  Buffer bufferC(*m_bufferA^*m_bufferB);

  string expectedHexString = "746865206b696420646f6e277420706c6179";
  ASSERT_EQ(expectedHexString, bufferC.GetValueHex());
}
