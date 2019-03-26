#include "pch.h"
#include "Address.h"

// socket library inclusion for windows
#include <WinSock2.h>
// link to the winsock library to get socket functionality
#pragma comment(lib, "wsock32.lib")

Address::Address()
{
	unsigned int a = 207;
	unsigned int b = 45;
	unsigned int c = 186;
	unsigned int d = 98;
	this->port = 30000;

	// configure for sendto
	address = (a << 24) |
		(b << 16) |
		(c << 8) |
		d;

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(address);
	addr.sin_port = htons(port);
}

Address::Address(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned short port)
{
	// set up address
	// configure for sendto
	address = (a << 24) |
		(b << 16) |
		(c << 8) |
		d;

	this->port = port;

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(address);
	addr.sin_port = htons(port);
}

Address::Address(unsigned int address, unsigned short port)
{
	this->address = address;
	this->port = port;
}

unsigned int Address::GetAddress() const
{
	return this->address;
}

//unsigned char Address::GetA() const
//{
//	return this->;
//}
//
//unsigned char Address::GetB() const
//{
//	return this->;
//}
//
//unsigned char Address::GetC() const
//{
//	return this->;
//}
//
//unsigned char Address::GetD() const
//{
//	return this->;
//}

unsigned short Address::GetPort() const
{
	return this->port;
}