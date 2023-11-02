#ifndef __REQUESTCODEC__
#define __REQUESTCODEC__
#pragma once
#include <iostream>
#include "Codec.h"
#include "Message.pb.h"


using namespace std;
struct RequestInfo
{
    int cmd;
    string clientID;
    string serverID;
    string sign;
    string data;
};

class RequestCodec :
    public Codec
{
private:
    string m_encStr; 
    //Ҫ���л���������RequestMsg���У���Ҫͨ��RequestMsg��������л����� 
    RequestMsg m_msg;
public:
    //�ն���
    RequestCodec();
    //������Ķ������� ����
    RequestCodec(const string& encstr);
    //������Ķ������� ����
    RequestCodec(const RequestInfo& info);
    //��������
    ~RequestCodec();


    //init�����Ǹ����캯��׼����
    void initMessage(const string& encstr);//����ʱʹ��
    void initMessage(const RequestInfo& info);//����ʱʹ��
    //��д���ຯ��
    string encodeMsg() override;//���� ���л��������������л����ַ���
    void* decodeMsg()override; //���� �����л����������ص���һ�������
};

#endif // !__REQUESTCODEC__


