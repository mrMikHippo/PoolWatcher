/*
 * PageData.cpp
 *
 *  Created on: Dec 15, 2017
 *      Author: hippo
 */

#include "PageData.h"
#include <string.h>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>

#define RN_SEQUENCE_LENGTH	4

using namespace std;


void PageData::Parse(string &data)
{
	printf("Parsing page data:\n");
	// Start point of content
	size_t spcontent = data.find(SEPARATE_SYMS);
	if (spcontent != string::npos) {
		printf("\"\\r\\n\\r\\n\" sequence found\n");
		spcontent += RN_SEQUENCE_LENGTH;
		printf("Start point of content = %ld\n", spcontent);

		header.parse(data.substr(0, spcontent));
		// TODO save and parse page
		content = data.substr(spcontent);
	} else {
		// TODO what if not found sequence
		printf("ERROR separate sequence not found\n");
	}
}

void PageData::PrintData(std::string &data)
{
	for (auto tok : data) {
		if (tok == '\r') continue;
		printf("%c", tok);
	}
}

//void PageData::ParseHTMLContent(string &data)
//{
//	printf("Page Content:\n");
//	PrintData(data);
//	//	string start_tokens[] = {"<doctype", "<html"};
//	//	vector<string> start_tokens_v = {"<doctype", "<html"};
//	//	vector<string>::iterator it;
//}


