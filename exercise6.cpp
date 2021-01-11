#include <iostream>

//Exercise 6: Karvonen Heart Rate Calculator
//https://repl.it/join/apydwfsf-bhupindersd
//https://repl.it/@BhupinderSD/Karvonen-Heart-Rate-Calculator

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

//Karvonen formular
int calculateTargetHeartRate(int age, int restingHR, float intensity) {
  int maxHR = 220 - age;
  return ((maxHR - restingHR) * (intensity/100)) + restingHR;
}

int main() {
  int intensity = 40;
  int age = getNumber("Please enter your age: ");
  int pulse = getNumber("Please enter your resting pulse: ");

  std::cout << "\nResting pulse: " << pulse << "\tAge: " << age << std::endl;
  std::cout << "\nIntensity\t\tRate";
  std::cout << "\n------------------------";

  do {
  int targetHeartRate = calculateTargetHeartRate(age, pulse, intensity);
  std::cout << "\n" << intensity << "%.\t\t\t" << targetHeartRate << " bpm";
  intensity += 5;
  } while (intensity < 100);

  std::cout << std::endl;
}
