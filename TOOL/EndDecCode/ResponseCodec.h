#ifndef __RESPONSECODEC__
#define __RESPONSECODEC__
#pragma once

#include <iostream>
#include "Codec.h"
#include "Message.pb.h"

using namespace std;

struct ResponseInfo
{
    bool status;
    int seckeyID;
    string clientID;
    string serverID;
    string data;
};

class ResponseCodec :
    public Codec
{
private:
    string m_encStr;
    RespondMsg m_msg;
public:
    //�չ���
    ResponseCodec();
    //���� ����
    ResponseCodec(const string& encstr);
    //���� ����
    ResponseCodec(const ResponseInfo& info);
    //��������
    ~ResponseCodec();

    //��ʼ������
    void initMessage(const string& encstr);    //���ڽ���
    void initMessage(const ResponseInfo& info);//���ڱ��� 
    //��д���ຯ��
    string encodeMsg()override;//���� ���л��������������л����ַ���
    void* decodeMsg()override; //���� �����л����������ص���һ�������

};

 
#endif // !__RESPONSECODEC__

