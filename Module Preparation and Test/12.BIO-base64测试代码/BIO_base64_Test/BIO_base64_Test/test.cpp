#include <iostream>
#include <string>
#include <stdlib.h>  
#include <openssl/rsa.h>
#include <openssl/pem.h>
using namespace std;


void WriteEncode()
{
	char  data[] = "hello, world";
	// ����base64�����bio����
	BIO* b64 = BIO_new(BIO_f_base64());

	// �������ڴ��еõ�һ��base64����֮����ַ���
	BIO* mem = BIO_new(BIO_s_mem());

	// ������bio������, �ṹ: b64->mem
	BIO_push(b64, mem);

	// ��Ҫ���������д�뵽bio������
	BIO_write(b64, &data, strlen(data) + 1);

	// �����ݴ�bio�����Ӧ���ڴ���ȡ�� -> char*
	BUF_MEM* ptr = NULL;

	// ����ͨ��ptrָ�봫��
	BIO_get_mem_ptr(b64, &ptr);
	char* buf = new char[ptr->length+1];
	memcpy(buf, ptr->data, ptr->length);

	printf("����֮�������: %s\n", buf);
	printf("==============================\n");

}

void ReadDecode()
{
	// Ҫ���������
	char  data[] = "Good evening, California";
	// ����base64�����bio����
	BIO* b64 = BIO_new(BIO_f_base64());

#if 0
	// �洢Ҫ���������
	BIO* mem = BIO_new(BIO_s_mem());
	// ������д��mem��Ӧ���ڴ���
	BIO_write(mem, data, strlen(data));
#else
	BIO* mem = BIO_new_mem_buf(&data, strlen(data) + 1);
#endif
	// ��֯bio��
	BIO_push(b64, mem);
	// ������
	char buf[1024];
	BIO_read(b64, buf, 1024);
	printf("base64��������ݣ�%s\n", buf);
}


// ����
char* Base64Encode(char* input, int length)
{
	BIO* bmem = NULL;
	BIO* b64 = NULL;
	BUF_MEM* bptr = NULL;
	b64 = BIO_new(BIO_f_base64());

	bmem = BIO_new(BIO_s_mem());
	b64 = BIO_push(b64, bmem);
	BIO_write(b64, input, length);
	BIO_flush(b64);
	BIO_get_mem_ptr(b64, &bptr);
	char* buff = (char*)malloc(bptr->length + 1);
	memcpy(buff, bptr->data, bptr->length);
	buff[bptr->length] = 0;
	BIO_free_all(b64);
	return buff;
}

// ����
char* Base64Decode(char* input, int length)
{
	BIO* b64 = NULL;
	BIO* bmem = NULL;
	char* buffer = (char*)malloc(length);
	memset(buffer, 0, length);
	b64 = BIO_new(BIO_f_base64());
	bmem = BIO_new_mem_buf(input, length);
	bmem = BIO_push(b64, bmem);
	BIO_read(bmem, buffer, length);
	BIO_free_all(bmem);
	return buffer;
}

int main()
{
	
	WriteEncode();
	ReadDecode();
	
	char data[] = "hello, world";
	char*  str = Base64Encode(data, strlen(data)+1);
	printf("\n������____�������ַ���Ϊ��%s \n", str);
	return 0;
}