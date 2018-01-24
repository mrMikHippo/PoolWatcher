/*
 * HTTPHeader.h
 *
 *  Created on: Jan 24, 2018
 *      Author: hippo
 */

#ifndef HTTPHEADER_H_
#define HTTPHEADER_H_

#include <string>
#include<vector>

const std::vector<std::string> tokens = { "HTTP", "Cache-Control", "Content-Type",
										"Referrer-Policy", "Location", "Content-Length", "Date"};

class HTTPHeader {
	std::string  version_http;	// http version
	int			 status = 0;	// page status
	std::string  location;		// redirect
	int			 content_length = 0; // content length
	std::string  date;			// date
	std::string  content_type;	// text/html or another
	std::string  server;		// nginx or another

public:
	HTTPHeader();
	virtual ~HTTPHeader();
	void parse(std::string data);
};

#endif /* HTTPHEADER_H_ */
