#include <iostream>


int main()
{
	char symbol;
	std::cout << "Write a symbol" << std::endl;	
	std::cin >> symbol;

	switch(symbol)
	{
		case 'A'...'Z':
			std::cout << "Capital letters" << std::endl;
			break;
		case 'a'...'z':
			std::cout << "Lowercase letters" << std::endl;
			break;
		case '0'...'9':
			std::cout << "Digits" << std::endl;
			break;
		case ']':
			[[fallthrough]];
		case '[':
			[[fallthrough]];
		case ':'...'?':
			[[fallthrough]];
		case '!'...'/':
			std::cout << "Punctuation Symbols" << std::endl;
			break;
		default:
			std::cout << "Other symbols" << std::endl;
			break;
	}
}

