#ifndef __REQUESTFACTORY__
#define __REQUESTFACTORY__

#pragma once
#include "CodecFactory.h"
#include "RequestCodec.h"
class RequestFactory :
	public CodecFactory
{
public:
	RequestFactory();
	RequestFactory(const string& enc);
	RequestFactory(const RequestInfo& info);
	~RequestFactory();

	Codec* createCodec();
private:
	bool m_flag;    //���  true : m_info ����ʼ��     false : m_encStr ����ʼ��
	string m_encStr;    //����
	RequestInfo m_info;    //����
};


#endif // !__REQUESTFACTORY__


