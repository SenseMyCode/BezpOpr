#include <iostream>
using namespace std;
int main(){
  cout << "char "        << sizeof(char)        << endl
       << "short "       << sizeof(short)       << endl
       << "int "         << sizeof(int)         << endl
       << "long "        << sizeof(long)        << endl
       << "long long "   << sizeof(long long)   << endl
       << "float "       << sizeof(float)       << endl
       << "double "      << sizeof(double)      << endl
       << "long double " << sizeof(long double) << endl
       << "bool "        << sizeof(bool)        << endl
       << "void* "       << sizeof(void*)       << endl;
}