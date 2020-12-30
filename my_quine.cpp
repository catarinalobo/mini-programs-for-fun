#include <iostream>
int main() {
  std::string my_quine[] = {
    "#include <iostream>",
    "int main() {",
    " std::string my_quine[] = {",
    " };",
    " std::cout << my_quine[0] << std::endl << my_quine[1] << std::endl << std::string(1,(char)32) << my_quine[2] << std::endl;",
    " for(int i=0; i<11; i++)",
    "   std::cout << std::string(1,(char)32) << std::string(1,(char)32) << std::string(1,(char)32) << std::string(1,(char)32) << std::string(1,(char)34) << my_quine[i] << std::string(1,(char)34)+std::string(1,(char)44) << std::endl;",
    " std::cout << std::string(1,(char)32) << std::string(1,(char)32) << std::string(1,(char)32) << std::string(1,(char)32) << std::string(1,(char)34) << my_quine[11] << std::string(1,(char)34) << std::endl;",
    " for(int i=3; i<11; i++)",
    "   std::cout << std::string(1,(char)32) << my_quine[i] << std::endl;",
    " std::cout << my_quine[11];",
    "}"
  };
  std::cout << my_quine[0] << std::endl << my_quine[1] << std::endl << std::string(1,(char)32) << my_quine[2] << std::endl;
  for(int i=0; i<11; i++)
    std::cout << std::string(1,(char)32) << std::string(1,(char)32) << std::string(1,(char)32) << std::string(1,(char)32) << std::string(1,(char)34) << my_quine[i] << std::string(1,(char)34)+std::string(1,(char)44) << std::endl;
  std::cout << std::string(1,(char)32) << std::string(1,(char)32) << std::string(1,(char)32) << std::string(1,(char)32) << std::string(1,(char)34) << my_quine[11] << std::string(1,(char)34) << std::endl;
  for(int i=3; i<11; i++)
    std::cout << std::string(1,(char)32) << my_quine[i] << std::endl;
  std::cout << my_quine[11];
}