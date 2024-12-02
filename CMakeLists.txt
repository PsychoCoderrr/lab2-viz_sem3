cmake_minimum_required(VERSION 3.16)
project(MyProject LANGUAGES CXX)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пути к SDL2
set(SDL2_INCLUDE_DIR /opt/homebrew/Cellar/sdl2/2.30.9/include)
set(SDL2_LIBRARY_DIR /opt/homebrew/Cellar/sdl2/2.30.9/lib)

# Пути к ncurses
set(NCURSES_INCLUDE_DIR /opt/homebrew/include)
set(NCURSES_LIBRARY_DIR /opt/homebrew/lib)

# Укажите исходные файлы
set(SOURCE_FILES
    main.cpp
    # Заголовочные файлы
    Book.h
    ArraySequence.h
    ArrayIterator.h
    BookCardComporator.h
    BubbleSort.h
    Complex.h
    ComplexComparator.h
    DefaultComporator.h
    Generator.h
    HeadSorter.h
    HeapSort.h
    Person.h
    QuickSort.h
    Sequence.h
    tests.h
    # Добавьте остальные файлы здесь
)

# Добавляем исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Указываем, где искать заголовочные файлы
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${NCURSES_INCLUDE_DIR})

# Линкуем библиотеку SDL2
target_link_directories(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARY_DIR})
target_link_directories(${PROJECT_NAME} PRIVATE ${NCURSES_LIBRARY_DIR})

target_link_libraries(${PROJECT_NAME} SDL2 ncurses)
