#include <iostream>
#include <filesystem>
#include <vector>  // Para usar std::vector
#include <string>

void files(const std::string &a_carpeta)
{
    std::vector<std::string> nombres_sin_dat; // Vector para almacenar nombres sin .dat

    for (const auto &entry : std::filesystem::directory_iterator(a_carpeta))
    {
        if (entry.is_regular_file())
        {
            // Obtener el nombre del archivo
            std::string nombre_archivo = entry.path().filename().string();
            
            // Eliminar la extensión .dat
            std::string nombre_sin_dat = nombre_archivo.substr(0, nombre_archivo.find_last_of("."));

            // Agregar el nombre sin .dat al vector
            nombres_sin_dat.push_back(nombre_sin_dat);
        }
    }

    // Imprimir los nombres sin .dat
    for (const auto &nombre : nombres_sin_dat)
    {
        std::cout << nombre << '\n';
    }
}

int main()
{
    files("/mnt/c/Users/andre/OneDrive/Documentos/Semestre-7/SistemasOperativos/code-editor/compressed_files");
    return 0;
}
