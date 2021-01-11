#include <iostream>
#include <ctime>

//Exercise 5: Retirement Calculator
//https://repl.it/join/oruwatnq-bhupindersd
//https://repl.it/@BhupinderSD/Retirement-Calculator

int getNumber(std::string request) {
  int number;

  std::cout << request;
  std::cin >> number;
  while(std::cin.fail() || number < 0) {
    std::cout << "Please enter a valid age.\n\n";
    std::cin.clear(); //clears the error flag on cin so that future I/O operations work correctly
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //clear the buffer before taking new line
    std::cout << request;
    std::cin >> number;
  }
  return number;
}

int main() {
  int currentAge = getNumber("Please enter your current age? ");
  int retirementAge = getNumber("At what age would you like to retire? ");
  time_t now = time(0); //current time based on the system 
  tm *ltm = localtime(&now); //convert to local time 
  int currentYear = 1900 + ltm->tm_year; //get the year after 1900
  int retirementYear = currentYear + retirementAge - currentAge;
  int yearsRemaining = retirementYear - currentYear;
  
  if (yearsRemaining > 0) {
    std::cout << "\nThe current year is " << currentYear << ", can retire in " << retirementYear << "; you have " << yearsRemaining << " years remaining.\n";
  } else if (yearsRemaining == 0) {
    std::cout << "\nThe current and retirement year is " << currentYear << ", you can retire now.\n";
  } else {
    std::cout << "\nThe retirement year is " << retirementYear << " and the current year is " << currentYear << ", you should have retired " << yearsRemaining*-1 << " year(s) ago.\n";
  }

  return 0;
}
