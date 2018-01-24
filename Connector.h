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
	mutable int err = 1;

public:
	Connector();
	virtual ~Connector();
	void Connect();
	void Send(std::string header);
	std::string Receive();
	void Close();
	bool IsError() const { return !err; }

private:
	void printRequest(bool recv, const std::string str) const;
};

#endif /* CONNECTOR_H_ */
