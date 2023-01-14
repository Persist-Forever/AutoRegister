#pragma once

#include <map>
#include "IServer.h"

class CmdMgr {
public:
	static CmdMgr& GetInstance();
	void RegisterCmd(uint16_t cmd, IServer* server);
	void DealCmd(const uint8_t* data, uint32_t len);
private:
	CmdMgr() = default;
	~CmdMgr() = default;
	std::map<uint16_t, IServer*> m_cmd;
};