#include <SDL2/SDL.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#include <ranges>
#include <string>
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

//void drawMenu(const std::vector<std::string>& options, int highlight) {
//    clear();
//    for (int i = 0; i < options.size(); ++i) {
//        if (i == highlight) {
//            attron(A_REVERSE);
//        }
//        mvprintw(i, 0, options[i].c_str());
//        if (i == highlight) {
//            attroff(A_REVERSE);
//        }
//    }
//    refresh();
//}
//
//int main() {
//    initscr();
//    raw();
//    keypad(stdscr, TRUE);
//    noecho();
//
//    std::vector<std::string> mainMenu = {"BubbleSort", "QuickSort", "HeapSort", "Exit"};
//    std::vector<std::string> bubbleSortMenu = {"Visualization", "AddStat", "GenFileAndSort", "Back"};
//    std::vector<std::string> addStatMenu = {"1000", "10000", "50000", "100000", "200000", "Back"};
//    std::vector<std::string> genFileMenu = {"Title", "Pages", "FName", "SName", "Year", "Back"};
//    std::vector<std::string> sizeMenu = {"1000", "10000", "100000", "Back"};
//
//    int mainChoice = 0;
//    int bubbleSortChoice = 0;
//    int addStatChoice = 0;
//    int genFileChoice = 0;
//    int sizeChoice = 0;
//
//    while (true)
//    {
//        drawMenu(mainMenu, mainChoice);
//        int ch = getch();
//
//        switch (ch)
//        {
//            case KEY_UP:
//                mainChoice = (mainChoice > 0) ? mainChoice - 1 : mainMenu.size() - 1;
//                break;
//            case KEY_DOWN:
//                mainChoice = (mainChoice < mainMenu.size() - 1) ? mainChoice + 1 : 0;
//                break;
//            case 10: // Enter
//                if (mainChoice == 3)
//                {
//                    endwin();
//                    return 0; // Exit
//                }
//
//                while (true)
//                {
//                    if (mainChoice == 0) // BubbleSort
//                    {
//                        drawMenu(bubbleSortMenu, bubbleSortChoice);
//                        ch = getch();
//                        switch (ch)
//                        {
//                            case KEY_UP:
//                                bubbleSortChoice = (bubbleSortChoice > 0) ? bubbleSortChoice - 1 : bubbleSortMenu.size() - 1;
//                                break;
//                            case KEY_DOWN:
//                                bubbleSortChoice = (bubbleSortChoice < bubbleSortMenu.size() - 1) ? bubbleSortChoice + 1 : 0;
//                                break;
//                            case 10: // Enter
//                                if (bubbleSortChoice == 0)
//                                { // Visualization
//                                    bubblesortviztest();
//                                    //getch();
//                                    drawMenu(mainMenu, mainChoice);
//                                    break;
//                                }
//                                else if (bubbleSortChoice == 1) // AddStat
//                                {
//                                    while (true)
//                                    {
//                                        drawMenu(addStatMenu, addStatChoice);
//                                        ch = getch();
//                                        switch (ch)
//                                        {
//                                            case KEY_UP:
//                                                addStatChoice = (addStatChoice > 0) ? addStatChoice - 1 : addStatMenu.size() - 1;
//                                                break;
//                                            case KEY_DOWN:
//                                                addStatChoice = (addStatChoice < addStatMenu.size() - 1) ? addStatChoice + 1 : 0;
//                                                break;
//                                            case 10: // Enter
//                                                if (addStatChoice == addStatMenu.size() - 1) {
//                                                    goto backToBubbleSort;
//                                                }
//                                                else {
//                                                    statBubbleSort(stoi(addStatMenu[addStatChoice])); // Call func2 with size
//                                                    getch();
//                                                }
//                                                break;
//                                        }
//                                    }
//                                }
//                                else if (bubbleSortChoice == 2) // GenFileAndSort
//                                {
//                                    while (true)
//                                    {
//                                        drawMenu(genFileMenu, genFileChoice);
//                                        ch = getch();
//                                        switch (ch)
//                                        {
//                                            case KEY_UP:
//                                                genFileChoice = (genFileChoice > 0) ? genFileChoice - 1 : genFileMenu.size() - 1;
//                                                break;
//                                            case KEY_DOWN:
//                                                genFileChoice = (genFileChoice < genFileMenu.size() - 1) ? genFileChoice + 1 : 0;
//                                                break;
//                                            case 10: // Enter
//                                                if (genFileChoice == genFileMenu.size() - 1)
//                                                {
//                                                    goto backToBubbleSort;
//                                                }
//                                                else
//                                                {
//                                                    while (true)
//                                                    {
//                                                        drawMenu(sizeMenu, sizeChoice);
//                                                        ch = getch();
//                                                        switch (ch)
//                                                        {
//                                                            case KEY_UP:
//                                                                sizeChoice = (sizeChoice > 0) ? sizeChoice - 1 : sizeMenu.size() - 1;
//                                                                break;
//                                                            case KEY_DOWN:
//                                                                sizeChoice = (sizeChoice < sizeMenu.size() - 1) ? sizeChoice + 1 : 0;
//                                                                break;
//                                                            case 10: // Enter
//                                                                if (sizeChoice == sizeMenu.size() - 1) {
//                                                                    goto backToGenFile;
//                                                                }
//                                                                else
//                                                                {
//                                                                    testBubbleSortPages(stoi(sizeMenu[sizeChoice])); // Call func3 with parameter
//                                                                    getch();
//                                                                }
//                                                                break;
//                                                        }
//                                                    }
//                                                }
//                                                break;
//                                        }
//                                    }
//                                    backToGenFile:
//                                    break;
//                                }
//                                break;
//                        }
//                    }
//
//                    backToBubbleSort:
//                    break;
//                }
//                break;
//        }
//    }
//
//    endwin();
//    return 0;
//}















//void drawMenu(const std::vector<std::string>& options, int highlight) {
//    clear();
//    for (int i = 0; i < options.size(); ++i) {
//        if (i == highlight) {
//            attron(A_REVERSE);  // Подсвечиваем выбранную строку
//        }
//        mvprintw(i, 0, options[i].c_str());
//        if (i == highlight) {
//            attroff(A_REVERSE); // Снимаем подсветку
//        }
//    }
//    refresh();
//}
//
//int main() {
//    initscr();
//    raw();
//    keypad(stdscr, TRUE);
//    noecho();
//
//    // Меню
//    std::vector<std::string> mainMenu = {"BubbleSort", "QuickSort", "HeapSort", "Exit"};
//    std::vector<std::string> bubbleSortMenu = {"Visualization", "AddStat", "GenFileAndSort"};
//    std::vector<std::string> addStatMenu = {"1000", "10000", "50000", "100000", "200000", "Back"};
//    std::vector<std::string> genFileMenu = {"Title", "Pages", "FName", "SName", "Year", "Back"};
//    std::vector<std::string> sizeMenu = {"1000", "10000", "100000", "Back"};
//
//    // Индексы выбранных элементов
//    int mainChoice = 0;
//    int bubbleSortChoice = 0;
//    int addStatChoice = 0;
//    int genFileChoice = 0;
//    int sizeChoice = 0;
//
//    while (true) {
//        drawMenu(mainMenu, mainChoice); // Главное меню
//        int ch = getch();
//
//        switch (ch) {
//            case KEY_UP:
//                mainChoice = (mainChoice > 0) ? mainChoice - 1 : mainMenu.size() - 1;
//                break;
//            case KEY_DOWN:
//                mainChoice = (mainChoice < mainMenu.size() - 1) ? mainChoice + 1 : 0;
//                break;
//            case 10: // Enter
//                if (mainChoice == 3)
//                { // Exit
//                    endwin();
//                    return 0;
//                }
//
//                // Выбираем, в какое подменю перейти
//                while (true)
//                {
//                    if (mainChoice == 0) { // BubbleSort
//                        while (true)
//                        {
//                            drawMenu(bubbleSortMenu, bubbleSortChoice);
//                            ch = getch();
//                            switch (ch)
//                            {
//                                case KEY_UP:
//                                    bubbleSortChoice = (bubbleSortChoice > 0) ? bubbleSortChoice - 1 : bubbleSortMenu.size() - 1;
//                                    break;
//                                case KEY_DOWN:
//                                    bubbleSortChoice = (bubbleSortChoice < bubbleSortMenu.size() - 1) ? bubbleSortChoice + 1 : 0;
//                                    break;
//                                case 10: // Enter
//                                    if (bubbleSortChoice == 0) // Visualization
//                                    {
//                                        bubblesortviztest();
//                                    }
//                                    else if (bubbleSortChoice == 1)
//                                    { // AddStat
//                                        while (true) {
//                                            drawMenu(addStatMenu, addStatChoice);
//                                            ch = getch();
//                                            switch (ch)
//                                            {
//                                                case KEY_UP:
//                                                    addStatChoice = (addStatChoice > 0) ? addStatChoice - 1 : addStatMenu.size() - 1;
//                                                    break;
//                                                case KEY_DOWN:
//                                                    addStatChoice = (addStatChoice < addStatMenu.size() - 1) ? addStatChoice + 1 : 0;
//                                                    break;
//                                                case 10: // Enter
//                                                    if (addStatChoice == addStatMenu.size() - 1)
//                                                    {
//                                                        goto backToBubbleSort; // Вернуться к BubbleSort
//                                                    } else
//                                                    {
//                                                        statBubbleSort(stoi(addStatMenu[addStatChoice]));
//                                                        getch(); // Ожидаем нажатие для продолжения
//                                                    }
//                                                    break;
//                                            }
//                                        }
//                                    }
//                                    else if (bubbleSortChoice == 2) // GenFileAndSort
//                                    {
//                                        while (true)
//                                        {
//                                            drawMenu(genFileMenu, genFileChoice);
//                                            ch = getch();
//                                            switch (ch)
//                                            {
//                                                case KEY_UP:
//                                                    genFileChoice = (genFileChoice > 0) ? genFileChoice - 1 : genFileMenu.size() - 1;
//                                                    break;
//                                                case KEY_DOWN:
//                                                    genFileChoice = (genFileChoice < genFileMenu.size() - 1) ? genFileChoice + 1 : 0;
//                                                    break;
//                                                case 10: // Enter
//                                                    if (genFileChoice == genFileMenu.size() - 1)
//                                                    {
//                                                        goto backToBubbleSort; // Вернуться к BubbleSort
//                                                    } else {
//                                                        while (true)
//                                                        {
//                                                            drawMenu(sizeMenu, sizeChoice);
//                                                            ch = getch();
//                                                            switch (ch)
//                                                            {
//                                                                case KEY_UP:
//                                                                    sizeChoice = (sizeChoice > 0) ? sizeChoice - 1 : sizeMenu.size() - 1;
//                                                                    break;
//                                                                case KEY_DOWN:
//                                                                    sizeChoice = (sizeChoice < sizeMenu.size() - 1) ? sizeChoice + 1 : 0;
//                                                                    break;
//                                                                case 10: // Enter
//                                                                    if (sizeChoice == sizeMenu.size() - 1)
//                                                                    {
//                                                                        goto backToGenFile; // Вернуться к GenFile
//                                                                    }
//                                                                    else
//                                                                    {
//                                                                        testBubbleSortPages(stoi(sizeMenu[sizeChoice])); // Ваши функции
//                                                                        getch(); // Ожидаем нажатие для продолжения
//                                                                    }
//                                                                    break;
//                                                            }
//                                                        }
//                                                    }
//                                                    break;
//                                            }
//                                        }
//                                        backToGenFile:
//                                        break;
//                                    }
//                                    break;
//                            }
//                        }
//                    }
//
//                    backToBubbleSort:
//                    break;
//                }
//                break;
//        }
//    }
//
//    endwin();
//    return 0;
//}

void drawMenu(const std::vector<std::string>& options, int highlight) {
    clear();
    for (int i = 0; i < options.size(); ++i) {
        if (i == highlight) {
            attron(A_REVERSE);  // Подсвечиваем выбранную строку
        }
        mvprintw(i, 0, options[i].c_str());
        if (i == highlight) {
            attroff(A_REVERSE); // Снимаем подсветку
        }
    }
    refresh();
}

int main() {
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    // Меню
    std::vector<std::string> mainMenu = {"BubbleSort", "QuickSort", "HeapSort", "Exit"};
    std::vector<std::string> bubbleSortMenu = {"Visualization", "AddStat", "GenFileAndSort"};
    std::vector<std::string> quickSortMenu = {"Visualization", "AddStat", "GenFileAndSort"};
    std::vector<std::string> heapSortMenu = {"Visualization", "AddStat", "GenFileAndSort"};
    std::vector<std::string> addStatMenu = {"1000", "10000", "50000", "100000", "200000", "Back"};
    std::vector<std::string> addStatMenuQuick = {"10000", "100000", "500000", "1000000", "5000000", "Back"};
    std::vector<std::string> addStatMenuHeap = {"10000", "100000", "500000", "1000000", "5000000", "Back"};
    std::vector<std::string> genFileMenu = {"Title", "Pages", "FName", "SName", "Year", "Back"};
    std::vector<std::string> sizeMenu = {"1000", "10000", "100000", "Back"};

    // Индексы выбранных элементов
    int mainChoice = 0;
    int bubbleSortChoice = 0;
    int quickSortChoice = 0;
    int heapSortChoice = 0;
    int addStatChoice = 0;
    int genFileChoice = 0;
    int sizeChoice = 0;

    while (true) {
        drawMenu(mainMenu, mainChoice); // Главное меню
        int ch = getch();

        switch (ch) {
            case KEY_UP:
                mainChoice = (mainChoice > 0) ? mainChoice - 1 : mainMenu.size() - 1;
                break;
            case KEY_DOWN:
                mainChoice = (mainChoice < mainMenu.size() - 1) ? mainChoice + 1 : 0;
                break;
            case 10: // Enter
                if (mainChoice == 3) { // Exit
                    endwin();
                    return 0;
                }

                // Обрабатываем кнопки сортировок
                while (true)
                {
                    if (mainChoice == 0) { // BubbleSort
                        while (true) {
                            drawMenu(bubbleSortMenu, bubbleSortChoice);
                            ch = getch();
                            switch (ch) {
                                case KEY_UP:
                                    bubbleSortChoice = (bubbleSortChoice > 0) ? bubbleSortChoice - 1 : bubbleSortMenu.size() - 1;
                                    break;
                                case KEY_DOWN:
                                    bubbleSortChoice = (bubbleSortChoice < bubbleSortMenu.size() - 1) ? bubbleSortChoice + 1 : 0;
                                    break;
                                case 10: // Enter
                                    if (bubbleSortChoice == 0) { // Visualization
                                        bubblesortviztest();
                                    } else if (bubbleSortChoice == 1) { // AddStat
                                        while (true) {
                                            drawMenu(addStatMenu, addStatChoice);
                                            ch = getch();
                                            switch (ch) {
                                                case KEY_UP:
                                                    addStatChoice = (addStatChoice > 0) ? addStatChoice - 1 : addStatMenu.size() - 1;
                                                    break;
                                                case KEY_DOWN:
                                                    addStatChoice = (addStatChoice < addStatMenu.size() - 1) ? addStatChoice + 1 : 0;
                                                    break;
                                                case 10: // Enter
                                                    if (addStatChoice == addStatMenu.size() - 1) {
                                                        goto backToBubbleSort;
                                                    } else {
                                                        statBubbleSort(stoi(addStatMenu[addStatChoice]));
                                                        getch();
                                                    }
                                                    break;
                                            }
                                        }
                                    }
                                    else if (bubbleSortChoice == 2) // GenFileAndSort
                                    {
                                        while (true) {
                                            drawMenu(genFileMenu, genFileChoice);
                                            ch = getch();
                                            switch (ch) {
                                                case KEY_UP:
                                                    genFileChoice = (genFileChoice > 0) ? genFileChoice - 1 : genFileMenu.size() - 1;
                                                    break;
                                                case KEY_DOWN:
                                                    genFileChoice = (genFileChoice < genFileMenu.size() - 1) ? genFileChoice + 1 : 0;
                                                    break;
                                                case 10: // Enter
                                                    std::string selectedOption = genFileMenu[genFileChoice];
                                                    if (genFileChoice == genFileMenu.size() - 1) {
                                                        goto backToBubbleSort;
                                                    }
                                                    else {
                                                        while (true) {
                                                            drawMenu(sizeMenu, sizeChoice);
                                                            ch = getch();
                                                            switch (ch) {
                                                                case KEY_UP:
                                                                    sizeChoice = (sizeChoice > 0) ? sizeChoice - 1 : sizeMenu.size() - 1;
                                                                    break;
                                                                case KEY_DOWN:
                                                                    sizeChoice = (sizeChoice < sizeMenu.size() - 1) ? sizeChoice + 1 : 0;
                                                                    break;
                                                                case 10: // Enter
                                                                    if (sizeChoice == sizeMenu.size() - 1) {
                                                                        goto backToGenFileBubble;
                                                                    }
                                                                    else {
                                                                        int selectedSize = stoi(sizeMenu[sizeChoice]);
                                                                        if (selectedOption == "Title") {
                                                                            testBubbleSortTitle(selectedSize); // Функция для Title
                                                                        } else if (selectedOption == "Pages") {
                                                                            testBubbleSortPages(selectedSize); // Функция для Pages
                                                                        } else if (selectedOption == "FName") {
                                                                            testBubbleSortFName(selectedSize); // Функция для FName
                                                                        } else if (selectedOption == "SName") {
                                                                            testBubbleSortSName(selectedSize); // Функция для SName
                                                                        } else if (selectedOption == "Year") {
                                                                            testBubbleSortYear(selectedSize); // Функция для Year
                                                                        }
                                                                        getch();
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                    }
                                                    break;
                                            }
                                        }
                                        backToGenFileBubble:
                                        break;
                                    }
                                    break;
                            }
                        }
                    }

                    if (mainChoice == 1) { // QuickSort
                        while (true) {
                            drawMenu(quickSortMenu, quickSortChoice);
                            ch = getch();
                            switch (ch) {
                                case KEY_UP:
                                    quickSortChoice = (quickSortChoice > 0) ? quickSortChoice - 1 : quickSortMenu.size() - 1;
                                    break;
                                case KEY_DOWN:
                                    quickSortChoice = (quickSortChoice < quickSortMenu.size() - 1) ? quickSortChoice + 1 : 0;
                                    break;
                                case 10: // Enter
                                    if (quickSortChoice == 0) { // Visualization
                                        quicksortviztest();
                                    } else if (quickSortChoice == 1) { // AddStat
                                        while (true) {
                                            drawMenu(addStatMenuQuick, addStatChoice);
                                            ch = getch();
                                            switch (ch) {
                                                case KEY_UP:
                                                    addStatChoice = (addStatChoice > 0) ? addStatChoice - 1 : addStatMenuQuick.size() - 1;
                                                    break;
                                                case KEY_DOWN:
                                                    addStatChoice = (addStatChoice < addStatMenuQuick.size() - 1) ? addStatChoice + 1 : 0;
                                                    break;
                                                case 10: // Enter
                                                    if (addStatChoice == addStatMenuQuick.size() - 1) {
                                                        goto backToQuickSort;
                                                    } else {
                                                        statQuickSort(stoi(addStatMenuQuick[addStatChoice]));
                                                        getch();
                                                    }
                                                    break;
                                            }
                                        }
                                    } else if (quickSortChoice == 2) { // GenFileAndSort
                                        while (true) {
                                            drawMenu(genFileMenu, genFileChoice);
                                            ch = getch();
                                            switch (ch) {
                                                case KEY_UP:
                                                    genFileChoice = (genFileChoice > 0) ? genFileChoice - 1 : genFileMenu.size() - 1;
                                                    break;
                                                case KEY_DOWN:
                                                    genFileChoice = (genFileChoice < genFileMenu.size() - 1) ? genFileChoice + 1 : 0;
                                                    break;
                                                case 10: // Enter
                                                    if (genFileChoice == genFileMenu.size() - 1) {
                                                        goto backToQuickSort;
                                                    } else {
                                                        while (true) {
                                                            drawMenu(sizeMenu, sizeChoice);
                                                            ch = getch();
                                                            switch (ch) {
                                                                case KEY_UP:
                                                                    sizeChoice = (sizeChoice > 0) ? sizeChoice - 1 : sizeMenu.size() - 1;
                                                                    break;
                                                                case KEY_DOWN:
                                                                    sizeChoice = (sizeChoice < sizeMenu.size() - 1) ? sizeChoice + 1 : 0;
                                                                    break;
                                                                case 10: // Enter
                                                                    if (sizeChoice == sizeMenu.size() - 1) {
                                                                        goto backToGenFileQuick;
                                                                    } else {
                                                                        testQuickSortPages(stoi(sizeMenu[sizeChoice]));
                                                                        getch();
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                    }
                                                    break;
                                            }
                                        }
                                        backToGenFileQuick:
                                        break;
                                    }
                                    break;
                            }
                        }
                    }

                    // Аналогично для HeapSort
                    if (mainChoice == 2) { // HeapSort
                        while (true) {
                            drawMenu(heapSortMenu, heapSortChoice);
                            ch = getch();
                            switch (ch) {
                                case KEY_UP:
                                    heapSortChoice = (heapSortChoice > 0) ? heapSortChoice - 1 : heapSortMenu.size() - 1;
                                    break;
                                case KEY_DOWN:
                                    heapSortChoice = (heapSortChoice < heapSortMenu.size() - 1) ? heapSortChoice + 1 : 0;
                                    break;
                                case 10: // Enter
                                    if (heapSortChoice == 0) { // Visualization
                                        heapsortviztest();
                                    } else if (heapSortChoice == 1) { // AddStat
                                        while (true) {
                                            drawMenu(addStatMenuHeap, addStatChoice);
                                            ch = getch();
                                            switch (ch) {
                                                case KEY_UP:
                                                    addStatChoice = (addStatChoice > 0) ? addStatChoice - 1 : addStatMenuHeap.size() - 1;
                                                    break;
                                                case KEY_DOWN:
                                                    addStatChoice = (addStatChoice < addStatMenuHeap.size() - 1) ? addStatChoice + 1 : 0;
                                                    break;
                                                case 10: // Enter
                                                    if (addStatChoice == addStatMenuHeap.size() - 1) {
                                                        goto backToHeapSort;
                                                    } else {
                                                        statHeapSort(stoi(addStatMenuHeap[addStatChoice]));
                                                        getch();
                                                    }
                                                    break;
                                            }
                                        }
                                    } else if (heapSortChoice == 2) { // GenFileAndSort
                                        while (true) {
                                            drawMenu(genFileMenu, genFileChoice);
                                            ch = getch();
                                            switch (ch) {
                                                case KEY_UP:
                                                    genFileChoice = (genFileChoice > 0) ? genFileChoice - 1 : genFileMenu.size() - 1;
                                                    break;
                                                case KEY_DOWN:
                                                    genFileChoice = (genFileChoice < genFileMenu.size() - 1) ? genFileChoice + 1 : 0;
                                                    break;
                                                case 10: // Enter
                                                    if (genFileChoice == genFileMenu.size() - 1) {
                                                        goto backToHeapSort;
                                                    } else {
                                                        while (true) {
                                                            drawMenu(sizeMenu, sizeChoice);
                                                            ch = getch();
                                                            switch (ch) {
                                                                case KEY_UP:
                                                                    sizeChoice = (sizeChoice > 0) ? sizeChoice - 1 : sizeMenu.size() - 1;
                                                                    break;
                                                                case KEY_DOWN:
                                                                    sizeChoice = (sizeChoice < sizeMenu.size() - 1) ? sizeChoice + 1 : 0;
                                                                    break;
                                                                case 10: // Enter
                                                                    if (sizeChoice == sizeMenu.size() - 1) {
                                                                        goto backToGenFileHeap;
                                                                    } else {
                                                                        testHeapSortPages(stoi(sizeMenu[sizeChoice]));
                                                                        getch();
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                    }
                                                    break;
                                            }
                                        }
                                        backToGenFileHeap:
                                        break;
                                    }
                                    break;
                            }
                        }
                        backToHeapSort:
                        break;
                    }
                    backToBubbleSort:
                    backToQuickSort:
                    break;
                }
                break;
        }
    }

    endwin();
    return 0;
}
