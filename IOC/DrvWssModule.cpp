#include <iostream>
#include "DrvWssModule.h"
#include "DrvConst.h"

//DrvModuleFactory::Register g_wssModule(DEV_MODULE_DRV, [](std::string name) { return new DrvWssModule(name); });

RIGISTER_DEV_FUNC(DrvModuleFactory, DEV_MODULE_DRV, DrvWssModule, std::string)

void DrvWssModule::PrintMoudleName() const
{
	std::cout << GetModuleName() << std::endl;
}