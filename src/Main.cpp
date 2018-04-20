/*==========================================================================
Name        : Server.cpp
Author      : Denis Z
Version     :
Description : TCP and UDP server
============================================================================*/

#include <thread>
#include "Server.hpp"

#define tcp_port 5555
#define udp_port 5556

void tcp_f() {
	TcpServer tcp_server(tcp_port);
	tcp_server.Start();
}

void udp_f() {
	UdpServer udp_server(udp_port);
	udp_server.Start();
}

int main() {
	thread tcp_t(tcp_f);
	thread udp_t(udp_f);

	while(true) {
		/*something code*/
		usleep(500000);
	}

	return 0;
}




