#include <iostream>

//Exercise 1: Quote a quote
//https://repl.it/join/rzwfjzbr-bhupindersd
//https://repl.it/@BhupinderSD/QuoteAQuote

int main() {
  std::string quote;
  std::string author;
  
	std::cout << "What is the quote? ";
  getline(std::cin, quote);

  std::cout << "Who said it? ";
  getline(std::cin, author);

  std::cout << "\n" << author << " says: \"" << quote << "\"\n";
  
  return 0;
}
