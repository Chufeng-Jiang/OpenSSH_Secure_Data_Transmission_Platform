#ifndef __RESPONSEFACTORY__
#define __RESPONSEFACTORY__


#pragma once
#include "CodecFactory.h"
#include "ResponseCodec.h"
class ResponseFactory :
    public CodecFactory
{
public:
    ResponseFactory();
    ResponseFactory(const string& enc);
    ResponseFactory(const ResponseInfo& info);
    ~ResponseFactory();

    Codec* createCodec();
private:
    bool m_flag;   //���   true : m_info ����ʼ��     false : m_encStr ����ʼ��
    string m_encStr;   //����
    ResponseInfo m_info;   //����    
};

#endif // !__RESPONSEFACTORY__



