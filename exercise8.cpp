#include <iostream>
#include <unordered_set>
#include <limits>

//Exercise 8: Low & Largest Numbers
//https://repl.it/join/mxdwhiwj-bhupindersd
//https://repl.it/@BhupinderSD/Low-and-Largest-Numbers

int main() {
  int lowestValue = std::numeric_limits<int>::max(); //using the highest possible value so we can always have a lower number
  int largestValue = std::numeric_limits<int>::lowest(); //using the lowest possible value so we can always have a larger number
  std::unordered_set<int> set; //used to store unique numbers

  std::cout << "Please enter a valid numeric, or “Q” to finish:\n";

  while(true) { //continue asking for numbers until the user enters 'Q'
    bool shouldQuit = false;
    int number;
    std::cin >> number;
    while(std::cin.fail()) { //error handling since the input was not a number
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

    if (set.insert(number).second == false) { //a set only stores unique values, so if it is a duplicate, it will not add it 
      std::cout << "Duplicate number, ignored.\n";
      continue;
    }

    if (number < lowestValue) {
      lowestValue = number;
    } 
    if (number > largestValue) {
      largestValue = number;
    }
  }

  std::cout << "\nTotal number of unique values entered: " <<  set.size();

  if (set.size() == 0) { //if no values were entered, end the program
    std::cout << std::endl;
    return 0;
  }

  std::cout << "\nLowest value:\t\t" <<  lowestValue;
  std::cout << "\nLargest value:\t\t" <<  largestValue;
  std::cout << std::endl;

  return 0;
}
