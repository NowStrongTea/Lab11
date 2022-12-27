#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>

// Structure containing country and capital names
struct �ountry�apital
{
	std::string country;
	std::string capital;
};

// Vector to store country and capital structures
std::vector<�ountry�apital> vectorCountry�apital;

// The function fills the vector with structures containing the names of countries and capitals
void fillVector(std::string pathToFile, std::vector<�ountry�apital> &outputVector)
{
	�ountry�apital tmp;
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
void printVector(std::vector<�ountry�apital> outputVector)
{
	for (int i = 0; i < outputVector.size(); i++)
	{
		std::cout << "Country: " << outputVector[i].country << "\r\t\t\t";
		std::cout << "Capital: " << outputVector[i].capital << '\n';
	}
}

// The function searches the vector for a country by the given capital and displays it in the console
void searchCountry(std::vector<�ountry�apital> outputVector, std::string inputCapital)
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
void searchCapital(std::vector<�ountry�apital> outputVector, std::string inputCountry)
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
	fillVector("list.txt", vectorCountry�apital);
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
			searchCapital(vectorCountry�apital, tmp);
			system("pause");
			system("cls");
			break;
		case '2':
			std::cout << "Enter capital: ";
			std::getline(std::cin, tmp);
			searchCountry(vectorCountry�apital, tmp);
			system("pause");
			system("cls");
			break;
		case '3':
			printVector(vectorCountry�apital);
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}