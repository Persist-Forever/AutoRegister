#pragma once
#include <string>
#include "Factory.h"
#include "DrvManager.h"
class IDrvModule {
public:
	IDrvModule(std::string name) : m_moduleName(name) {}
	virtual ~IDrvModule() = default;
	virtual void PrintMoudleName() const = 0;
	inline std::string GetModuleName() const { return m_moduleName; }
private:
	std::string m_moduleName{"IdrvModule"};
};
using ModuleFunc = Dev::CreateClass<IDrvModule, std::string>;
using DrvModuleFactory = Dev::Factory<uint32_t, IDrvModule, ModuleFunc>;
using ModuleDrv = DrvManager<IDrvModule>;