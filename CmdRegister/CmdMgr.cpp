#include <iostream>
#include "CmdMgr.h"

CmdMgr& CmdMgr::GetInstance()
{
	static CmdMgr mgr;
	return mgr;
}

void CmdMgr::RegisterCmd(uint16_t cmd, IServer* server)
{
	m_cmd.emplace(cmd, server);
}

void CmdMgr::DealCmd(const uint8_t* data, uint32_t len)
{
	for (auto func : m_cmd) {
		std::cout << "deal cmdId: " << std::hex << func.first << std::endl;
		func.second->Excute(data, len);
	}
}