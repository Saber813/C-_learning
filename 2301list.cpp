/**
 * @file 2301list.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <ios>
#include <iostream>
#include <ostream>

/**
 * @brief 
 * 
 * @param precision 
 * @param value 
 */
void print(int precision, float value)
{
  std::cout.precision(precision);
  std::cout << std::scientific << value << '\t'
            << std::fixed      << value << '\t';

  // Set the format to general.
  std::cout.unsetf(std::ios_base::floatfield);
  std::cout << value << '\n';
}

/// Main program.
int main()
{
  print(6, 123456.789f); 
  print(4, 1.23456789f);
  print(2, 123456789.f);
  print(5, -1234.5678e9f);
}
