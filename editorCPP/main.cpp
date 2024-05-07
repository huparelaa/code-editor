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
                    editMode.openEditMode(filename);
                    std::cout << "File created.\n";
                    break;
                }
                case 'o': {
                    system("clear");
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
                        std::cout <<"File doesn't exists."<<std::endl;
                    }
                    break;
                }
                case 's':
                    system("clear");
                    inputHandler.listFiles();
                    break;
                case 'h':
                    system("clear");
                    inputHandler.showHelp();
                    break;
                default:
                    std::cout << "Invalid command.\n";
                    inputHandler.showHelp();
                    break;

                inputHandler.showHelp();
                
            }
        }
    }
};

int main() {
    TextEditor editor;
    editor.run();
    return 0;
}
