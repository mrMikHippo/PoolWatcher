/*
 * PageData.cpp
 *
 *  Created on: Dec 15, 2017
 *      Author: hippo
 */

#include "PageData.h"
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

void PageData::Separate(string &data)
{
	string separate_symbols = "\r\n\r\n";
	size_t start_content = data.find(separate_symbols);
	if (start_content != string::npos) {
		printf("\"\\r\\n\\r\\n\" sequence found\n");
		start_content += 4;
		printf("Start content = %ld\n", start_content);
		string header = data.substr(0, start_content);
		string content = data.substr(start_content);
		ParseHTTPHeader(header);
		ParseHTMLContent(content);
	} else {
		// TODO what if not found sequence
		printf("separate sequence not found\n");
	}
}

void PageData::ParseHTTPHeader(string &data)
{
	printf("Parse HTTP Header\n%s\n", data.c_str());
}

void PageData::ParseHTMLContent(string &data)
{
	printf("Page Content\n%s\n", data.c_str());
	//	string start_tokens[] = {"<doctype", "<html"};
	//	vector<string> start_tokens_v = {"<doctype", "<html"};
	//	vector<string>::iterator it;
}


