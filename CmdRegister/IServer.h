/**
�������ע�����
*/
#pragma once
#include <cstdint>

class IServer {
public:
	virtual uint32_t Excute(const uint8_t* data, uint32_t len) = 0;
};

