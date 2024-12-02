#pragma once
#include "Book.h"

bool ComporatorBookPages(const BookCard& lhs, const BookCard& rhs)
{
    return (rhs.GetPages() >= lhs.GetPages());
}

bool DescComporatorBookPages(const BookCard& lhs, const BookCard& rhs)
{
    return !(rhs.GetPages() >= lhs.GetPages());
}

bool ComporatorBookYear(const BookCard& lhs, const BookCard& rhs)
{
    return rhs.GetYearPublish() >= lhs.GetYearPublish();
}

bool DescComporatorBookYear(const BookCard& lhs, const BookCard& rhs)
{
    return !(rhs.GetYearPublish() >= lhs.GetYearPublish());
}

bool ComporatorBookFirstName(const BookCard& lhs, const BookCard& rhs)
{
    return rhs.GetAuthorFirstName() >= lhs.GetAuthorFirstName();
}

bool DescComporatorBookFirstName(const BookCard& lhs, const BookCard& rhs)
{
    return !(rhs.GetAuthorFirstName() >= lhs.GetAuthorFirstName());
}

bool ComparatorBookTitle(const BookCard& lhs, const BookCard& rhs)
{
    return rhs.GetTitle() >= lhs.GetTitle();
}

bool DescComparatorBookTitle(const BookCard& lhs, const BookCard& rhs)
{
    return !(rhs.GetTitle() >= lhs.GetTitle());
}

bool ComporatorBookSecondName(const BookCard& lhs, const BookCard& rhs)
{
    return rhs.GetAuthorSecondName() >= lhs.GetAuthorSecondName();
}

bool DescComporatorBookSecondName(const BookCard& lhs, const BookCard& rhs)
{
    return !(rhs.GetAuthorSecondName() >= lhs.GetAuthorSecondName());
}
