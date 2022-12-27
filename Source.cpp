#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>

// Structure containing country and capital names
struct ñountryÑapital
{
	std::string country;
	std::string capital;
};

// Vector to store country and capital structures
std::vector<ñountryÑapital> vectorCountryÑapital;

// The function fills the vector with structures containing the names of countries and capitals
void fillVector(std::string pathToFile, std::vector<ñountryÑapital> &outputVector)
{
	ñountryÑapital tmp;
	std::ifstream inputFile(pathToFile); // Open file for reading
	if (!inputFile.is_open())
		std::cout << "Error open file\n";
	else
	{
		while (!inputFile.eof())  // Execute until end of file
		{
			inputFile >> tmp.country;  // Put country name from file into structure
			inputFile >> tmp.capital;  // Put the name of the capital from the file into the structure
			outputVector.push_back(tmp);  // Add structure to end of vector
		}
	}
}

// Prints a vector to the console (structures of countries and capitals)
void printVector(std::vector<ñountryÑapital> outputVector)
{
	for (int i = 0; i < outputVector.size(); i++)
	{
		std::cout << "Country: " << outputVector[i].country << "\r\t\t\t";
		std::cout << "Capital: " << outputVector[i].capital << '\n';
	}
}

// The function searches the vector for a country by the given capital and displays it in the console
void searchCountry(std::vector<ñountryÑapital> outputVector, std::string inputCapital)
{
	bool found = false;
	for (int i = 0; i < outputVector.size(); i++)
	{
		if (outputVector[i].capital == inputCapital)
		{
			std::cout << "Country: " << outputVector[i].country << '\n';
			found = true;
		}
	}
	if (!found)
		std::cout << "The given capital was not found in the dictionary\n";
}

// The function searches the vector for the capital on the given side and outputs it to the console
void searchCapital(std::vector<ñountryÑapital> outputVector, std::string inputCountry)
{
	bool found = false;
	for (int i = 0; i < outputVector.size(); i++)
	{
		if (outputVector[i].country == inputCountry)
		{
			std::cout << "Capital: " << outputVector[i].capital << '\n';
			found = true;
		}
	}
	if (!found)
		std::cout << "This country was not found in the dictionary\n";
}

int main()
{
	std::string tmp;
	fillVector("list.txt", vectorCountryÑapital);
	char menu = '0';
	while (menu != '4')
	{

		std::cout << "1. Displaying the capital of a given state\n";
		std::cout << "2. Displaying the state whose capital is a given city\n";
		std::cout << "3. Show list of capital country\n";
		std::cout << "4. Exiting the program\n";
		menu = _getch();
		system("cls");
		switch (menu)
		{
		case '1':
			std::cout << "Enter country: ";
			std::getline(std::cin, tmp);
			searchCapital(vectorCountryÑapital, tmp);
			system("pause");
			system("cls");
			break;
		case '2':
			std::cout << "Enter capital: ";
			std::getline(std::cin, tmp);
			searchCountry(vectorCountryÑapital, tmp);
			system("pause");
			system("cls");
			break;
		case '3':
			printVector(vectorCountryÑapital);
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}