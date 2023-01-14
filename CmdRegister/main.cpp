#include <iostream>
#include "CmdMgr.h"
using namespace std;
int main()
{
	const uint8_t data[] = { 1, 2, 3, 4 };
	int len = sizeof(data) / sizeof(uint8_t);
	cout << len << endl;
	CmdMgr::GetInstance().DealCmd(data, len);

	return 0;
}