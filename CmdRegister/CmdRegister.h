#pragma once

#include "IServer.h"
#include "CmdMgr.h"

template<typename ClassName, uint16_t cmdId>
class CmdRegister {
public:
	struct Register {
		Register()
		{
			static ClassName service;
			CmdMgr::GetInstance().RegisterCmd(cmdId, &service);
		}
	};
	static Register reg;
};

template<typename ClassName, uint16_t cmdId>
typename CmdRegister<ClassName, cmdId>::Register CmdRegister<ClassName, cmdId>::reg;

#define CMD_REGISTER(cmdId)                                     \
class Server##cmdId : public IServer {                              \
	uint32_t Excute(const uint8_t* data, uint32_t len);            \
};                                                                  \
template class CmdRegister<Server##cmdId, cmdId>;                \
uint32_t Server##cmdId::Excute(const uint8_t* data, uint32_t len)