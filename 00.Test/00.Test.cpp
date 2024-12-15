// 00.matrixRain
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <vector>

constexpr auto WIDTH = 80         ;
constexpr auto HEIGHT = 25         ;
constexpr auto DELAY = 50000       ;
constexpr auto CHARACTERS = "!@#$%^&*()" ;
using namespace std;


char randomChar() {
    
    const char* charset = CHARACTERS;
    return charset[rand() % strlen(charset)];
}

int main() {
    srand(time(0)); 

    initscr();     
    noecho();       
    curs_set(0);    
    start_color();  
    init_pair(1, COLOR_GREEN, COLOR_BLACK); 

    vector<int> drops(WIDTH, 0); 

    while (true) {
        
        clear(); 
        attron(COLOR_PAIR(1)); 

        for (int x = 0; x < WIDTH; ++x) {
            mvaddch(drops[x], x, randomChar()); 
                        
            if (drops[x] >= HEIGHT || rand() % 10 > 8) {
                drops[x] = 0; 
            }
            else {
                drops[x]++;
            }
        }

        attroff(COLOR_PAIR(1)); // Деактивиране на цвета
        refresh();              // Обновяване на екрана
        usleep(DELAY);          // Закъснение за плавна анимация
    }

    endwin(); // Спиране на NCurses
    
    return 0;
}
