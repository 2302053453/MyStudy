//#include<iostream>
//#include<deque>
//using namespace std;
///*
//	2016-03-07
//	deque 예제
//*/
//
//// 서버/클라이언트간에 주고 받는 패킷
//struct Packet
//{
//	unsigned short index;	// 패킷 인덱스
//	unsigned short bodySize;	// 패킷body(실제 데이터)의 크기
//	char acBodyData[100];	// 패킷의 데이터
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
//	// 뒤에 추가
//	ReceivePackets.push_back(pk2);
//	ReceivePackets.push_back(pk3);
//	ReceivePackets.push_front(pk1);
//
//	for (deque<Packet>::iterator iter = ReceivePackets.begin(); iter != ReceivePackets.end(); iter++)
//	{
//		cout << "패킷 인덱스 : " << iter->index << endl;
//		cout << "패킷 크기 : " << iter->bodySize << endl;
//	}
//
//	cout << endl << "역방향으로 출력" << endl;
//
//	for (deque<Packet>::reverse_iterator iter = ReceivePackets.rbegin(); iter != ReceivePackets.rend(); iter++)
//	{
//		cout << "패킷 인덱스 : " << iter->index << endl;
//		cout << "패킷 크기 : " << iter->bodySize << endl;
//	}
//
//	cout << endl << "배열 방식으로 접근" << endl;
//	// 저장된 총 패킷 수
//	int ReceivePacketCount = ReceivePackets.size();
//	cout << "총 패킷 수: " << ReceivePacketCount << endl;
//	for (int i = 0; i < ReceivePacketCount; ++i)
//	{
//		cout << "패킷 인덱스: " << ReceivePackets[i].index << endl;
//		cout << "패킷 바디 크기: " << ReceivePackets[i].bodySize << endl;
//	}
//	
//	// 첫 번째, 마지막 위치에 있는 패킷
//	Packet& FirstPacket = ReceivePackets.front();
//	cout << "첫 번째 패킷의 인덱스: " << FirstPacket.index << endl;
//	Packet& LastPacket = ReceivePackets.back();
//	cout << "마지막 패킷의 인덱스: " << LastPacket.index << endl;
//
//	// at을 사용하여 두 번째 패킷
//	Packet& PacketAt = ReceivePackets.at(1);
//	cout << "두 번째 패킷의 인덱스: " << PacketAt.index << endl;
//
//	// 첫 번째 패킷 삭제
//	ReceivePackets.pop_front();
//	cout << "첫 번째 패킷의 인덱스: " << ReceivePackets[0].index << endl;
//
//	// 마지막패킷삭제
//	ReceivePackets.pop_back();
//	LastPacket = ReceivePackets.back();
//	cout << "마지막 패킷의 인덱스: " << LastPacket.index << endl;
//	
//	// 모든 패킷을 삭제
//	if (false == ReceivePackets.empty())
//	{
//		cout << "모든 패킷을 삭제합니다." << endl;
//		ReceivePackets.clear();
//	}
//}