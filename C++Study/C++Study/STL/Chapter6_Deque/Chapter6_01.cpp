//#include<iostream>
//#include<deque>
//using namespace std;
///*
//	2016-03-07
//	deque ����
//*/
//
//// ����/Ŭ���̾�Ʈ���� �ְ� �޴� ��Ŷ
//struct Packet
//{
//	unsigned short index;	// ��Ŷ �ε���
//	unsigned short bodySize;	// ��Ŷbody(���� ������)�� ũ��
//	char acBodyData[100];	// ��Ŷ�� ������
//};
//
//void main()
//{
//	Packet pk1,pk2, pk3;
//	pk1.index = 1; 
//	pk1.bodySize = 10;
//
//	pk2.index = 2;
//	pk2.bodySize = 12;
//
//	pk3.index = 3;
//	pk3.bodySize = 14;
//
//	deque<Packet> ReceivePackets;
//
//	// �ڿ� �߰�
//	ReceivePackets.push_back(pk2);
//	ReceivePackets.push_back(pk3);
//	ReceivePackets.push_front(pk1);
//
//	for (deque<Packet>::iterator iter = ReceivePackets.begin(); iter != ReceivePackets.end(); iter++)
//	{
//		cout << "��Ŷ �ε��� : " << iter->index << endl;
//		cout << "��Ŷ ũ�� : " << iter->bodySize << endl;
//	}
//
//	cout << endl << "���������� ���" << endl;
//
//	for (deque<Packet>::reverse_iterator iter = ReceivePackets.rbegin(); iter != ReceivePackets.rend(); iter++)
//	{
//		cout << "��Ŷ �ε��� : " << iter->index << endl;
//		cout << "��Ŷ ũ�� : " << iter->bodySize << endl;
//	}
//
//	cout << endl << "�迭 ������� ����" << endl;
//	// ����� �� ��Ŷ ��
//	int ReceivePacketCount = ReceivePackets.size();
//	cout << "�� ��Ŷ ��: " << ReceivePacketCount << endl;
//	for (int i = 0; i < ReceivePacketCount; ++i)
//	{
//		cout << "��Ŷ �ε���: " << ReceivePackets[i].index << endl;
//		cout << "��Ŷ �ٵ� ũ��: " << ReceivePackets[i].bodySize << endl;
//	}
//	
//	// ù ��°, ������ ��ġ�� �ִ� ��Ŷ
//	Packet& FirstPacket = ReceivePackets.front();
//	cout << "ù ��° ��Ŷ�� �ε���: " << FirstPacket.index << endl;
//	Packet& LastPacket = ReceivePackets.back();
//	cout << "������ ��Ŷ�� �ε���: " << LastPacket.index << endl;
//
//	// at�� ����Ͽ� �� ��° ��Ŷ
//	Packet& PacketAt = ReceivePackets.at(1);
//	cout << "�� ��° ��Ŷ�� �ε���: " << PacketAt.index << endl;
//
//	// ù ��° ��Ŷ ����
//	ReceivePackets.pop_front();
//	cout << "ù ��° ��Ŷ�� �ε���: " << ReceivePackets[0].index << endl;
//
//	// ��������Ŷ����
//	ReceivePackets.pop_back();
//	LastPacket = ReceivePackets.back();
//	cout << "������ ��Ŷ�� �ε���: " << LastPacket.index << endl;
//	
//	// ��� ��Ŷ�� ����
//	if (false == ReceivePackets.empty())
//	{
//		cout << "��� ��Ŷ�� �����մϴ�." << endl;
//		ReceivePackets.clear();
//	}
//}