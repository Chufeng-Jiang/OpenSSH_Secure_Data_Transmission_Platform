#ifndef __TCPSERVER__
#define __TCPSERVER__
#pragma once
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "TcpSocket.h"

class TcpServer
{
	///////����////////
public:
	TcpServer() = default;
	~TcpServer() = default;

	//���������ü���
	int setListen(const unsigned short port);
	//�ȴ������ܿͻ�����������Ĭ�����ӳ�ʱʱ��Ϊ8192s
	TcpSocket* acceptConnet(int wait_seconds = 8192);

	void closeFd();
	///////����////////
private:
	int m_lfd;	//�������ļ�������
};


#endif // !__TCPSERVER__

