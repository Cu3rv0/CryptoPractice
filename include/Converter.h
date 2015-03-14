#pragma once
#include <string>
#include <vector>

class Converter
{
public:
   std::string GetValueB64() const;
   std::string GetValueHex() const;
   std::vector<unsigned char> GetValueBinary() const;

   void SetValueHex(const std::string& hexString);
   void SetValueb64(const std::string& b64String);
   void setValueBinary(std::vector<unsigned char> data, unsigned int size);

private:

   std::vector<unsigned char> m_data;
};
