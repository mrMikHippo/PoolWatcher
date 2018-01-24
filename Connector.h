/*
 * Connector.h
 *
 *  Created on: Jan 24, 2018
 *      Author: hippo
 */

#ifndef CONNECTOR_H_
#define CONNECTOR_H_

#include <string>

#define PORT 			80
#define HOST_GOOGLE		"google.com"
#define SERVICE			"http"

class Connector {
	int sockfd = -1;
	char rbuf[1024];
	int err = 1;

public:
	Connector();
	virtual ~Connector();
	void Connect();
	void Send();
	void Receive();
	void Close();
	bool GetError() { return !err; }

private:
	void printRequest(bool recv, std::string str);
};

#endif /* CONNECTOR_H_ */
