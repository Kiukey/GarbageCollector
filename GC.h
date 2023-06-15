#pragma once
#include <vector>
#include "SingletonTemplate.h"

class IGarbageable;

class GC
{
private:
	static inline std::vector<IGarbageable*> addresses = std::vector<IGarbageable*>();
	static inline unsigned int objectMarkedLastCollection = 0;
	static inline unsigned int objectDestroyedLastCollection = 0;

public:
	GC();
	~GC();


	static void MarkAll();
	static void Collect();
	static bool MarkObject(IGarbageable* _toMark);
	static bool Register(IGarbageable* _toRegister);
private:

	static void DisplayResultLastCollection();
};

