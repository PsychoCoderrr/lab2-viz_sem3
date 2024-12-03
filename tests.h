#pragma once
#include <iostream>
#include <time.h>

#include "Complex.h"
#include "Person.h"
#include "assert.h"
#include "ArraySequence.h"
#include <compare>
#include "Generator.h"
#include "ArrayIterator.h"
#include "QuickSort.h"
#include "BookCardComporator.h"
#include "HeapSort.h"
#include "BubbleSort.h"
#include "FuncForBD.h"
#include "DefaultComporator.h"
void TestComplexSum()
{
    complex test1(2, 4);
    complex test2(1, 3);
    complex test3 = test1 + test2;
    assert(test3.GetRe() == 3);
    assert(test3.GetIm() == 7);
    assert(test1.GetRe() == 2);
    test3 += test1;
    assert(test3.GetRe() == 5);
    assert(test3.GetIm() == 11);
}

void TestComplexSubtract()
{
    complex test1(2, 4);
    complex test2(1, 3);
    complex test3 = test1 - test2;
    assert(test3.GetRe() == 1);
    assert(test3.GetIm() == 1);
    test3 -= test1;
    assert(test3.GetRe() == -1);
    assert(test3.GetIm() == -3);
}

void TestComplexMulti()
{
    complex test1(2, 4);
    complex test2(1, 3);
    complex test3 = test1 * test2;
    assert(test3.GetRe() == -10);
    assert(test3.GetIm() == 10);
    test3 *= test1;
    assert(test3.GetRe() == -60);
    assert(test3.GetIm() == -20);
}

void TestComplexDiv()
{
    complex test1(1, 1);
    complex test2(1, 1);
    complex test3 = test1 / test2;
    assert(test3.GetRe() == 1);
    assert(test3.GetIm() == 0);
}

void TestArraySequence()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    ArraySequence<int> test(a, 8);
    assert(test.GetFirst() == 1);
    assert(test.GetLast() == 8);
    test.Append(9);
    assert(test.GetLength() == 9);
    assert(test.GetLast() == 9);
    test.Prepend(0);
    assert(test.GetLength() == 10);
    assert(test.GetFirst() == 0);
    assert(test[0] == 0);
    assert(test[5] == 5);
    test[5] = 80;
    assert(test[5] == 80);
}


void testQuickSortPages(int cnt)
{
    std::string filename = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/otput.csv";
    std::string filename_2 = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/input.csv";

    Generator(filename, cnt);
    ArraySequence<BookCard> a;
    QuickSort<BookCard, ArraySequenceIterator<BookCard, false>> QuickSorter;
    GettingDataFromFile(filename, a);
    std::cout << a.GetLength() << std::endl;
    std::cout<<a[1] << std::endl;
    clock_t start = clock();
    QuickSorter.sort(a.begin(), a.end(), ComporatorBookPages);
    clock_t end = clock();
    std::cout << a[1] << std::endl;
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << std::endl;
    PuttingDataToFile(filename_2, a);
}

void testQuickSortFName(int cnt)
{
    std::string filename = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/otput.csv";
    std::string filename_2 = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/input.csv";

    Generator(filename, cnt);
    ArraySequence<BookCard> a;
    QuickSort<BookCard, ArraySequenceIterator<BookCard, false>> QuickSorter;
    GettingDataFromFile(filename, a);
    std::cout << a.GetLength() << std::endl;
    std::cout<<a[1] << std::endl;
    clock_t start = clock();
    QuickSorter.sort(a.begin(), a.end(), ComporatorBookFirstName);
    clock_t end = clock();
    std::cout << a[1] << std::endl;
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << std::endl;
    PuttingDataToFile(filename_2, a);
}

void testQuickSortSName(int cnt)
{
    std::string filename = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/otput.csv";
    std::string filename_2 = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/input.csv";

    Generator(filename, cnt);
    ArraySequence<BookCard> a;
    QuickSort<BookCard, ArraySequenceIterator<BookCard, false>> QuickSorter;
    GettingDataFromFile(filename, a);
    std::cout << a.GetLength() << std::endl;
    std::cout<<a[1] << std::endl;
    clock_t start = clock();
    QuickSorter.sort(a.begin(), a.end(), ComporatorBookSecondName);
    clock_t end = clock();
    std::cout << a[1] << std::endl;
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << std::endl;
    PuttingDataToFile(filename_2, a);
}

void testQuickSortTitle(int cnt)
{
    std::string filename = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/otput.csv";
    std::string filename_2 = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/input.csv";

    Generator(filename, cnt);
    ArraySequence<BookCard> a;
    QuickSort<BookCard, ArraySequenceIterator<BookCard, false>> QuickSorter;
    GettingDataFromFile(filename, a);
    std::cout << a.GetLength() << std::endl;
    std::cout<<a[1] << std::endl;
    clock_t start = clock();
    QuickSorter.sort(a.begin(), a.end(), ComparatorBookTitle);
    clock_t end = clock();
    std::cout << a[1] << std::endl;
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << std::endl;
    PuttingDataToFile(filename_2, a);
}

void testQuickSortYear(int cnt)
{
    std::string filename = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/otput.csv";
    std::string filename_2 = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/input.csv";

    Generator(filename, cnt);
    ArraySequence<BookCard> a;
    QuickSort<BookCard, ArraySequenceIterator<BookCard, false>> QuickSorter;
    GettingDataFromFile(filename, a);
    std::cout << a.GetLength() << std::endl;
    std::cout<<a[1] << std::endl;
    clock_t start = clock();
    QuickSorter.sort(a.begin(), a.end(), ComporatorBookYear);
    clock_t end = clock();
    std::cout << a[1] << std::endl;
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << std::endl;
    PuttingDataToFile(filename_2, a);
}












void testHeapSortPages(int cnt)
{
    std::string filename = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/otput.csv";
    std::string filename_2 = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/input.csv";

    Generator(filename, cnt);
    ArraySequence<BookCard> a;
    HeapSort<BookCard, ArraySequenceIterator<BookCard, false>> HeapSorter;
    GettingDataFromFile(filename, a);
    std::cout << a.GetLength() << std::endl;
    std::cout<<a[1] << std::endl;
    clock_t start = clock();
    HeapSorter.sort(a.begin(), a.end(), ComporatorBookPages);
    clock_t end = clock();
    std::cout << a[1] << std::endl;
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << std::endl;
    PuttingDataToFile(filename_2, a);
}

void testHeapSortFName(int cnt)
{
    std::string filename = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/otput.csv";
    std::string filename_2 = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/input.csv";

    Generator(filename, cnt);
    ArraySequence<BookCard> a;
    HeapSort<BookCard, ArraySequenceIterator<BookCard, false>> HeapSorter;
    GettingDataFromFile(filename, a);
    std::cout << a.GetLength() << std::endl;
    std::cout<<a[1] << std::endl;
    clock_t start = clock();
    HeapSorter.sort(a.begin(), a.end(), ComporatorBookFirstName);
    clock_t end = clock();
    std::cout << a[1] << std::endl;
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << std::endl;
    PuttingDataToFile(filename_2, a);
}

void testHeapSortSName(int cnt)
{
    std::string filename = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/otput.csv";
    std::string filename_2 = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/input.csv";

    Generator(filename, cnt);
    ArraySequence<BookCard> a;
    HeapSort<BookCard, ArraySequenceIterator<BookCard, false>> HeapSorter;
    GettingDataFromFile(filename, a);
    std::cout << a.GetLength() << std::endl;
    std::cout<<a[1] << std::endl;
    clock_t start = clock();
    HeapSorter.sort(a.begin(), a.end(), ComporatorBookSecondName);
    clock_t end = clock();
    std::cout << a[1] << std::endl;
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << std::endl;
    PuttingDataToFile(filename_2, a);
}

void testHeapSortTitle(int cnt)
{
    std::string filename = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/otput.csv";
    std::string filename_2 = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/input.csv";

    Generator(filename, cnt);
    ArraySequence<BookCard> a;
    HeapSort<BookCard, ArraySequenceIterator<BookCard, false>> HeapSorter;
    GettingDataFromFile(filename, a);
    std::cout << a.GetLength() << std::endl;
    std::cout<<a[1] << std::endl;
    clock_t start = clock();
    HeapSorter.sort(a.begin(), a.end(), ComparatorBookTitle);
    clock_t end = clock();
    std::cout << a[1] << std::endl;
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << std::endl;
    PuttingDataToFile(filename_2, a);
}

void testHeapSortYear(int cnt)
{
    std::string filename = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/otput.csv";
    std::string filename_2 = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/input.csv";

    Generator(filename, cnt);
    ArraySequence<BookCard> a;
    HeapSort<BookCard, ArraySequenceIterator<BookCard, false>> HeapSorter;
    GettingDataFromFile(filename, a);
    std::cout << a.GetLength() << std::endl;
    std::cout<<a[1] << std::endl;
    clock_t start = clock();
    HeapSorter.sort(a.begin(), a.end(), ComporatorBookYear);
    clock_t end = clock();
    std::cout << a[1] << std::endl;
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << std::endl;
    PuttingDataToFile(filename_2, a);
}










void testBubbleSortPages(int cnt)
{
    std::string filename = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/otput.csv";
    std::string filename_2 = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/input.csv";

    Generator(filename, cnt);
    ArraySequence<BookCard> a;
    BubbleSort<BookCard, ArraySequenceIterator<BookCard, false>> BubbleSorter;
    GettingDataFromFile(filename, a);
    BubbleSorter.sort(a.begin(), a.end(), ComporatorBookPages);
    PuttingDataToFile(filename_2, a);
}

void testBubbleSortFName(int cnt)
{
    std::string filename = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/otput.csv";
    std::string filename_2 = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/input.csv";

    Generator(filename, cnt);
    ArraySequence<BookCard> a;
    BubbleSort<BookCard, ArraySequenceIterator<BookCard, false>> BubbleSorter;
    GettingDataFromFile(filename, a);
    std::cout << a.GetLength() << std::endl;
    std::cout<<a[1] << std::endl;
    clock_t start = clock();
    BubbleSorter.sort(a.begin(), a.end(), ComporatorBookFirstName);
    clock_t end = clock();
    std::cout << a[1] << std::endl;
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << std::endl;
    PuttingDataToFile(filename_2, a);
}

void testBubbleSortSName(int cnt)
{
    std::string filename = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/otput.csv";
    std::string filename_2 = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/input.csv";

    Generator(filename, cnt);
    ArraySequence<BookCard> a;
    BubbleSort<BookCard, ArraySequenceIterator<BookCard, false>> BubbleSorter;
    GettingDataFromFile(filename, a);
    std::cout << a.GetLength() << std::endl;
    std::cout<<a[1] << std::endl;
    clock_t start = clock();
    BubbleSorter.sort(a.begin(), a.end(), ComporatorBookSecondName);
    clock_t end = clock();
    std::cout << a[1] << std::endl;
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << std::endl;
    PuttingDataToFile(filename_2, a);
}

void testBubbleSortTitle(int cnt)
{
    std::string filename = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/otput.csv";
    std::string filename_2 = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/input.csv";

    Generator(filename, cnt);
    ArraySequence<BookCard> a;
    BubbleSort<BookCard, ArraySequenceIterator<BookCard, false>> BubbleSorter;
    GettingDataFromFile(filename, a);
    std::cout << a.GetLength() << std::endl;
    std::cout<<a[1] << std::endl;
    clock_t start = clock();
    BubbleSorter.sort(a.begin(), a.end(), ComparatorBookTitle);
    clock_t end = clock();
    std::cout << a[1] << std::endl;
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << std::endl;
    PuttingDataToFile(filename_2, a);
}

void testBubbleSortYear(int cnt)
{
    std::string filename = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/otput.csv";
    std::string filename_2 = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/learnsdl2_2/learnsdl2_2/input.csv";

    Generator(filename, cnt);
    ArraySequence<BookCard> a;
    BubbleSort<BookCard, ArraySequenceIterator<BookCard, false>> BubbleSorter;
    GettingDataFromFile(filename, a);
    std::cout << a.GetLength() << std::endl;
    std::cout<<a[1] << std::endl;
    clock_t start = clock();
    BubbleSorter.sort(a.begin(), a.end(), ComporatorBookYear);
    clock_t end = clock();
    std::cout << a[1] << std::endl;
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << std::endl;
    PuttingDataToFile(filename_2, a);
}

void bubblesortviztest()
{
    BubbleSort<int, ArraySequenceIterator<int, false>> BubbleSorter;
    BubbleSorter.sort_viz();
}

void quicksortviztest()
{
    QuickSort<int, std::vector<int>::iterator> sorter;
    sorter.sort_viz();
}

void heapsortviztest()
{
    HeapSort<int, std::vector<int>::iterator> sorter;
    sorter.sort_viz();
}


void statBubbleSort(int size)
{
    ArraySequence<int> seq;
    int start_sequence = -10000;
    int end_sequence = 10000;
    int a;
    for (int i = 0; i < size; i++)
    {
        a = rand() % (end_sequence - start_sequence + 1) + start_sequence;
        seq.Append(a);
    }
    BubbleSort<int, ArraySequenceIterator<int, false>> BubbleSorter;
    clock_t start = clock();
    BubbleSorter.sort(seq.begin(), seq.end(), DefaultComparator);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    addToBD(1, size, seconds);
}

void statQuickSort(int size)
{
    ArraySequence<int> seq;
    int start_sequence = -10000;
    int end_sequence = 10000;
    int a;
    for (int i = 0; i < size; i++)
    {
        a = rand() % (end_sequence - start_sequence + 1) + start_sequence;
        seq.Append(a);
    }
    QuickSort<int, ArraySequenceIterator<int, false>> QuickSorter;
    clock_t start = clock();
    QuickSorter.sort(seq.begin(), seq.end(), DefaultComparator);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    addToBD(2, size, seconds);
}

void statHeapSort(int size)
{
    ArraySequence<int> seq;
    int start_sequence = -10000;
    int end_sequence = 10000;
    int a;
    for (int i = 0; i < size; i++)
    {
        a = rand() % (end_sequence - start_sequence + 1) + start_sequence;
        seq.Append(a);
    }
    HeapSort<int, ArraySequenceIterator<int, false>> HeapSorter;
    clock_t start = clock();
    HeapSorter.sort(seq.begin(), seq.end(), DefaultComparator);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    addToBD(3, size, seconds);
}
