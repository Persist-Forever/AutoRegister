#pragma once
#include <string>
#include "IDrvModule.h"

class DrvWssModule : public IDrvModule {
public:
	DrvWssModule(std::string name) : IDrvModule(name) {}
	~DrvWssModule() = default;
	void PrintMoudleName() const override;
};