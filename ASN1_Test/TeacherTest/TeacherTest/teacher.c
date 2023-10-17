#include "teacher.h"
#include "itcast_asn1_der.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	typedef struct _Teacher
	{
		char name[64];
		int age;
		char *p;
		long plen;
	}Teacher;
*/
int encodeTeacher(Teacher * p, char ** outData, int * outlen)
{
	ITCAST_ANYBUF * head = NULL;
	ITCAST_ANYBUF * temp = NULL;
	ITCAST_ANYBUF * next = NULL;

	//Encode the name
	//DER_ITCAST_String_To_AnyBuf(ITCAST_ANYBUF **pOriginBuf,unsigned char* strOrigin,int strOriginLen)
	DER_ITCAST_String_To_AnyBuf(&temp, p->name, strlen(p->name)+1); //��Char����ת������ITCAST_AnyBuf���ŵ���temp��
	DER_ItAsn1_WritePrintableString(temp, &head); // temp����head
	DER_ITCAST_FreeQueue(temp);
	next = head; //nextָ��head

	//Encode the age
	//head���䣬�±���Ľӵ�next->nextλ��
	DER_ItAsn1_WriteInteger(p->age, &next->next);
	next = next->next; //head���䣬next����һλ

	//Encode p
	EncodeChar(p->p,strlen(p->p) + 1, &next->next);
	next = next->next;

	//Encode plen
	DER_ItAsn1_WriteInteger(p->plen, &next->next);

	//Sequence
	DER_ItAsn1_WriteSequence(head, &temp);

	//Value
	*outData = temp->pData;
	*outlen = temp->dataLen;

	//Free
	DER_ITCAST_FreeQueue(head);

	return 0;
}

/*
	typedef struct _Teacher
	{
		char name[64];
		int age;
		char *p;
		long plen;
	}Teacher;
*/
int decodeTeacher(char * inData, int inLen, Teacher ** p)
{
	ITCAST_ANYBUF * head = NULL;
	ITCAST_ANYBUF * temp = NULL;
	ITCAST_ANYBUF * next = NULL;

	Teacher *pt = (Teacher*)malloc(sizeof(Teacher));
	if (pt == NULL)
	{
		return -1;
	}

	//��inData�����л�������
	DER_ITCAST_String_To_AnyBuf(&temp,inData, inLen);
	DER_ItAsn1_ReadSequence(temp, &head);
	DER_ITCAST_FreeQueue(temp);
	next = head;

	//����name
	DER_ItAsn1_ReadPrintableString(next, &temp);
	memcpy(pt->name, temp->pData, temp->dataLen);
	DER_ITCAST_FreeQueue(temp);
	next = next->next;

	//����age
	//�˴�������Decode����Ϊ����������Ϊ��ֵ
	DER_ItAsn1_ReadInteger(next, &pt->age);
	next = next->next;

	//����p
	int len = 0;
	DecodeChar(next, &pt->p, &len);
	next = next->next;

	//����plen
	DER_ItAsn1_ReadInteger(next, &pt->plen);

	//�����������ֵ
	*p = pt;

	//�ͷ��ڴ�
	DER_ITCAST_FreeQueue(head);

	return 0;
}

void freeTeacher(Teacher ** p)
{
	if (*p != NULL)
	{
		if ((*p)->p != NULL)
		{
			free((*p)->p);
		}
		free((*p));
	}
}
