/*
 * TESTPageData.h
 *
 *  Created on: Dec 15, 2017
 *      Author: hippo
 */

#ifndef TESTS_TESTPAGEDATA_H_
#define TESTS_TESTPAGEDATA_H_

//#include <string>
//#include "../PageData.h"
//
//class TEST_PageData : private PageData{
//	std::string data1 = "GET / HTTP/1.0\r\n"
//					"Host: google.com\r\n"
//					"User-Agent: Mozilla-Firefox\r\n"
//					"Accept: */*\r\n\r\n";
//	std::string data2 = "HTTP/1.0 302 Found\r\n"
//					"Cache-Control: private\r\n"
//					"Content-Type: text/html; charset=UTF-8\r\n"
//					"Referrer-Policy: no-referrer\r\n"
//					"Location: http://www.google.ru/?gfe_rd=cr&dcr=0&ei=RhA0WuCvKY7EXsX1m5AK\r\n"
//					"Content-Length: 266\r\n"
//					"Date: Fri, 15 Dec 2017 18:11:18 GMT\r\n\r\n"
//					"<HTML><HEAD><meta http-equiv=\"content-type\" content=\"text/html;charset=utf-8\">\r\n"
//					"<TITLE>302 Moved</TITLE></HEAD><BODY>\r\n"
//					"<H1>302 Moved</H1>\r\n"
//					"The document has moved\r\n"
//					"<A HREF=\"http://www.google.ru/?gfe_rd=cr&amp;dcr=0&amp;ei=RhA0WuCvKY7EXsX1m5AK\">here</A>.\r\n"
//					"</BODY></HTML>\r\n";
//	std::string data3 = "HTTP/1.1 403 Forbidden"
//					"Server: nginx\r\n"
//					"Date: Fri, 15 Dec 2017 18:14:03 GMT\r\n"
//					"Content-Type: text/html\r\n"
//					"Content-Length: 162\r\n"
//					"Connection: close\r\n"
//					"Vary: Accept-Encoding\r\n\r\n"
//					"<html>\r\n"
//					"<head><title>403 Forbidden</title></head>\r\n"
//					"<body bgcolor=\"white\">\r\n"
//					"<center><h1>403 Forbidden</h1></center>\r\n"
//					"<hr><center>nginx</center>\r\n"
//					"</body>\r\n"
//					"</html>\r\n"
//					"x\r\n";
//public:
//	TEST_PageData();
//	virtual ~TEST_PageData();
//
//	void TEST_GetPage();
//	void TEST_Separate(std::string &data);
//	void TEST_ParseHTTPHeader(std::string &data);
//	void TEST_ParseHTMLContent(std::string &data);
//
//
//};
//
//#endif /* TESTS_TESTPAGEDATA_H_ */
