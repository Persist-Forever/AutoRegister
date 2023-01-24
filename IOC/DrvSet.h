#pragma once
#include <cstdint>
#include <string>
#include "IDrvModule.h"
struct DrvAttr {
	uint16_t port;
	uint16_t chnl;
	std::string name;
};
const DrvAttr g_drvPara[] = {
	{1, 1, "wss_module1"},
	{2, 1, "wss_module2"},
	{3, 1, "wss_module3"},
};
class DrvSet {
public:
	static DrvSet& GetInstance()
	{
		static DrvSet drvSet;
		return drvSet;
	}
	~DrvSet() = default;
	void Initialize();
	IDrvModule* QueryModuleDrv(uint16_t port, uint16_t chnl);
	void TestModule();
};