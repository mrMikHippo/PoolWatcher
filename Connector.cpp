/*
 * Connector.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: hippo
 */
#include "Connector.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h> // for inet_ntop

Connector::Connector()
{
}

Connector::~Connector()
{
	Close();
}

void Connector::Connect()
{
	struct addrinfo hints, *servinfo;
	char ipstr[INET_ADDRSTRLEN];

	printf("Connection with %s\n", HOST_GOOGLE);

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;		// IPv4
	hints.ai_socktype = SOCK_STREAM; // TCP stream-sockets
	err = getaddrinfo(HOST_GOOGLE, SERVICE, &hints, &servinfo);
	if (err) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
		return;
	}

	// Get ip address
	struct sockaddr_in *saddr = (struct sockaddr_in *) servinfo->ai_addr;
	if (inet_ntop(servinfo->ai_family, &saddr->sin_addr, ipstr, sizeof(ipstr)) == NULL)
		printf("Can't get ip address\n");
	printf(" ( %s )\n", ipstr);

	sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
	if (sockfd < 0) {
		perror("socket");
		err = 0;
		freeaddrinfo(servinfo); // Free the linked list
	}

	if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) < 0) {
		perror("connect");
		err = 0;
	}

	freeaddrinfo(servinfo); // Free the linked list
}

void Connector::Close()
{
	if (sockfd) close(sockfd);
	err = 1;
}

void Connector::Send()
{
	ssize_t n;
	std::string header;
		header = "GET / HTTP/1.0\r\n";
		header += "Host: " + std::string(HOST_GOOGLE) + "\r\n";
		header += "User-Agent: Mozilla-Firefox\r\n";
		header += "Accept: */*\r\n\r\n";

	if (sockfd < 0) {
		printf("Hmm...Socket is closed. I can't send data\n");
		return;
	}
	n = send(sockfd, header.data(), header.length(), 0);
	if (n < 0) {
		printf("Error send\n");
		return;
	}
	printf("write=%ld bytes\n", n);
	printRequest(true, header);
}

std::string Connector::Receive()
{
	ssize_t n;
	char rbuf[1024];

	if (sockfd < 0) {
		printf("Hmm...Socket is closed. I can't receive data\n");
		return "";
	}
	memset(rbuf, 0, sizeof(rbuf));
	n = recv(sockfd, rbuf, sizeof(rbuf), 0);
	if (n < 0) {
		printf("Error recv");
		err = 1;
		return "";
	}
	printf("read=%ld bytes\n", n);
	printRequest(false, rbuf);
	return rbuf;
}

void Connector::printRequest(bool recv, const std::string str) const
{
	printf("%3d%c ", 0, (recv ? '>' : '<'));
	for (size_t i = 0, j = 1; i < str.length(); i++) {
		char k = str.at(i);
		if (k == '\r') continue;
		else if (k == '\n') {
			printf("\n%3ld%c ", j++, (recv ? '>' : '<'));
		} else printf("%c", k);
		fflush(stdout);
	}
	printf("\n");
}
