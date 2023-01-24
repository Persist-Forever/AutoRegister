#include <iostream>
#include <memory>
#include "CmdMgr.h"
#include "DrvSet.h"
using namespace std;

int main()
{
	DrvSet::GetInstance().Initialize();
	DrvSet::GetInstance().TestModule();
	return 0;
}