#pragma once
#include <functional>
#include <map>
#include <cstdint>
#include <iostream>

namespace Dev {

template<typename BaseClass, typename... Args>
using CreateClass = std::function<BaseClass* (Args... args)>;

template<typename Key, typename BaseClass, typename CreateClass>
class Factory {
public:
	static Factory& GetInstance()
	{
		static Factory factory;
		return factory;
	}
	struct Register {
		Register(const Key& key, CreateClass func)
		{
			GetInstance().RegCreatClass(key, func);
		}
	};
	void RegCreatClass(const Key& key, CreateClass func)
	{
		auto itrFunc = m_func.emplace(key, func);
		if (!itrFunc.second) {
			std::cout << "do not duplicate registration" << std::endl;

		}
		//m_func[key] = func;
	}
	template<typename... Args>
	BaseClass* CreatPtr(const Key& key, Args&&... args)
	{
		auto itr = m_func.find(key);
		if (itr == m_func.end()) {
			return nullptr;
		}
		return itr->second(std::forward<Args>(args)...);
	}
private:
	std::map<Key, CreateClass> m_func;

};

#define RIGISTER_DEV_FUNC(Factory, Key, Obj, Para)  \
Factory::Register g_##Factory##Obj(Key, [](const Para& para) { return new Obj(para);});

}
