#include <stdexcept>

using namespace std;

#include "IntVector.h"

IntVector::IntVector()
{
	sz = 0;
	cap = 0;
	data = nullptr;
}

IntVector::IntVector(unsigned size, int value)
{
	sz = size;
	cap = size;
	data = new int[size];

	for (unsigned i = 0; i < size; ++i)
	{
		data[i] = value;
	}
}

IntVector::~IntVector()
{
	delete[] data;
	data = nullptr;
}

unsigned IntVector::size() const
{
	return sz;
}

unsigned IntVector::capacity() const
{
	return cap;
}

bool IntVector::empty() const
{
	return sz == 0;
}

const int& IntVector::at(unsigned index) const
{
	if (empty() || index < 0 || index >= sz)
	{
		throw out_of_range("IntVector::at_range_check");
	}

	return data[index];
}

int& IntVector::at(unsigned index)
{
    if (empty() || index < 0 || index >= sz)
    {
        throw out_of_range("IntVector::at_range_check");
    }

    return data[index];
}

void IntVector::insert(unsigned index, int value)
{
    if (index > sz)
    {
        throw out_of_range("IntVector::insert_range_check");
    }

    if (sz == cap)
    {
        expand();
    }

    for (unsigned i = sz; i > index; --i)
    {
        data[i] = data[i - 1];
    }

    data[index] = value;
    ++sz;
}

void IntVector::erase(unsigned index)
{
    if (index >= sz)
    {
        throw out_of_range("IntVector::erase_range_check");
    }

    for (unsigned i = index; i + 1 < sz; ++i)
    {
        data[i] = data[i + 1];
    }

    --sz;
}

const int& IntVector::front() const
{
	return data[0];
}

int& IntVector::front()
{
    return data[0];
}

const int& IntVector::back() const
{
	return data[sz - 1];
}

int& IntVector::back()
{
    return data[sz - 1];
}

void IntVector::assign(unsigned n, int value)
{
    if (n > cap * 2)
    {
        expand(n - cap);
    }
    else if (n > cap)
    {
        expand();
    }

    for (unsigned i = 0; i < n; ++i)
    {
        data[i] = value;
    }

    sz = n;
}

void IntVector::push_back(int value)
{
    if (sz == cap)
    {
        expand();
    }
    data[sz] = value;
    ++sz;
}

void IntVector::pop_back()
{
    --sz;
}

void IntVector::clear()
{
    sz = 0;
}

void IntVector::resize(unsigned size, int value)
{
    if (size < sz)
    {
        sz = size;
    }
    else if (size > sz)
    {
        if (size > cap * 2)
        {
            expand(size - cap);
        }
        else if (size > cap)
        {
            expand();
        }

        for (unsigned i = sz; i < size; ++i)
        {
            data[i] = value;
        }

        sz = size;
    }
}

void IntVector::reserve(unsigned n)
{
    if (n > cap)
    {
        expand(n - cap);
    }
}

void IntVector::expand()
{
    if (cap == 0)
    {
        expand(1);
    }
    else
    {
        expand(cap);
    }
}

void IntVector::expand(unsigned amount)
{
    int* temp = new int[cap + amount];
    for (unsigned i = 0; i < sz; ++i) // Should not iterate if data is empty/null
    {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    cap += amount;
}