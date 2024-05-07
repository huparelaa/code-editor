#include <iostream>
#include <string>
#include <filesystem>
#include "inputHandler.cpp"  // Asegúrate de que la ruta sea correcta y accesible

class TextEditor {
    InputHandler inputHandler;
    std::string currentFile;
    std::string content;

public:
    TextEditor() {}

    void run() {
        char ch;
        system("clear");
        inputHandler.showHelp();
        std::cout << "Enter 'q' to exit.\n";
        while (std::cin >> ch && ch != 'q') {  // 'q' para salir
            switch (ch) {
                // print ">" to indicate that the user can enter a command ascii 62
                
                case 'c': {
                    system("clear");
                    std::string filename;
                    std::cout << "Enter new filename: ";
                    std::cin >> filename;
                    inputHandler.createFile(filename);
                    system("clear");
                    std::cout << "File created.\n";
                    break;
                }
                case 'o': {
                    std::string openFilename;
                    std::cout << "Enter filename to open: ";
                    std::cin >> openFilename;
                    if (!inputHandler.openFile(openFilename, content)) {
                        std::cout << "File does not exist.\n";
                    } else {
                        std::cout << "File content:\n" << content << std::endl;
                    }
                    break;
                }
                case 's':
                    inputHandler.listFiles();
                    break;
                case 'h':
                    inputHandler.showHelp();
                    break;
            }
        }
    }
};

int main() {

    TextEditor editor;
    editor.run();
    return 0;
}
