#include <iostream>
#include <string>
#include <filesystem>
#include "inputHandler.cpp"
#include "../LZW/decompress.h"
#include "editMode.cpp"

class TextEditor {
    InputHandler inputHandler;
    FileManager fileManager;
    EditMode editMode;
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
                    bool found = fileManager.find_file("../compressed_files", openFilename);
                    if (found){
                        std::string fullFilename = openFilename + ".compressed";
                        decompress(fullFilename.c_str());
                        editMode.openEditMode(openFilename);
                        std::cout << "File opened.\n";
                    }else{
                        std::cout <<"File doesn't exists. Pipipipi"<<std::endl;
                    }
                    break;
                }
                case 's':
                    inputHandler.listFiles();
                    break;
                case 'h':
                    inputHandler.showHelp();
                    break;
                default:
                    std::cout << "Invalid command.\n";
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
