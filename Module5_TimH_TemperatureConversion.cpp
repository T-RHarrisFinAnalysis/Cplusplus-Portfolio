/*
CS 210 Module Five Assignment: Fahrenheit to Celsius File Conversion
Author: Tim Harris
Date: May 2026

This program reads city/temperature data from FahrenheitTemperature.txt,
converts each temperature to Celsius, and writes the results to CelsiusTemperature.txt.
*/

#include <iostream>
#include <fstream>   // Needed for file input/output
#include <string>    // Needed for using the string class

using namespace std;

int main() {
    // Declare input and output file stream objects
    ifstream fin;           // Input file stream for reading
    ofstream fout;          // Output file stream for writing

    // Open the input file for reading  
    fin.open("FahrenheitTemperature.txt");

    // Check if the input file opened successfully  
    if (!fin) {
        cout << "Error: Could not open input file.\n";
        return 1;   // Exit with error code  
    }

    // Open the output file for writing  
    fout.open("CelsiusTemperature.txt");
    if (!fout) {
        cout << "Error: Could not create output file.\n";
        fin.close();    // Close input file before exiting  
        return 1;
    }

    string city;
    int tempF;      // Fahrenheit temperature (from file)  
    double tempC;   // Celsius temperature (to calculate)

    // Read each city and temperature from the input file  
    while (fin >> city >> tempF) {
        // Convert Fahrenheit to Celsius using the formula  
        tempC = (tempF - 32) * 5.0 / 9.0;

        // Write city and temperature to the output file  
        fout << city << " " << tempC << endl;
    }

    // Close both files to ensure data is saved and resources are released  
    fin.close();
    fout.close();

    cout << "Conversion complete. Check CelsiusTemperature.txt for results." << endl;

    // AI Usage: AI tools were used to support editing and commenting. All logic/decisions are my own.

    return 0;
}