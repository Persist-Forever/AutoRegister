#pragma once
#include <cstdint>
#include <map>
template<typename BaseClass>
class DrvManager {
public:
	static DrvManager& GetInstance()
	{
		static DrvManager manager;
		return manager;
	}
	~DrvManager()
	{
		for (auto itr = m_devDrv.begin(); itr != m_devDrv.end(); itr++) {
			delete(itr->second);
			itr->second = nullptr;
		}
		m_devDrv.clear();
	}
	BaseClass* QueryModuleDrv(uint16_t port, uint16_t chnl)
	{
		uint32_t key = (port << 16) + chnl;
		auto itr = m_devDrv.find(key);
		if (itr == m_devDrv.end()) {
			return nullptr;
		}
		return itr->second;
	}
	void SaveDrv(uint16_t port, uint16_t chnl, BaseClass* drv)
	{
		uint32_t key = (port << 16) + chnl;
		m_devDrv.emplace(key, drv);
	}
private:
	std::map<uint32_t, BaseClass*> m_devDrv;
};