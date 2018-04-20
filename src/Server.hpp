#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <cctype>
#include <algorithm>

#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>

using namespace std;

class Server {
public:
	virtual void Start() =0;
	void parse(char *, int);
protected:
	virtual void handle() = 0;

	int m_Port;
	int hsock;
	uint16_t avail_bytes;
};

class TcpServer : public Server {
public:
	TcpServer(int Port);
	~TcpServer();
	void Start();
private:
	void handle();
};

class UdpServer : public Server {
public:
	UdpServer(int Port);
	~UdpServer();
	void Start();
private:
	void handle();
};
