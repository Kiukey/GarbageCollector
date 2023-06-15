#include <iostream>
#include "Object.h"
class Test
{
public:

	void Debug()
	{
		std::cout << "Test" << std::endl;
	}
};

int main()
{
	//_CrtSetBreakAlloc(155)

	GC* _instance = new GC();
	Object<char> _newObject = Object<char>(new char[3]{'a','b', 'c' }, true);
	Object<Test> _newObject2 = Object<Test>(new Test());
	Object<int> _newObject3 = Object<int>(new int(12));

	_instance->Collect();

	for (int i = 0; i < 3; i++)
	{
		std::cout << _newObject[i] << std::endl;
		_newObject[i] = 'c';
		std::cout << _newObject[i] << std::endl;
	}

	_newObject2->Debug();
	std::cout << *_newObject3 << std::endl;
	_instance->Collect();
	_instance->Collect();
	
	delete _instance;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);



	//console cmd qui marche pas de ouf xD 
	//while (true)
	//{
	//	char* _result = new char[100];
	//	std::cin.getline(_result, 100);
	//	system(_result);
	//}
}
