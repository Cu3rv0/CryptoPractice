#pragma once
#include "Buffer.h"
#include <algorithm>

Buffer operator^(const Buffer& lhs, const Buffer& rhs)
{
   unsigned int minSize = std::min(lhs.Size(),rhs.Size());
   std::vector<bool> xorResult(minSize);

   for (auto i = 0; i != minSize; ++i)
   {
      xorResult[i] = lhs.GetValueBinary()[i] ^ rhs.GetValueBinary()[i];
   }

   return Buffer(xorResult);
}
