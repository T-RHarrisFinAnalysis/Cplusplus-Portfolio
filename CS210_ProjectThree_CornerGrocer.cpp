/*Name: Tim Harris
Course : CS - 210 
Programming Languages
Project Three - Corner Grocer Item Tracker
This program reads grocery purchase data from a file,
tracks item frequencies, creates a backup file, and
allows users to search and display frequency information
through a menu-driven interface.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>
#include <stdexcept>

class GroceryTracker {
private:
    // Stores grocery items and their purchase frequencies
    std::map<std::string, int> itemFrequency;

public:
    // Load items from input file and count frequencies
    void loadData(const std::string& filename) {
        std::ifstream infile(filename);

        if (!infile) {
            throw std::runtime_error("Input file not found: " + filename);
        }

        std::string item;

        // Read each grocery item and count occurrences
        while (infile >> item) {
            itemFrequency[item]++;
        }

        infile.close();

        // Create backup file automatically
        saveBackup("frequency.dat");
    }

    // Save frequency data to backup file
    void saveBackup(const std::string& backupFile) {
        std::ofstream outfile(backupFile);

        if (!outfile) {
            throw std::runtime_error("Cannot open backup file: " + backupFile);
        }

        // Write item names and frequencies to backup file
        for (const auto& pair : itemFrequency) {
            outfile << pair.first << " " << pair.second << std::endl;
        }

        outfile.close();
    }

    // Return frequency of a specific item
    int getFrequency(const std::string& item) const {
        auto it = itemFrequency.find(item);

        if (it != itemFrequency.end()) {
            return it->second;
        }

        return 0;
    }

    // Display all grocery items and their frequencies
    void printAllFrequencies() const {
        std::cout << "\n=== Item Frequency List ===\n";

        for (const auto& pair : itemFrequency) {
            std::cout << pair.first << " " << pair.second << std::endl;
        }
    }

    // Display histogram using asterisks
    void printHistogram() const {
        std::cout << "\n=== Item Frequency Histogram ===\n";

        for (const auto& pair : itemFrequency) {
            std::cout << pair.first << " ";

            for (int i = 0; i < pair.second; ++i) {
                std::cout << "*";
            }

            std::cout << std::endl;
        }
    }
};

// Get validated menu choice from user
int getMenuChoice() {
    int choice;

    while (true) {
        std::cout << "\n==============================\n";
        std::cout << " Corner Grocer Menu\n";
        std::cout << "==============================\n";
        std::cout << "1. Get frequency of a specific item\n";
        std::cout << "2. Print frequency list of all items\n";
        std::cout << "3. Print histogram of item frequencies\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";

        if (std::cin >> choice && choice >= 1 && choice <= 4) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }

        std::cout << "Invalid input. Please enter a number between 1 and 4.\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Get item name from user
std::string getItemName() {
    std::string item;

    std::cout << "Enter the item name: ";
    std::getline(std::cin, item);

    return item;
}

int main() {
    GroceryTracker tracker;

    try {
        tracker.loadData("CS210_Project_Three_Input_File.txt");
        std::cout << "Data loaded successfully and backup file created.\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error during file operations: "
            << e.what() << std::endl;
        return 1;
    }

    bool running = true;

    // Continue displaying menu until user exits
    while (running) {
        int choice = getMenuChoice();

        switch (choice) {
        case 1: {
            std::string item = getItemName();
            int frequency = tracker.getFrequency(item);

            std::cout << "\n\"" << item
                << "\" appears "
                << frequency
                << " time(s).\n";
            break;
        }

        case 2:
            tracker.printAllFrequencies();
            break;

        case 3:
            tracker.printHistogram();
            break;

        case 4:
            std::cout << "\nExiting program. Goodbye!\n";
            running = false;
            break;
        }
    }

    return 0;
}