#include <iostream>

//Exercise 2: Fahrenheit Centigrade Conversion
//https://repl.it/join/cwfzqrss-bhupindersd
//https://repl.it/@BhupinderSD/FahrenheitCentigradeConversion

float fahrenheitToCentigrade(float temperature) {
  return (temperature - 32) * 5/9;
}

float centigradeToFahrenheit(float temperature) {
  return (temperature * 9/5) + 32;
}

char getChoice() {
  char choice;
  std::cout << "\n\nYour choice: ";
  std::cin >> choice;
  return toupper(choice);
}

int main() {
  float temperature;
  char choice;

  std::cout << "Please enter the starting temperature: ";
  std::cin >> temperature;

  std::cout << "Press \'C\' to convert from Fahrenheit to Centigrade. ";
  std::cout << "\nPress \'F\' to convert from Centigrade to Fahrenheit. ";

  do {
    std::cout << "\n\nYour choice: ";
    std::cin >> choice;
    choice = toupper(choice);
    
    switch(choice) {
      case 'C': {
        std::cout << temperature << " degrees Fahrenheit is " << fahrenheitToCentigrade(temperature) << "\n";
        break;
      }
      case 'F': {
        std::cout << temperature << " degrees Centigrade is " << centigradeToFahrenheit(temperature) << "\n";
        break;
      }
      default: {
        std::cout << "Please enter \'C\' or \'F\'.";
        break;
      }
    }
  } while (choice != 'C' && choice != 'F');

  return 0;
}
