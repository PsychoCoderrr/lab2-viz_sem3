#include <SDL2/SDL.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#include <ranges>

#include <time.h>
#include <fstream>

#include "tests.h"
#include "ArrayIterator.h"
#include "ArraySequence.h"
//#include "ComplexComparator.h"
#include "HeadSorter.h"
//#include "BubbleSort.h"
#include "DefaultComporator.h"
#include "QuickSort.h"
//#include "HeapSort.h"
#include "Book.h"
#include "Generator.h"
#include "BookCardComporator.h"


#include <ncurses.h>

//void draw_menu(int highlight) {
//    const char *choices[] = { "Option 1", "Option 2" };
//    int num_choices = sizeof(choices) / sizeof(char *);
//
//    clear();  // Очищаем экран
//
//    for (int i = 0; i < num_choices; i++) {
//        if (i == highlight) {
//            attron(A_REVERSE);  // Выделяем активный элемент
//            mvprintw(i, 0, choices[i]);
//            attroff(A_REVERSE); // Снимаем выделение
//        } else {
//            mvprintw(i, 0, choices[i]);
//        }
//    }
//    refresh();  // Обновляем экран
//}
//
//int main() {
//    // Инициализация ncurses
//    initscr();
//    raw();                    // Отключаем буферизацию
//    keypad(stdscr, TRUE);     // Включаем поддержку стрелок
//    noecho();                 // Отключаем вывод вводимых символов
//    
//    int highlight = 0;  // Индекс выбранного элемента
//    int choice = 0;     // Храним выбор пользователя
//    int c;
//    
//    // Главный цикл
//    while (1) {
//        draw_menu(highlight);
//        c = getch();  // Получаем символ
//        
//        switch (c) {
//            case KEY_UP:
//                if (highlight > 0)
//                    highlight--;
//                break;
//            case KEY_DOWN:
//                if (highlight < 1)
//                    highlight++;
//                break;
//            case 10:  // Нажатие Enter
//                choice = highlight;
//                if (choice == 0 || choice == 1) {
//                    clear();
//                    //printw("Hello, World!\n");  // Печатаем сообщение
//                    bubblesortviztest();
//                    refresh();
//                    getch();  // Ожидаем клавишу перед выходом
//                    return 0;
//                }
//                break;
//        }
//    }
//    
//    //endwin();  // Завершаем работу с ncurses
//    return 0;
//}

void draw_menu(int highlight) {
    const char *choices[] = { "Bubble Sort", "Merge Sort", "Insertion Sort" };
    int num_choices = sizeof(choices) / sizeof(char *);

    clear();  // Очищаем экран

    for (int i = 0; i < num_choices; i++) {
        if (i == highlight) {
            attron(A_REVERSE);  // Выделяем активный элемент
            mvprintw(i, 0, choices[i]);
            attroff(A_REVERSE); // Снимаем выделение
        } else {
            mvprintw(i, 0, choices[i]);
        }
    }
    refresh();  // Обновляем экран
}

int main() {
    // Инициализация ncurses
    initscr();
    raw();                    // Отключаем буферизацию
    keypad(stdscr, TRUE);     // Включаем поддержку стрелок
    noecho();                 // Отключаем вывод вводимых символов

    int highlight = 0;  // Индекс выбранного элемента
    int choice = 0;     // Храним выбор пользователя
    int c;

    // Главный цикл
    while (1) {
        draw_menu(highlight);
        c = getch();  // Получаем символ

        switch (c) {
            case KEY_UP:
                if (highlight > 0)
                    highlight--;
                break;
            case KEY_DOWN:
                if (highlight < 2)
                    highlight++;
                break;
            case 10:  // Нажатие Enter
                choice = highlight;
                if (choice == 0) {
                    clear();
                    bubblesortviztest();
                } else if (choice == 1) {
                    clear();
                    quicksortviztest();
                } else if (choice == 2) {
                    clear();
                    heapsortviztest();
                }
                draw_menu(highlight);  // После завершения сортировки возвращаемся в меню
                break;
        }
    }

    endwin();  // Завершаем работу с ncurses
    return 0;
}
