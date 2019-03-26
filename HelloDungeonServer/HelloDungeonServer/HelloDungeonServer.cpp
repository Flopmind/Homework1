// HelloDungeonServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Socket.h"

// socket library inclusion for windows
#include <WinSock2.h>
// link to the winsock library to get socket functionality
#pragma comment(lib, "wsock32.lib")

const int X = 256;

struct command
{
	unsigned char cmd;
	// 256 commands for now
	char payload[X];
	// Some payload based on the command
};
struct status
{
	unsigned char status;
	// 256 status types for now
	char payload[X];
	// Some payload based on the command
};

//bool InitializeSockets()
//{
//	WSADATA WsaData;
//	return WSAStartup(MAKEWORD(2, 2), &WsaData) == NO_ERROR;
//}
//
//void ShutdownSockets()
//{
//	WSACleanup();
//}
//
//bool CreateSocket()
//{
//	//create socket
//	int handle = socket(AF_INET,
//		SOCK_DGRAM,
//		IPPROTO_UDP);
//
//	if (handle <= 0)
//	{
//		printf("failed to create socket\n");
//		return false;
//	}
//
//	// port stuff
//	sockaddr_in address;
//	address.sin_family = AF_INET;
//	address.sin_addr.s_addr = INADDR_ANY;
//	address.sin_port =
//		// Endian-fixing magical nonsense
//		htons((unsigned short)port);
//
//	if (bind(handle,
//		(const sockaddr*)&address,
//		sizeof(sockaddr_in)) < 0)
//	{
//		printf("failed to bind socket\n");
//		return false;
//	}
//	// set port to non-blocking mode
//	DWORD nonBlocking = 1;
//	if (ioctlsocket(handle,
//		FIONBIO,
//		&nonBlocking) != 0)
//	{
//		printf("failed to set non-blocking\n");
//		return false;
//	}
//
//	// send packet
//	int sent_bytes =
//		sendto(handle,
//		(const char*)packet_data,
//			packet_size,
//			0,
//			(sockaddr*)&address,
//			sizeof(sockaddr_in));
//
//	if (sent_bytes != packet_size)
//	{
//		printf("failed to send packet\n");
//		return false;
//	}
//
//	// set up address
//	unsigned int a = 207;
//	unsigned int b = 45;
//	unsigned int c = 186;
//	unsigned int d = 98;
//	unsigned short port = 30000;
//
//	// configure for sendto
//	unsigned int address =	(a << 24) |
//							(b << 16) |
//							(c << 8 ) |
//							 d;
//
//	sockaddr_in addr;
//	addr.sin_family = AF_INET;
//	addr.sin_addr.s_addr = htonl(address);
//	addr.sin_port = htons(port);
//
//	// receive packets loop
//	while (true)
//	{
//		unsigned char packet_data[256];
//
//		unsigned int max_packet_size =
//			sizeof(packet_data);
//
//		typedef int socklen_t;
//
//		sockaddr_in from;
//		socklen_t fromLength = sizeof(from);
//
//		int bytes = recvfrom(handle,
//			(char*)packet_data,
//			max_packet_size,
//			0,
//			(sockaddr*)&from,
//			&fromLength);
//
//		if (bytes <= 0)
//			break;
//
//		unsigned int from_address =
//			ntohl(from.sin_addr.s_addr);
//
//		unsigned int from_port =
//			ntohs(from.sin_port);
//
//		// process received packet
//	}
//
//	// receive packets
//
//	while (true)
//	{
//		Address sender;
//		unsigned char buffer[256];
//		int bytes_read =
//			socket.Receive(sender,
//				buffer,
//				sizeof(buffer));
//		if (!bytes_read)
//			break;
//
//		// process packet
//	}
//
//	//Destroy Socket
//	closesocket(handle);
//}

int main()
{
	//Address myAddress = Address();
	Socket mySocket = Socket();


	const int port = 30000;

	if (!mySocket.Open(Address(127, 0, 0, 1, 30000).GetPort()))
	{
		printf("failed to create socket!\n");
		return false;
	}

	// receive packets

	while (true)
	{
		Address sender;
		unsigned char buffer[256];
		int bytes_read = mySocket.Receive(sender, buffer, sizeof(buffer));
		if (!bytes_read)
			break;

		// process packet
		if (((const char*)buffer)[0] == 'h' || buffer[0] == 'h')
		{
			printf((const char*)buffer);
		}

		Sleep(200);
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
