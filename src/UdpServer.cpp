#include "Server.hpp"

void UdpServer::Start() {
	struct sockaddr_in my_addr;

	hsock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (hsock == -1) {
		cerr << "Error initializing UDP server socket" << endl;
		exit(1);
	}

	memset(&my_addr, 0, sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(UdpServer::m_Port);
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(hsock, (sockaddr*)&my_addr, sizeof(my_addr)) == -1) {
		cerr << "Error binding to UDP socket" << endl;
		exit(1);
	}

	UdpServer::handle();

}

void UdpServer::handle() {
	struct sockaddr_in client_addr;
	unsigned int address_len;
	char buf[1024];

	address_len = sizeof(client_addr);

	while(true) {
		avail_bytes = recvfrom(hsock, buf, 1024, 0, (struct sockaddr*)&client_addr, &address_len);

		if (avail_bytes <= 0) {
			cerr << "Error receive UDP Datagrams" << endl;
		}
		else {
			parse(buf, avail_bytes);
			sendto(hsock, buf, avail_bytes, 0, (struct sockaddr*)&client_addr, address_len);
		}
	}
}

UdpServer::UdpServer (int Port) {
	m_Port = Port;
	avail_bytes = 0;
}

UdpServer::~UdpServer() {

}




