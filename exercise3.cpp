#include <iostream>

//Exercise 3: Area of a Rectangle Room
//https://repl.it/join/bpgqfoml-bhupindersd
//https://repl.it/@BhupinderSD/AreaOfARectangleRoom

float getNumber(std::string request) {
  float number;

  std::cout << request;
  std::cin >> number;
  while(std::cin.fail()) {
    std::cout << "Please enter a number.\n\n";
    std::cin.clear(); //clears the error flag on cin so that future I/O operations work correctly
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //clear the buffer before taking new line
    
    std::cout << request;
    std::cin >> number;
  }
  return number;
}

char getUnit() {
  char unit;

  std::cout << "Press \'F\' to enter your units in feet. ";
  std::cout << "\nPress \'M\' to enter your units in meters.  ";

  do {
    std::cout << "\n\nYour choice: ";
    std::cin >> unit;
    std::cin.clear(); //clears any error flag on cin so that future I/O operations work correctly
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //clear buffer after taking the first character
    unit = toupper(unit);

    if (unit != 'F' && unit != 'M') {
      std::cout << "Please enter \'F\' or \'M\'.";
    }
    
  } while (unit != 'F' && unit != 'M');

  return unit;
}

int main() {
  const float SQ_FOOT_TO_SQ_METERS_FACTOR = 0.092903;

  char unit = getUnit();
  float length = getNumber("\nWhat is the length of the room? ");
  float width = getNumber("What is the width of the room? ");
  float areaInFoot;
  float areaInMeters;
  std::string unitName;

  if (unit == 'F') {
    unitName = "feet";
    areaInFoot = length * width;
    areaInMeters = areaInFoot * SQ_FOOT_TO_SQ_METERS_FACTOR;
  } else {
    unitName = "meters";
    areaInMeters = length * width;
    areaInFoot = areaInMeters / SQ_FOOT_TO_SQ_METERS_FACTOR;
  }

  std::cout << "\nYour room\'s dimension is " << length << " by " << width << " " << unitName << ", the area is: ";
  std::cout << "\n" << areaInFoot << " square foot";
  std::cout << "\n" << areaInMeters << " square meters\n";

  return 0;
}
