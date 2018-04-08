#include "xmachinemanager.h"

//访问量大==采用饿汉模式
XMachineManager *XMachineManager::m_Instance = new XMachineManager();
XMachineManager *XMachineManager::getMachineInstance()
{
    return m_Instance;
}

XMachineManager::XMachineManager()
{
}

XMachineManager::~XMachineManager()
{
}
