#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Diary {
private:
    std::string filename;

public:
    Diary(const std::string& file) : filename(file) {}

    void writeEntry(const std::string& entry) {
        std::ofstream outFile(filename, std::ios::app);
        if (outFile) {
            outFile << entry << std::endl;
        }
    }

    void readEntries() {
        std::ifstream inFile(filename);
        std::string line;
        while (getline(inFile, line)) {
            std::cout << line << std::endl;
        }
    }

    void deleteEntry(int entryNumber) {
        std::ifstream inFile(filename);
        std::vector<std::string> entries;
        std::string line;

        while (getline(inFile, line)) {
            entries.push_back(line);
        }

        if (entryNumber >= 1 && entryNumber <= entries.size()) {
            entries.erase(entries.begin() + entryNumber - 1);
        }

        std::ofstream outFile(filename);
        for (const auto& entry : entries) {
            outFile << entry << std::endl;
        }
    }

    void editEntry(int entryNumber, const std::string& newEntry) {
        std::ifstream inFile(filename);
        std::vector<std::string> entries;
        std::string line;

        while (getline(inFile, line)) {
            entries.push_back(line);
        }

        if (entryNumber >= 1 && entryNumber <= entries.size()) {
            entries[entryNumber - 1] = newEntry;
        }

        std::ofstream outFile(filename);
        for (const auto& entry : entries) {
            outFile << entry << std::endl;
        }
    }
};

int main() {
    Diary diary("diary.txt");
    int choice;
    do {
        std::cout << "\n1. Write Entry\n2. Read Entries\n3. Edit Entry\n4. Delete Entry\n5. Exit\n";
        std::cout << "Choose an option: ";
        
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string entry;
            std::cout << "Enter your diary entry: ";
            std::getline(std::cin, entry);
            diary.writeEntry(entry);
        } else if (choice == 2) {
            diary.readEntries();
        } else if (choice == 3) {
            int entryNumber;
            std::string newEntry;
            std::cout << "Enter the entry number to edit: ";
            std::cin >> entryNumber;
            std::cin.ignore();
            std::cout << "Enter the new entry: ";
            std::getline(std::cin, newEntry);
            diary.editEntry(entryNumber, newEntry);
        } else if (choice == 4) {
            int entryNumber;
            std::cout << "Enter the entry number to delete: ";
            std::cin >> entryNumber;
            diary.deleteEntry(entryNumber);
        }
    } while (choice != 5);
    
    return 0;
}
