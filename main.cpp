#include <cstdio>

#include "Connector.h"

//#include "PageData.h"

int main(int argc, char *argv[])
{

	Connector sock_conn;

	sock_conn.Connect();

	sock_conn.Send();
	sock_conn.Receive();

//	string user_agent = "Mozilla/5.0 (Windows NT 6.2; WOW64; rv:31.0) Gecko/20100101 Firefox/31.0";
//	string accept_type = "Accept: text/thml, application/xhtml+xml\r\n";
//	string encoding = "Accept-Encoding: gzip, deflate\r\n";
//	string proxy_conn = "Proxy-Connection: Keep-Alive\r\n";

	printf("Goodbye!\n");
	return 0;
}
