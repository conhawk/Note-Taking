#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Note {
    std::string title;
    std::string content;
};

std::vector<Note> notes;

void displayMenu() {
    std::cout << "Note-Taking Application\n";
    std::cout << "1. Create a new note\n";
    std::cout << "2. View existing notes\n";
    std::cout << "3. Save notes to file\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void createNote() {
    Note newNote;
    std::cout << "Enter the title of the note: ";
    std::cin.ignore(); // Ignore any leftover characters from previous input
    std::getline(std::cin, newNote.title);
    std::cout << "Enter the content of the note (type 'end' in a new line to finish):\n";

    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line == "end") break;
        newNote.content += line + "\n";
    }

    notes.push_back(newNote);
    std::cout << "Note created successfully!\n";
}

void viewNotes() {
    if (notes.empty()) {
        std::cout << "No notes found.\n";
        return;
    }

    for (const auto& note : notes) {
        std::cout << "Title: " << note.title << '\n';
        std::cout << "Content:\n" << note.content << '\n';
        std::cout << "----------------------\n";
    }
}

void saveNotesToFile(const std::string& filename) {
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cerr << "Error opening the file for writing.\n";
        return;
    }

    for (const auto& note : notes) {
        outFile << "Title: " << note.title << '\n';
        outFile << "Content:\n" << note.content << '\n';
        outFile << "----------------------\n";
    }

    outFile.close();
    std::cout << "Notes saved to " << filename << " successfully!\n";
}

int main() {
    int choice;
    const std::string filename = "notes.txt";

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            createNote();
            break;
        case 2:
            viewNotes();
            break;
        case 3:
            saveNotesToFile(filename);
            break;
        case 4:
            std::cout << "Exiting the application. Goodbye!\n";
            return 0;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
