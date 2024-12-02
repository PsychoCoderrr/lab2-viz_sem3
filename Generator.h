#pragma once
#include <fstream>
#include <ctime>
#include <random>
#include "ArraySequence.h"
#include "Book.h"
template <typename T>
class ArraySequence;

std::string FirstNameList[20] = {
    "Ivan", "Andrei", "Dmitri", "Alexei", "Nikolai",
    "Sergei", "Mikhail", "Pavel", "Vladislav", "Oleg",
    "Yaroslav", "Roman", "Artem", "Viktor", "Boris",
    "Maxim", "Konstantin", "Gennady", "Leonid", "Stanislav"};

std::string SecondNameList[20] = {
    "Ivanov", "Petrov", "Sidorov", "Fedorov", "Kuznetsov",
    "Popov", "Smirnov", "Orlov", "Makarov", "Lebedev",
    "Egorov", "Morozov", "Volkov", "Novikov", "Pavlov",
    "Karpov", "Yakovlev", "Zaitsev", "Chernov", "Kalinin"
};

std::string TitleNameList[] = {
    "Vremya pervykh", "Iskusstvo voiny", "Zov predkov", "Kapitanskaya dochka", "Tikhiy Don",
    "Prestuplenie i nakazanie", "Anna Karenina", "Master i Margarita", "Deti kapitana Granta", "Ocherednoy pervy klas",
    "Zemlya lyudey", "Tayna tretey planety", "Serebryanoye ozero", "Besy", "Posledniy chelovek",
    "Put do zvyozd", "Tolstoy: Zhizn i vremya", "Metamorfozy", "Domovoy", "Gore ot uma",
    "Belaya gvardiya", "Na dnye", "Dostoevsky: Sudba i tvorchestvo", "Tolko ty", "Pyat zvyozd",
    "Pod znakom Vody", "Khroniki budushchego", "Rasskazy o prirode", "Noch svobody", "Severny veter",
    "Zhemchuzhnoe ozero", "Posledniy geroy", "Svet vo t'me", "Mgnoveniya vechnosti", "Doroga v nikuda",
    "Proshchay oruzhiye", "Poezd na Yumu", "Gravitatsiya", "Polyarnaya zvezda", "Na krae zemli",
    "Vokzal mechty", "Zvezdnyy pilot", "Plamya i led", "Iskry budushchego", "Podvodnaya odisseya",
    "Tayna Karpat", "Mir v teni", "Poslednyaya zvezda", "Labirinty razuma", "Piknyk na obochine",
    "Zvyozdnyy rubikon", "Na beregu vechnosti", "Vremennaya petlya", "Zateryanny mir", "Vybor cheloveka",
    "Den strashnogo suda", "Kogda goryat mosty", "Tayna glubiny", "Legendy severa"
};

void Generator(std::string& name, int count)
{
    std::ofstream outFile(name, std::ios::out);
    
    if (!outFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }
    
    std::mt19937 generator(static_cast<unsigned int>(std::time(nullptr)));
    
    std::string title, authorSecondName, authorFirstName, ISBN;
    int pages, YearPublish;
    
    outFile << "ISBN,title,authorSecondName,authorFirstName,pages,YearPublish\n";
    
    std::uniform_int_distribution<int> dist1(1000000, 9999999);
    std::uniform_int_distribution<int> dist2(50, 2000);
    std::uniform_int_distribution<int> dist3(1800, 2024);
    std::uniform_int_distribution<int> distFirstName(0, 19);
    std::uniform_int_distribution<int> distSecondName(0, 19);
    std::uniform_int_distribution<int> distTitle(0, 59);
    
    for (int i = 0; i < count; i++)
    {
        ISBN = std::to_string(dist1(generator));
        title = TitleNameList[distTitle(generator)];
        authorFirstName = FirstNameList[distFirstName(generator)];
        authorSecondName = SecondNameList[distSecondName(generator)];
        pages = dist2(generator);
        YearPublish = dist3(generator);
        
        outFile << ISBN << "," << title << "," << authorSecondName << "," << authorFirstName << "," << pages << "," << YearPublish << "\n";
    }
    
    outFile.close();
}

void GettingDataFromFile(std::string& name, ArraySequence<BookCard>& book)
{
    std::ifstream inFile(name);
    
    if (!inFile) {
        throw std::ios_base::failure("Failed to open file for reading");
    }
    
    BookCard tmp;
    inFile.ignore(63, '\n');
    while(true)
    {
        std::getline(inFile, tmp.ISBN, ',');
        std::getline(inFile, tmp.title, ',');
        std::getline(inFile, tmp.authorSecondName, ',');
        std::getline(inFile, tmp.authorFirstName, ',');

        inFile >> tmp.pages;
        inFile.ignore(1);
        inFile >> tmp.YearPublish;
        inFile.ignore(1);
        
        if(!inFile)
        {
            break;
        }
        book.Append(tmp);
    }
}

void PuttingDataToFile(std::string& name, ArraySequence<BookCard>& book)
{
    std::ofstream outFile(name, std::ios::out);
    
    if (!outFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }
    
    outFile << "ISBN,title,authorSecondName,authorFirstName,pages,YearPublish\n";
    for(auto i = 0; i < book.GetLength(); i++)
    {
        outFile << book[i].ISBN << "," << book[i].title << "," << book[i].authorSecondName << "," << book[i].authorFirstName<< "," <<book[i].pages << "," << book[i].YearPublish <<"\n";
    }
}
