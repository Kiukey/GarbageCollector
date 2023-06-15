#pragma once

template<typename T>
class SingletonTemplate
{
private:
	static inline T* instance = nullptr;
public:
	SingletonTemplate() = default;
	virtual ~SingletonTemplate()
	{
		delete instance;
		instance = nullptr;
	}

	static inline T* Instance()
	{
		if (instance == nullptr)
			instance = new T();
		return instance;
	}
	void Destroy()
	{
		OnDestroy();
		delete this;
	}
private:
	virtual void OnDestroy() {}
};