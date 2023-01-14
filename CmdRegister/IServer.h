/**
命令处理自注册机制
*/
#pragma once
#include <cstdint>

class IServer {
public:
	virtual uint32_t Excute(const uint8_t* data, uint32_t len) = 0;
};

