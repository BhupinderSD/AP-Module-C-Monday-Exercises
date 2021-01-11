#include <iostream>

//Exercise 4: Odds & Evens
//https://repl.it/join/rnyasjts-bhupindersd
//https://repl.it/@BhupinderSD/OddsAndEvens

long getNumber(std::string request) {
  long number;

  std::cout << request;
  std::cin >> number;
  while(std::cin.fail()) {
    std::cout << "Please enter a valid number.\n\n";
    std::cin.clear(); //clears the error flag on cin so that future I/O operations work correctly
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //clear the buffer before taking new line
    
    std::cout << request;
    std::cin >> number;
  }
  return number;
}

int main() {
  long number;
  bool isEven;

  number = getNumber("Please enter a value? ");

  if (number % 2 == 0) { //check if the remainder is 0
    std::cout << number << " is an even number\n";
  } else {
    std::cout << number << " is an odd number\n";
  }

  return 0;
}
