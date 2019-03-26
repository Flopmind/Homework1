#include "pch.h"
#include "Socket.h"

#include <iostream>
// socket library inclusion for windows
#include <WinSock2.h>
// link to the winsock library to get socket functionality
#pragma comment(lib, "wsock32.lib")

Socket::Socket()
{
	WSADATA WsaData;
	WSAStartup(MAKEWORD(2, 2), &WsaData);

	handle = socket(AF_INET,
		SOCK_DGRAM,
		IPPROTO_UDP);

	if (handle <= 0)
	{
		printf("failed to create socket\n");
	}
}

Socket::~Socket()
{
	Close();
	WSACleanup();
}

bool Socket::Open(unsigned short port)
{
	// port stuff
	sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port =
		// Endian-fixing magical nonsense
		htons((unsigned short)port);

	if (bind(handle,
		(const sockaddr*)&address,
		sizeof(sockaddr_in)) < 0)
	{
		printf("failed to bind socket\n");
		return false;
	}
	// set port to non-blocking mode
	DWORD nonBlocking = 1;
	if (ioctlsocket(handle,
		FIONBIO,
		&nonBlocking) != 0)
	{
		printf("failed to set non-blocking\n");
		return false;
	}
	return true;
}

void Socket::Close()
{
	closesocket(handle);
}

bool Socket::IsOpen() const
{
	return true;
}

bool Socket::Send(const Address & destination, const void * data, int size)
{
	int sent_bytes =
		sendto(handle,
		(const char*)data,
			size,
			0,
			(sockaddr*)&destination,
			sizeof(sockaddr_in));

	if (sent_bytes != size)
	{
		printf("failed to send packet\n");
		return false;
	}
	return true;
}

int Socket::Receive(Address &sender, void * data, int size)
{
	int fromLength = sizeof(sender);
	return recvfrom(handle, (char*)data, size, 0, (sockaddr*)&sender, &fromLength);

	// receive packets loop
	//while (true)
	//{
	//	unsigned char packet_data[256];

	//	unsigned int max_packet_size =
	//		sizeof(packet_data);

	//	typedef int socklen_t;

	//	sockaddr_in from;
	//	socklen_t fromLength = sizeof(from);

	//	int bytes = recvfrom(handle,
	//		(char*)packet_data,
	//		max_packet_size,
	//		0,
	//		(sockaddr*)&from,
	//		&fromLength);

	//	if (bytes <= 0)
	//		break;

	//	unsigned int from_address =
	//		ntohl(from.sin_addr.s_addr);

	//	unsigned int from_port =
	//		ntohs(from.sin_port);

	//	// process received packet
	//}
}