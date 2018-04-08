#ifndef XMACHINEMANAGER_H
#define XMACHINEMANAGER_H

class XMachineManager
{
public:
    static XMachineManager *getMachineInstance();
private:
    XMachineManager();
    ~XMachineManager();
private:
    static XMachineManager *m_Instance;
};

#endif // XMACHINEMANAGER_H
