#ifndef __TCPSOCKET__
#define __TCPSOCKET__
#pragma once
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
/*����ͨ�ŵ��׽�����*/
// ��ʱ��ʱ��
static const int TIMEOUT = 8192;
class TcpSocket
{
	///////����////////
public:
	TcpSocket() = default;
	TcpSocket(int connect);
	~TcpSocket() = default;

	// ���ӷ�����
	int connectToHost(string ip, unsigned short port, int timeout = TIMEOUT);
	// ��������
	int sendMsg(string sendData, int timeout = TIMEOUT);
	// ��������
	string recvMsg(int timeout = TIMEOUT);
	// �Ͽ�����
	void disconnect();
private:
	// ����I/O������
	int setNoBlock(int fd);
	// ����I/O����
	int setBlock(int fd);
	// ����ʱ��⺯����������������
	int readTimeout(unsigned int wait_seconds);
	// д��ʱ��⺯����������д����
	int writeTimeout(unsigned int wait_seconds);
	// �����ӳ�ʱ��connect����
	int connectTimeout(struct sockaddr_in* addr, unsigned int wait_seconds);
	// ÿ�δӻ������ж�ȡn���ַ�
	int readn(void* buffer,int count);
	// ÿ����������д��n���ַ�
	int writen(const void* buffer, int count);
	 
	
	///////����////////
public:
	enum ErrorType
	{
		ParamError = 3001,
		TimeoutError,
		PeerCloseError,
		MallocError
	};
private:
	int m_socket;	//ͨ�ŵ��ļ�������
};

#endif // ! __TCPSOCKET__



