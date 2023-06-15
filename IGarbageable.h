#pragma once
#include "GC.h"


class IGarbageable
{
private:

	bool isGarbageable = true;
	bool isMarked = false;
public:
	IGarbageable()
	{
		GC::Register(this);
	};
	virtual ~IGarbageable() = default;

	bool IsMarked()
	{
		return isMarked;
	}
	void SetGarbageableState(bool _state)
	{
		isGarbageable = _state;
	}
	void SetMarkedState(bool _state)
	{
		isMarked = _state;
	}

	virtual void DestroyValue() = 0;

};