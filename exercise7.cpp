#include <iostream>

//Exercise 7: Zero, Positive & Negative Type Counter
//https://repl.it/join/vkndarpn-bhupindersd
//https://repl.it/@BhupinderSD/Zero-Positive-and-Negative-Type-Counter

int main() {
  int positiveCount = 0;
  int negativeCount = 0;
  int zeroCount = 0;

  std::cout << "Please enter a valid numeric, or “Q” to finish:\n";

  while(true) { //continue asking for numbers until the user enters 'Q'
    bool shouldQuit = false;
    int number;
    std::cin >> number;
    while(std::cin.fail()) {
      char charValue;
      std::cin.clear(); //clears the error flag on cin so that future I/O operations work correctly
      if ((std::cin >> charValue) && toupper(charValue) == 'Q' ) { //check if the user is trying to quit
          shouldQuit = true;  //sets a flag so we break the outer while loop
          break; //breaks the inner while loop so we don't show an error for entering a character instead of a number
      }

      std::cout << "Invalid value, please try again:\n";
      std::cin.clear(); //clears the error flag on cin so that future I/O operations work correctly
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //clear the buffer before taking a new line
      std::cin >> number;
    }

    if (shouldQuit) {
      break; //breaks the while true loop and stops asking for more numbers
    }
    
    if (number < 0) {
      negativeCount++;
    } else if (number == 0) {
      zeroCount++;
    } else {
      positiveCount++;
    }
  }

  int totalCount = positiveCount + negativeCount + zeroCount;
  std::cout << "\nTotal number of values entered: " <<  totalCount;
  std::cout << "\nZeros:\t\t" <<  zeroCount;
  std::cout << "\nPositives:\t" <<  positiveCount;
  std::cout << "\nNegatives:\t" <<  negativeCount;
  std::cout << std::endl;

  return 0;
}

