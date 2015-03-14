#pragma once
#include <string>
#include <vector>

class Converter
{
public:
   Converter();

   std::string GetValueB64() const;
   std::string GetValueHex() const;
   std::vector<unsigned char> GetValueBinary() const;

   void SetValueHex(const std::string& hexString);
   void SetValueb64(const std::string& b64String);
   void setValueBinary(std::vector<unsigned char> data, unsigned int size);

private:
   
   void Load(const unsigned char);
   std::vector<unsigned char> m_data;
   unsigned char m_lastCharSize;
};
