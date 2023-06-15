#include "GC.h"
#include "IGarbageable.h"
#include <iostream>

GC::GC()
{
}

GC::~GC()
{
	MarkAll();
	Collect();
	addresses.clear();
}

void GC::MarkAll()
{
	for (IGarbageable* _value : addresses)
	{
		_value->SetMarkedState(true);
	}
}

void GC::Collect()
{
	objectDestroyedLastCollection = 0;
	objectMarkedLastCollection = 0;
	for (int i = 0; i < addresses.size(); i++)
	{
		if (addresses[i]->IsMarked())
		{
			addresses[i]->DestroyValue();
			addresses.erase(addresses.begin() + i);
			objectDestroyedLastCollection++;
			i--;
		}
		else
		{
			addresses[i]->SetMarkedState(true);
			objectMarkedLastCollection++;
		}
	}
	DisplayResultLastCollection();
}

bool GC::MarkObject(IGarbageable* _toMark)
{
	if (!_toMark)
		return false;
	_toMark->SetMarkedState(true);
	return true;
}

bool GC::Register(IGarbageable* _toRegister)
{
	if (!_toRegister)
		return false;
	addresses.push_back(_toRegister);
	return true;
}

void GC::DisplayResultLastCollection()
{
	std::cout << "---------------------------" << std::endl;
	std::cout << "Number marked this loop : " << objectMarkedLastCollection << std::endl;
	std::cout << "Numbre Destroyed this loop : " << objectDestroyedLastCollection << std::endl;

}
