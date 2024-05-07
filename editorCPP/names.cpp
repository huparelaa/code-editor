#include <iostream>
#include <filesystem>  

void files(const std::string &a_carpeta)
{
    for (const auto &entry : std::filesystem::directory_iterator(a_carpeta))
    {
        if (entry.is_regular_file())
        {
            std::cout << entry.path().stem() << '\n';
        }
    }
}

int main()
{
    muestra_contenido_de("/mnt/c/Users/andre/OneDrive/Documentos/Semestre-7/SistemasOperativos/code-editor/compressed_files");
    return 0;
}
