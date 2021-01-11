#include <iostream>
#include <ctype.h>

//Exercise 9: Character Type Checker
//https://repl.it/join/zhrslmlt-bhupindersd
//https://repl.it/@BhupinderSD/Character-Type-Checker

void flushBuffer() {
    std::cin.clear(); //resets the cin stream state so that future I/O operations work correctly
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //clears the cin buffer including new lines
}

int main() {
  while (true) { 
    std::cout << "\nPlease enter a character? ";
    char character = getchar(); //gets the next character 
    flushBuffer(); //clears any additional characters or new lines
    if (isalpha(character)) {
      std::cout << "Alphabetic character detected.";
    } else if (isdigit(character)) {
      std::cout << "Digit character detected.";
    } else {
      std::cout << "Special character detected.";
    }

    std::cout << "\n\nTry again (Y/N)? ";
    char tryAgain = toupper(getchar());
    flushBuffer();
    if (tryAgain == 'Y') {
      continue; //runs the loop again
    } else if (tryAgain == 'N') {
      break;
    } else {
      std::cout << "Invalid input, closing program";
      break; //closes the program if the user enters an invalid input 
    }
  }

  std::cout << "\nThank you, good bye.\n";
  
  return 0;
}
