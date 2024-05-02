#include <ncurses.h>
#include <string>
#include <vector>

class TextEditor {
public:
    TextEditor() {
        initscr();              // Inicia el modo curses
        raw();                  // Desactiva el buffering de línea
        keypad(stdscr, TRUE);   // Permite la lectura de teclas de función, flechas, etc.
        noecho();               // No muestra los caracteres ingresados
    }

    ~TextEditor() {
        endwin();               // Termina el modo curses
    }

    void run() {
        std::string line;
        int ch;
        while ((ch = getch()) != KEY_F(1)) { // F1 para salir
            switch (ch) {
                case KEY_BACKSPACE:
                case 127: // Manejo del backspace
                    if (!line.empty()) {
                        line.pop_back();
                        int y, x;
                        getyx(stdscr, y, x);
                        move(y, x-1);
                        delch();
                    }
                    break;
                case '\n': // Enter
                    line.clear();
                    printw("\n");
                    break;
                default:
                    line.push_back(ch);
                    printw("%c", ch);
            }
        }
    }
};

int main() {
    TextEditor editor;
    editor.run();
    return 0;
}
