//#include<iostream>
//#include<deque>
//using namespace std;
///*
//	2016-03-07
//	deque insert, erase 예제
//*/
//
//struct Packet
//{
//	unsigned short index;	// 패킷 인덱스
//	unsigned short bodySize;	// 패킷body(실제 데이터)의 크기
//	char acBodyData[100];	// 패킷의 데이터
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
//		// 첫 번째 위치에 pk3을 삽입
//		ReceivePackets.insert(ReceivePackets.begin(), pk3);
//		
//		for (deque<Packet>::iterator iter = ReceivePackets.begin(); iter != ReceivePackets.end(); iter++)
//		{
//			cout << "패킷 인덱스 : " << iter->index << endl;
//			cout << "패킷 크기 : " << iter->bodySize << endl;
//		}
//
//		// 두 번째 위치에 pk4를 2개 삽입
//		cout << endl << "Insert 2 " << endl;
//		ReceivePackets.insert(++ReceivePackets.begin(),2, pk4);
//
//		for (deque<Packet>::iterator iter = ReceivePackets.begin(); iter != ReceivePackets.end(); iter++)
//		{
//			cout << "패킷 인덱스 : " << iter->index << endl;
//			cout << "패킷 크기 : " << iter->bodySize << endl;
//		}
//
//		cout << endl << "Insert 3 " << endl;
//		deque<Packet> ReceivePacket2;
//		ReceivePacket2.push_back(pk3);
//		ReceivePacket2.push_back(pk4);
//		ReceivePacket2.push_back(pk1);
//
//		// ReceivePacket2를 receivePacket의 첫 번째에 삽입
//		ReceivePackets.insert(ReceivePackets.begin(), ReceivePacket2.begin(), ReceivePacket2.end());
//		for (deque<Packet>::iterator iter = ReceivePackets.begin(); iter != ReceivePackets.end(); iter++)
//		{
//			cout << "패킷 인덱스 : " << iter->index << endl;
//			cout << "패킷 크기 : " << iter->bodySize << endl;
//		}
//
//		cout << endl << "< erase >" << endl;
//		// 두 번째 원소를 삭제한다.
//		cout << "erase 1" << endl;
//		ReceivePackets.erase(++ReceivePackets.begin());
//		for (deque<Packet>::iterator iter = ReceivePackets.begin(); iter != ReceivePackets.end(); iter++)
//		{
//			cout << "패킷 인덱스 : " << iter->index << endl;
//			cout << "패킷 크기 : " << iter->bodySize << endl;
//		}
//
//		//두 번째 이후부터 모두 삭제한다
//		cout << endl << "erase 2" << endl;
//		ReceivePackets.erase(++ReceivePackets.begin(), ReceivePackets.end());
//		for (deque<Packet>::iterator iter = ReceivePackets.begin(); iter != ReceivePackets.end(); iter++)
//		{
//			cout << "패킷 인덱스 : " << iter->index << endl;
//			cout << "패킷 크기 : " << iter->bodySize << endl;
//		}
//
//		system("pause");
//}