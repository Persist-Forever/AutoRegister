#include <iostream>
#include "CmdRegister.h"

CMD_REGISTER(0x1234)
{
	std::cout << "para len:" << len << std::endl;
	std::cout << "data:" << std::endl;
	for (uint16_t i = 0; i < len; ++i) {
		std::cout << static_cast<uint16_t>(data[i]) << "  ";
	}
	std::cout << std::endl;
	return 0;
}