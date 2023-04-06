#include <iostream>
#include <vector>

void bankPass(std::vector<int> numbers, std::string password) {
  for(auto i = numbers.begin(); i != numbers.end(); ++i) {
    std::cout << "\nLetter " << *i << ": " << password.at(*i - 1);
  }
}

int main() {
  std::vector<int> numbers;
  int numCount;
  std::string password;

  std::cout << "Your password: ";
  std::cin >> password;

  std::cout << "\nHow many characters do you have to provide? ";
  std::cin >> numCount;
  std::cout << "\n";

  for(int i = 0; i < numCount; i++) {
    int temp;
    std::cout << "Number " << i + 1 << ": ";
    std::cin >> temp;
    numbers.push_back(temp);
  }

  bankPass(numbers, password);

}