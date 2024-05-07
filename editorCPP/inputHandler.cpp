#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include "fileManager.cpp"

namespace fs = std::filesystem;

class InputHandler
{
    FileManager filemanager;

public:
    void createFile(const std::string &filename)
    {
        system("mkdir -p ../decompressed_files"); // Crea el directorio si no existe
        std::ofstream file("../decompressed_files/" + filename);
    }

    bool openFile(const std::string &filename, std::string &content)
    {
        std::string path = "compressed_files/" + filename + ".compressed";
        if (fs::exists(path))
        { // Verifica si el archivo existe
            std::ifstream file(path);
            content = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            return true;
        }
        return false;
    }

    void listFiles()
    {
        filemanager.show_compressed_files("../compressed_files");
    }

    void showHelp()
    {
        printf("c: Create file, o: Open file, s: Show files, h: Help, q:Exit\n");
    }
};
