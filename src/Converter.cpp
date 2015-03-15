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
   else return 'A' + bin - 10;
}

unsigned char HexCharToBin(unsigned char hexChar)
{
   if (hexChar < 'A') return hexChar - '0';
   else return hexChar - 'A' + 10;
}

unsigned char B64CharToBin(unsigned char b64Char)
{
   if (b64Char < 'a') return b64Char - 'A';
   if (b64Char < '0') return 26 + b64Char - 'a';
   else return 52 + b64Char - '0';
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

vector<bool> Converter::GetValueBinary() const
{
   return m_dataBlob;
}

void Converter::SetValueHex(const string& hexString)
{
   for_each(hexString.begin(),
            hexString.end(),
            [this](unsigned char c) mutable
            {
               for(auto i = 3; i >= 0; --i)
               {
                  m_dataBlob.push_back((HexCharToBin(c) >> i) & 1);
               }
            });
}


void Converter::SetValueB64(const string& b64String)
{
   for_each(b64String.begin(),
            b64String.end(),
            [this](unsigned char c) mutable
            {
               for(auto i = 5; i>= 0; --i)
               {
                  m_dataBlob.push_back((B64CharToBin(c) >> i) & 1);
               }
            });
}
