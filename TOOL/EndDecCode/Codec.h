#ifndef __CODEC__
#define __CODEC__
#pragma once
#include<iostream>

using std::string;

class Codec
{
public:
	Codec();
	virtual string encodeMsg();	//����
	virtual void* decodeMsg();	//����
	//������-->��̬-->Big Three-->����ͨ������ָ���ͷ��������
	virtual ~Codec();

};


#endif // !__CODEC__


