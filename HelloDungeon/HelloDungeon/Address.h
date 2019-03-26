#pragma once

#include <WinSock2.h>

class Address
{
public:

	Address();

	Address(unsigned char a,
		unsigned char b,
		unsigned char c,
		unsigned char d,
		unsigned short port);

	Address(unsigned int address,
		unsigned short port);

	unsigned int GetAddress() const;

	const sockaddr GetAddr() const;

	unsigned char GetA() const;
	unsigned char GetB() const;
	unsigned char GetC() const;
	unsigned char GetD() const;


	unsigned short GetPort() const;

private:

	unsigned int address;
	unsigned short port;
	sockaddr_in addr;
};

