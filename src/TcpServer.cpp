#include "Server.hpp"

void TcpServer::Start() {
	struct sockaddr_in my_addr;

	hsock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (hsock == -1) {
		cerr << "Error initializing TCP server socket" << endl;
		exit(1);
	}

	memset(&my_addr, 0, sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(TcpServer::m_Port);
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(hsock, (sockaddr*)&my_addr, sizeof(my_addr)) == -1) {
		cerr << "Error binding to TCP server socket" << endl;
		exit(1);
	}
	if (listen(hsock, 10) == -1) {
		cerr << "Error listening socket" << endl;
		exit(1);
	}

	TcpServer::handle();

}

void TcpServer::handle() {
	int sockfd;
	struct sockaddr_in client_addr;
	unsigned int addrlen = sizeof(client_addr);
	char buf[1024];

	while(true) {
		if ((sockfd = accept(hsock, (sockaddr*)&client_addr, &addrlen)) == -1) {
			cerr << "Error accept" << endl;
			exit(1);
		}
		else {
			cout << "Client connected from " << inet_ntoa(client_addr.sin_addr) << " TCP protocol" << endl;

			while(true) {
				memset(buf, 0, sizeof(buf));
				avail_bytes = recv(sockfd, buf, 1024, 0);
				if (avail_bytes <= 0) {
					break;
				}
				parse(buf, avail_bytes);
				send(sockfd, buf, avail_bytes, 0);
			}
			shutdown(sockfd, SHUT_RDWR);
			close(sockfd);
		}
	}
}

TcpServer::TcpServer (int Port) {
	m_Port = Port;
	avail_bytes = 0;
}

TcpServer::~TcpServer() {

}


