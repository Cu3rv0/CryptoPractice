#include "Converter.h"
#include <algorithm>
#include <iostream>

using namespace std;

string Converter::GetValueB64() const
{
   return "Hello!";
}

unsigned char BinToHexChar(unsigned char bin)
{
   if (bin < 10) return '0' + bin;

   return 'A' + bin - 10;
}

unsigned char hexCharToBin(unsigned char hexChar)
{
   if (hexChar < 'A') return hexChar - '0';

   return hexChar - 'A' + 10;
}

string Converter::GetValueHex() const
{
   string hexString;
   unsigned char binCharacter;

   for (auto charIndex = 0; charIndex < m_dataBlob.size(); charIndex +=4)
   {
      for (auto bitIndex = 0; bitIndex != 4; ++bitIndex)
      {
          binCharacter += m_dataBlob[charIndex + bitIndex] << (3 - bitIndex);
      }
      hexString += BinToHexChar(binCharacter);
      binCharacter = 0;
   }
   return hexString;
}

void Converter::SetValueHex(const string& hexString)
{
   for_each(hexString.begin(),
            hexString.end(),
            [this](unsigned char c) mutable
            {
               for(auto i = 3; i >= 0; --i)
               {
                  m_dataBlob.push_back((hexCharToBin(c) >> i) & 1);
               }
            });
}

vector<bool> Converter::GetValueBinary() const
{
   return m_dataBlob;
}

