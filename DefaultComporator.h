#pragma once

template<typename T>
bool DefaultComparator(const T& lhs, const T& rhs)
{
    return (rhs >= lhs);
}

template<typename T>
bool DescDefaultComporator(const T& lhs, const T& rhs)
{
    return (rhs <= lhs);
}
