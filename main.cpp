#include <SDL2/SDL.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#include <ranges>

#include <time.h>
#include <fstream>


//#include <mysql_driver.h>  // Основной драйвер
//#include <mysql_connection.h>  // Объект подключения
//#include <cppconn/statement.h>  // Для выполнения SQL-запросов
//#include <cppconn/prepared_statement.h>  // Для параметризованных запросов


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

//void draw_menu(int highlight) {
//    const char *choices[] = { "Bubble Sort", "Merge Sort", "Insertion Sort" };
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
//                if (highlight < 2)
//                    highlight++;
//                break;
//            case 10:  // Нажатие Enter
//                choice = highlight;
//                if (choice == 0) {
//                    clear();
//                    bubblesortviztest();
//                } else if (choice == 1) {
//                    clear();
//                    quicksortviztest();
//                } else if (choice == 2) {
//                    clear();
//                    heapsortviztest();
//                }
//                draw_menu(highlight);  // После завершения сортировки возвращаемся в меню
//                break;
//        }
//    }
//
//    endwin();  // Завершаем работу с ncurses
//    return 0;
//}

//void insert_sorting_result(const std::string& sortType, int arraySize, double executionTime) {
//    try {
//        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
//        std::unique_ptr<sql::Connection> conn(
//            driver->connect("tcp://127.0.0.1:3306", "root", "your_password")
//        );
//        conn->setSchema("sorting_db");
//
//        std::unique_ptr<sql::PreparedStatement> pstmt(
//            conn->prepareStatement("INSERT INTO sorting_results (sort_type, array_size, execution_time) VALUES (?, ?, ?)")
//        );
//
//        pstmt->setString(1, sortType);
//        pstmt->setInt(2, arraySize);
//        pstmt->setDouble(3, executionTime);
//        pstmt->executeUpdate();
//
//        std::cout << "Data inserted successfully." << std::endl;
//    } catch (sql::SQLException& e) {
//        std::cerr << "Error: " << e.what() << std::endl;
//    }
//}

#include <mysqlx/xdevapi.h>

int main() {
    try {
        // Создание сессии
        mysqlx::Session session("localhost", 33060, "root", "1234");

        // Подключение к схеме (базе данных)
        mysqlx::Schema schema = session.getSchema("sorting_db");

        // Доступ к таблице
        mysqlx::Table table = schema.getTable("sorting_results");

        // Вставка данных
        table.insert("sort_type", "array_size", "execution_time")
            .values("2", 1000, 0.023)
            .execute();

        std::cout << "Data inserted successfully!" << std::endl;
    } catch (const mysqlx::Error &err) {
        std::cerr << "Error: " << err.what() << std::endl;
    } catch (std::exception &ex) {
        std::cerr << "STD Exception: " << ex.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception caught" << std::endl;
    }

    return 0;
}
