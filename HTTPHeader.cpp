/*
 * HTTPHeader.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: hippo
 */

#include "HTTPHeader.h"

using std::string;
using std::vector;

HTTPHeader::HTTPHeader() {
}

HTTPHeader::~HTTPHeader() {
}

void HTTPHeader::parse(string data)
{

	for (auto &token : tokens) {
		size_t pos = data.find(token);
		if (pos != string::npos) {
			printf("\"%s\" found\n", token.c_str());
		}
	}
}

