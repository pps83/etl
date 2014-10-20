///\file

/******************************************************************************
The MIT License(MIT)

Embedded Template Library.

Copyright(c) 2014 jwellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#ifndef __etl_math__
#define __etl_math__

#include <cstddef>

namespace etl 
{
  //***************************************************************************
  /// The base generic log template.
  /// Defines 'value' as the log of the number at the specified base.
  /// The result is rounded down to the next integer.
  ///\tparam N    The number to find the log of.
  ///\tparam BASE The base of the log.
  //***************************************************************************
  template <const size_t N, const size_t BASE>
  struct log
  {
    enum value_type
    {
      // Recursive definition.
      value = (N >= BASE) ? 1 + log<N / BASE, BASE>::value : 0
    };
  };

  //***************************************************************************
  /// Specialisation for N = 1
  //***************************************************************************
  template <const size_t BASE>
  struct log<1, BASE>
  {
    enum value_type
    {
      value = 0
    };
  };

  //***************************************************************************
  /// Specialisation for N = 0
  //***************************************************************************
  template <const size_t BASE>
  struct log<0, BASE>
  {
    enum value_type
    {
      value = 0
    };
  };

  //***************************************************************************
  /// The specialisation for base 2 logs.
  //***************************************************************************
  template <const size_t N>
  struct Log2
  {
    enum value_type
    {
      value = log<N, 2>::value
    };
  };

  //***************************************************************************
  /// The specialisation for base 10 logs.
  //***************************************************************************
  template <const size_t N>
  struct Log10
  {
    enum value_type
    {
      value = log<N, 10>::value
    };
  };
}

#endif
