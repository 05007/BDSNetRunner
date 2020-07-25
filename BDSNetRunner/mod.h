#pragma once
#include "Events.h"

// ������/��ҵ��
#define COMMERCIAL 0

extern void init();
extern void exit();
extern void initMods();

#define MCCSAPI extern "C" __declspec (dllexport)

// ����c#һ��ͨ��ָ��
MCCSAPI void setSharePtr(const char*, void*);
// ��ȡc#һ��ͨ��ָ��
MCCSAPI void* getSharePtr(const char*);
// �Ƴ�c#һ��ͨ��ָ��
MCCSAPI void* removeSharePtr(const char*);

// ע��c#�¼�����ǰ�ص�
MCCSAPI bool addBeforeActListener(const char*, bool(*)(Events));
// ע��c#�¼�������ص�
MCCSAPI bool addAfterActListener(const char*, bool(*)(Events));
// �Ƴ�c#�¼�����ǰ�ص�
MCCSAPI bool removeBeforeActListener(const char*, bool(*)(Events));
// �Ƴ�c#�¼�������ص�
MCCSAPI bool removeAfterActListener(const char*, bool(*)(Events));
// ����һ��ȫ��ָ��˵��
MCCSAPI void setCommandDescribeEx(const char*, const char*, char, char, char);
// ִ�к��ָ��
MCCSAPI bool runcmd(const char*);
// ����һ�����������Ϣ��ĩβ�ӻ��з���
MCCSAPI void logout(const char*);
// ��ȡ��������б�
MCCSAPI const char* getOnLinePlayers();
// ����������
MCCSAPI bool reNameByUuid(const char*, const char*);
// ��ȡһ�����������Ϣ
MCCSAPI const char* selectPlayer(const char*);
// ģ�⺰��
MCCSAPI bool talkAs(const char*, const char*);
// ģ��ָ��
MCCSAPI bool runcmdAs(const char*, const char*);
// ����ָ�����һ������
MCCSAPI UINT sendSimpleForm(char*, char*, char*, char*);
// ����ָ�����һ��ģ��Ի���
MCCSAPI UINT sendModalForm(char*, char*, char*, char*, char*);
// ����ָ�����һ���Զ���GUI����
MCCSAPI UINT sendCustomForm(char*, char*);
// ������ʹ�õ�id
MCCSAPI bool releaseForm(unsigned);
// �������һ������Ʒ
MCCSAPI bool addPlayerItem(const char*, int, short, char);

// �Ӵ˴���ȡ����API
MCCSAPI void* getExtraAPI(const char*);


#if (COMMERCIAL)
// ����ԭ�ͣ���ȡһ���ṹ
typedef const char* (**getStructureFunc)(int, const char*, const char*, bool, bool);
// ����ԭ�ͣ�����һ���ṹ��ָ��λ��
typedef bool (**setStructureFunc)(const char*, int, const char*, char, bool, bool);
// ����ԭ�ͣ���ȡ���������
typedef const char* (**getPlayerAbilitiesFunc)(const char*);
// ����ԭ�ͣ��������������
typedef bool (**setPlayerAbilitiesFunc)(const char*, const char*);
// ����ԭ�ͣ���ȡ������Ա�
typedef const char* (**getPlayerAttributesFunc)(const char*);
// ����ԭ�ͣ��������������ʱֵ��
typedef bool (**setPlayerTempAttributesFunc)(const char*, const char*);
// ����ԭ�ͣ���ȡ�����������ֵ��
typedef const char* (**getPlayerMaxAttributesFunc)(const char*);
// ����ԭ�ͣ����������������ֵ��
typedef bool (**setPlayerMaxAttributesFunc)(const char*, const char*);
// ����ԭ�ͣ���ȡ���������Ʒ�б�
typedef const char* (**getPlayerItemsFunc)(const char*);
// ����ԭ�ͣ��������������Ʒ�б�
typedef bool (**setPlayerItemsFunc)(const char*, const char*);
// ����ԭ�ͣ���ȡ��ҵ�ǰѡ������Ϣ
typedef const char* (**getPlayerSelectedItemFunc)(const char*);
// ����ԭ�ͣ��������һ����Ʒ
typedef bool (**addPlayerItemExFunc)(const char*, const char*);
// ����ԭ�ͣ���ȡ�������Ч���б�
typedef const char* (**getPlayerEffectsFunc)(const char*);
// ����ԭ�ͣ������������Ч���б�
typedef bool (**setPlayerEffectsFunc)(const char*, const char*);
// ����ԭ�ͣ���������Զ���Ѫ��
typedef bool (**setPlayerBossBarFunc)(const char*, const char*, float);
// ����ԭ�ͣ��������Զ���Ѫ��
typedef bool (**removePlayerBossBarFunc)(const char*);
// ����ԭ�ͣ����������ָ��������
typedef bool (**transferserverFunc)(const char*, const char*, int);
// ����ԭ�ͣ����������ָ�������ά��
typedef bool (**teleportFunc)(const char*, float, float, float, int);
// ����ԭ�ͣ���������Զ���������ʱ�Ʒְ�
typedef bool (**setPlayerSidebarFunc)(const char*, const char*, const char*);
// ����ԭ�ͣ��������Զ�������
typedef bool (**removePlayerSidebarFunc)(const char*);
// ����ԭ�ͣ���ȡ���Ȩ������Ϸģʽ
typedef const char* (**getPlayerPermissionAndGametypeFunc)(const char*);
// ����ԭ�ͣ��������Ȩ������Ϸģʽ
typedef bool (**setPlayerPermissionAndGametypeFunc)(const char*, const char*);
#endif

// ����ʵ��RVA��Ӧ��ַ
MCCSAPI unsigned long long dlsym(int rva);
// ע��c#���õ�hook����
MCCSAPI bool cshook(int rva, void* hook, void** org);
// ע��c#���õ�unhook����
MCCSAPI bool csunhook(void* hook, void** org);