//#include<iostream>
//#include<deque>
//using namespace std;
///*
//	2016-03-07
//	deque insert, erase ����
//*/
//
//struct Packet
//{
//	unsigned short index;	// ��Ŷ �ε���
//	unsigned short bodySize;	// ��Ŷbody(���� ������)�� ũ��
//	char acBodyData[100];	// ��Ŷ�� ������
//};
//
//void main()
//{
//		Packet pk1,pk2, pk3, pk4;
//		pk1.index = 1; 
//		pk1.bodySize = 10;
//	
//		pk2.index = 2;
//		pk2.bodySize = 12;
//	
//		pk3.index = 3;
//		pk3.bodySize = 14;
//
//		pk4.index = 4;
//		pk4.bodySize = 16;
//
//		deque<Packet> ReceivePackets;
//		ReceivePackets.push_back(pk1);
//		ReceivePackets.push_back(pk2);
//		ReceivePackets.push_back(pk3);
//
//		cout << "<INSERT >" << endl;
//
//		// ù ��° ��ġ�� pk3�� ����
//		ReceivePackets.insert(ReceivePackets.begin(), pk3);
//		
//		for (deque<Packet>::iterator iter = ReceivePackets.begin(); iter != ReceivePackets.end(); iter++)
//		{
//			cout << "��Ŷ �ε��� : " << iter->index << endl;
//			cout << "��Ŷ ũ�� : " << iter->bodySize << endl;
//		}
//
//		// �� ��° ��ġ�� pk4�� 2�� ����
//		cout << endl << "Insert 2 " << endl;
//		ReceivePackets.insert(++ReceivePackets.begin(),2, pk4);
//
//		for (deque<Packet>::iterator iter = ReceivePackets.begin(); iter != ReceivePackets.end(); iter++)
//		{
//			cout << "��Ŷ �ε��� : " << iter->index << endl;
//			cout << "��Ŷ ũ�� : " << iter->bodySize << endl;
//		}
//
//		cout << endl << "Insert 3 " << endl;
//		deque<Packet> ReceivePacket2;
//		ReceivePacket2.push_back(pk3);
//		ReceivePacket2.push_back(pk4);
//		ReceivePacket2.push_back(pk1);
//
//		// ReceivePacket2�� receivePacket�� ù ��°�� ����
//		ReceivePackets.insert(ReceivePackets.begin(), ReceivePacket2.begin(), ReceivePacket2.end());
//		for (deque<Packet>::iterator iter = ReceivePackets.begin(); iter != ReceivePackets.end(); iter++)
//		{
//			cout << "��Ŷ �ε��� : " << iter->index << endl;
//			cout << "��Ŷ ũ�� : " << iter->bodySize << endl;
//		}
//
//		cout << endl << "< erase >" << endl;
//		// �� ��° ���Ҹ� �����Ѵ�.
//		cout << "erase 1" << endl;
//		ReceivePackets.erase(++ReceivePackets.begin());
//		for (deque<Packet>::iterator iter = ReceivePackets.begin(); iter != ReceivePackets.end(); iter++)
//		{
//			cout << "��Ŷ �ε��� : " << iter->index << endl;
//			cout << "��Ŷ ũ�� : " << iter->bodySize << endl;
//		}
//
//		//�� ��° ���ĺ��� ��� �����Ѵ�
//		cout << endl << "erase 2" << endl;
//		ReceivePackets.erase(++ReceivePackets.begin(), ReceivePackets.end());
//		for (deque<Packet>::iterator iter = ReceivePackets.begin(); iter != ReceivePackets.end(); iter++)
//		{
//			cout << "��Ŷ �ε��� : " << iter->index << endl;
//			cout << "��Ŷ ũ�� : " << iter->bodySize << endl;
//		}
//
//		system("pause");
//}