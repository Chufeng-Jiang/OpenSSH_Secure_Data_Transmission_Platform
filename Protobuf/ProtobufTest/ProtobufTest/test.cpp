#include <iostream>
#include "Persion.pb.h"
using namespace std;
/*
	message Persion
	{
	int32 id = 1;   // ��Ŵ�1��ʼ
	string name = 2;
	string sex = 3;
	int32 age = 4;
	}
*/
int main()
{
	// 1. ����persion����, ����ʼ��
	Persion p;
	p.set_id(1001);
	// ����һ���ڴ�, �洢����
	p.add_name();
	p.set_name(0, "·��");
	p.set_sex("man");
	p.set_age(17);


	// 2. ��persion�������л� -> �ַ���
	string output;
	p.SerializeToString(&output);
	cout << "���л��������: " << output << endl;

	// 3. ���ݴ���

	// 4. ��������, ����(output) -> ���� -> ԭʼ����
	// 4.1 ����Persion����
	Persion pp;
	pp.ParseFromString(output);

	// ��Info����ֵȡ��

	// 5. ����ԭʼ���� -> ��ӡ������Ϣ
	cout << "id: " << pp.id() << ", name: "
		<< pp.name(0) << ", "
		<< ", sex: " << pp.sex() << ", age: " << pp.age()
		<< endl;

	return 0;
}