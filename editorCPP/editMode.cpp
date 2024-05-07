#include <ncurses.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../LZW/compress.h"

class EditMode {
public:
    std::string content;  // Búfer de texto en memoria

    void openEditMode(const std::string& filename) {
        std::string path = "../decompressed_files/" + filename;
        content = readFile(path);

        initscr();              // Start ncurses mode
        raw();                  // Line buffering disabled
        keypad(stdscr, TRUE);   // Enable function keys
        noecho();               // Don't echo() while we do getch

        int ch;
        int row = 0;
        int col = 0;
        printContent(content, row, col);

        while((ch = getch()) != KEY_F(4)) { // F4 key to exit
            switch(ch) {
                case KEY_BACKSPACE:
                case 127:
                    if (col > 0) {
                        mvdelch(row, --col); // Move back one column and delete char
                        content.erase(content.end() - 1);  // Remove last character from content
                    } else if (row > 0) {
                        --row;
                        col = getLineLength(row);
                        move(row, col);
                        content.erase(content.end() - 1);  // Remove newline character
                    }
                    break;
                case '\n':
                    mvaddch(row, col++, ch); // Display newline and move right
                    content += ch;  // Add newline to content
                    row++;
                    col = 0;
                    break;
                default:
                    mvaddch(row, col++, ch); // Display character and move right
                    content += ch;  // Add character to content
                    break;
            }
        }

        saveToFile(path, content);
        endwin(); // End ncurses mode
    }

private:
    std::string readFile(const std::string& path) {
        std::ifstream file(path);
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    void printContent(const std::string& content, int &row, int &col) {
        move(0, 0);
        for (char c : content) {
            if (c == '\n') {
                col = 0;
                row++;
            } else {
                mvaddch(row, col++, c);
            }
        }
    }

    int getLineLength(int row) {
        int length = 0;
        move(row, 0);
        while (inch() != '\n' && inch() != '\0') {
            length++;
            move(row, length);
        }
        return length;
    }

    std::string collectContent() {
        std::stringstream ss;
        char ch;
        for (int y = 0; y < LINES; y++) {
            for (int x = 0; x < COLS; x++) {
                move(y, x);
                ch = static_cast<char>(inch() & A_CHARTEXT);
                ss << ch;
            }
            ss << '\n';
        }
        return ss.str();
    }

    void saveToFile(const std::string& path, const std::string& content) {
    std::ofstream file(path);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for saving changes.\n";
        return;
    }

    file << content;
    file.close();

    compress(path.c_str());
    system(("rm " + path).c_str());
}
};
