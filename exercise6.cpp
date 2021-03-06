#include <iostream>

//Exercise 6: Karvonen Heart Rate Calculator
//https://repl.it/join/apydwfsf-bhupindersd
//https://repl.it/@BhupinderSD/Karvonen-Heart-Rate-Calculator

void flushBuffer() {
    std::cin.clear(); //resets the cin stream state so that future I/O operations work correctly
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //clears the cin buffer including new lines or additional characters
}

//Get a number that is larger than or equal to 0
int getNumber(std::string request) {
  int number;

  std::cout << request;
  std::cin >> number;
  while(std::cin.fail() || number < 0) { //while the user enters an invalid input, keep asking for a valid input 
    std::cout << "Invalid input.\n\n";
    flushBuffer(); 
    std::cout << request;
    std::cin >> number;
  }
  flushBuffer(); 
  return number;
}

int calculateTargetHeartRate(int age, int restingHR, float intensity) {
  int maxHR = 220 - age;
  return ((maxHR - restingHR) * (intensity/100)) + restingHR; //Karvonen formular
}

int main() {
  int intensity = 40;
  int age = getNumber("Please enter your age: ");
  int pulse = getNumber("Please enter your resting pulse: ");

  std::cout << "\nResting pulse: " << pulse << "\tAge: " << age << std::endl;
  std::cout << "\nIntensity\t\tRate";
  std::cout << "\n------------------------";

  do { //generate the table at intensities incrementing by 5% till 100% exclusive
  int targetHeartRate = calculateTargetHeartRate(age, pulse, intensity);
  std::cout << "\n" << intensity << "%.\t\t\t" << targetHeartRate << " bpm";
  intensity += 5;
  } while (intensity < 100);

  std::cout << std::endl;
}
