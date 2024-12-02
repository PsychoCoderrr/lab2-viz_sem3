#pragma once
#include "Sequence.h"
#include "ArrayIterator.h"
#include "Book.h"
template<typename T, typename iterator>
struct HeadSorter
{
    virtual void sort(iterator begin, iterator end, bool (*comparator)(const T&, const T&)) = 0;
};
