#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

class FileManager
{
public:
    void show_compressed_files(const std::string &a_carpeta)
    {
        std::vector<std::string> nombres_sin_dat;

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

        // Imprimir los nombres sin .compressed.dat
        for (const auto &nombre : nombres_sin_dat)
        {
            std::cout << nombre << '\n';
        }
    }

    bool find_file(const std::string &a_carpeta, const std::string &a_nombre)
    {
        for (const auto &entry : std::filesystem::directory_iterator(a_carpeta))
        {
            if (entry.is_regular_file())
            {
                // Obtener el nombre del archivo
                std::string nombre_archivo = entry.path().filename().string();

                // Eliminar la extensión .compressed.dat
                std::string nombre_sin_dat = nombre_archivo.substr(0, nombre_archivo.find_last_of("."));

                // Verificar si el nombre sin .compressed.dat es igual al nombre buscado
                if (nombre_sin_dat == a_nombre)
                {
                    return true;
                }
            }
        }

        return false;
    }
};