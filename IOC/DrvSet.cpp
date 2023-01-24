#include "DrvSet.h"
//#include "DrvManager.h"

void DrvSet::Initialize()
{
	for (const auto& para : g_drvPara) {
		uint32_t key = (para.port << 16) + para.chnl;
		IDrvModule* module = DrvModuleFactory::GetInstance().CreatPtr(1, para.name);
		if (module == nullptr) {
			std::cout << "module is not creat ...  port£º" << para.port << "  chnl:" << para.chnl << std::endl;
			continue;
		}
		ModuleDrv::GetInstance().SaveDrv(para.port, para.chnl, module);
	}
}

IDrvModule* DrvSet::QueryModuleDrv(uint16_t port, uint16_t chnl)
{
	return ModuleDrv::GetInstance().QueryModuleDrv(port, chnl);
}

void DrvSet::TestModule()
{
	for (const auto& para : g_drvPara) {
		IDrvModule* module = QueryModuleDrv(para.port, para.chnl);
		if (module == nullptr) {
			std::cout << "module is find err ...  port£º" << para.port << "  chnl:" << para.chnl << std::endl;
			return;
		}
		module->PrintMoudleName();
	}
}