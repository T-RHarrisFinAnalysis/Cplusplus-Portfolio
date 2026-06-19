/*
 * Name: Tim Harris
 * Date: June 3, 2026
 * Project: Fahrenheit to Celsius File Conversion
 * Description:
 * Reads city + Fahrenheit temperatures from a file,
 * converts them to Celsius, and writes results to a new file.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    // Open input file (forces same-directory lookup)
    ifstream inputFile("./FahrenheitTemperature.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open FahrenheitTemperature.txt" << endl;
        cerr << "Make sure the file is in the same folder as the program." << endl;
        return 1;
    }

    // Open output file
    ofstream outputFile("CelsiusTemperature.txt");

    if (!outputFile.is_open()) {
        cerr << "Error: Could not create output file." << endl;
        return 1;
    }

    string city;
    int fahrenheit;
    double celsius;

    // Optional nice formatting header
    outputFile << left << setw(15) << "City"
        << "Celsius" << endl;
    outputFile << "------------------------" << endl;

    // Read, convert, write
    while (inputFile >> city >> fahrenheit) {

        celsius = (fahrenheit - 32) * 5.0 / 9.0;

        outputFile << left << setw(15) << city
            << fixed << setprecision(2)
            << celsius << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Conversion complete. Check CelsiusTemperature.txt" << endl;

    return 0;
}