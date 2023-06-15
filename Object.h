#pragma once
#include "IGarbageable.h"
#include <string>
#include <iostream>

template<typename T>
class Object : public IGarbageable
{
	T* value = nullptr;
	bool isArray = false;
public:

	Object(){}
	Object(T* _value, bool _isArray = false)
	{
		value = _value;
		isArray = _isArray;
	}

	void DestroyValue() override
	{

		if (isArray)
			delete[] value;
		else
			delete value;
		value = nullptr;
	}

	T* Get()
	{
		SetMarkedState(false);
		return value;
	}
	T* operator->()
	{
		return Get();
	}
	T& operator[](int _index) const
	{
		return value[_index];
	}
	T operator*() const
	{
		return *value;
	}
	void operator=(T* _value) const
	{
		value = _value;
	}
};

