/*
 * PageData.h
 *
 *  Created on: Dec 15, 2017
 *      Author: hippo
 */

#ifndef PAGEDATA_H_
#define PAGEDATA_H_

#include <string>
#include "HTTPHeader.h"

const std::string SEPARATE_SYMS = "\r\n\r\n";

//struct HTTPheader {
//	std::string  version_http;	 // http version
//	int			 status;		 // page status
//	std::string  location;		 // redirect
//	int			 content_length; // content length
//	std::string  date;			 // date
//	std::string  content_type;	 // text/html or another
//	std::string  server;		 // nginx or another
//};

//class HTTPheader {
//	std::string  version_http;	// http version
//	int			 status = 0;	// page status
//	std::string  location;		// redirect
//	int			 content_length = 0; // content length
//	std::string  date;			// date
//	std::string  content_type;	// text/html or another
//	std::string  server;		// nginx or another
//
//public:
//	HTTPheader();
//	virtual ~HTTPheader() {}
//
//	void parseData(std::string data);
//
//private:
//
//};



class PageData {

	int error = 0;

	HTTPHeader header;		// instance header
	std::string content;	// instance content

public:
	PageData() {}
	virtual ~PageData() {}

	/* Separate data into HTTP header and HTML content */
	void Parse(std::string &data);

	void PrintData(std::string &data);

//	void GetPage(std::string &data) {
//		Separate(data);
//	}
//	HTTPheader GetHTTPHeader() const { return header; }

private:
	/* Separation of data into HTTP header and HTML content */
	void Separate(std::string &data);
	/* Parsing HTTP title */
//	void ParseHTTPHeader(std::string &data);
//	void ParseHTMLContent(std::string &data);

};

#endif /* PAGEDATA_H_ */
