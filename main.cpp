#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h> // for inet_ntop
#include <string>

#include "PageData.h"


#define PORT 80
#define HOST_GOOGLE		"google.com"
#define NUM_BITS	8

using namespace std;

void error(const char *msg)
{
	perror(msg);
	exit(0);
}

void printRequest(bool recv, string str)
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


int main(int argc, char *argv[])
{
	struct sockaddr_in serv_addr;
	struct hostent *server;
	int sockfd = 0;
	ssize_t n;

//	string user_agent = "Mozilla/5.0 (Windows NT 6.2; WOW64; rv:31.0) Gecko/20100101 Firefox/31.0";
//	string accept_type = "Accept: text/thml, application/xhtml+xml\r\n";
//	string encoding = "Accept-Encoding: gzip, deflate\r\n";
//	string proxy_conn = "Proxy-Connection: Keep-Alive\r\n";

	bool run_tests = false;
	if (argc > 1) run_tests = true;

	if (run_tests) {
		printf("RUN TESTS!\n");
		PageData pdata;
		string data = "GET fluck\r\n"
						"Bla bla\r\n\r"
						"yoyo\r\n\r\n"
						"<html>\r\n"
						"</html>\r\n\r\n";
		pdata.GetPage(data);
		printf("Done\n");
		return 0;
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("Socket creation error\n");

	server = gethostbyname(HOST_GOOGLE);
	if (server == NULL) {
		fprintf(stderr, "ERROR, no such host\n");
		exit(0);
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	printf("server addr = %s\n", server->h_name);

	char a[80];
	memset(a, 0, sizeof(a));

	if (inet_ntop(AF_INET, server->h_addr_list[0], a, (server->h_length * NUM_BITS)) <= 0)
		error("Invalid address/ Address not supported\n");

	printf("addr = %s\n", a);
	bcopy(  (char *) server->h_addr_list[0],
			(char *)&serv_addr.sin_addr.s_addr,
			server->h_length);
//	strncpy((char *)&serv_addr.sin_addr.s_addr, (char *) server->h_addr_list[0], server->h_length);

	printf("Connecting...");
	if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("ERROR connecting");
	printf("[ OK ]\n");

	string str;
	str = "GET / HTTP/1.0\r\n";
	str += "Host: google.com\r\n";
	str += "User-Agent: Mozilla-Firefox\r\n";
	str += "Accept: */*\r\n\r\n";
//	str += "Connection: close\r\n\r\n";
	char rbuf[1024];

	n = send(sockfd, str.c_str(), str.length(), 0);

	if (n < 0) error("ERROR writing socket");
	printf("write=%ld bytes\n", n);
	printRequest(true, str);

	// TODO Make recieve Big data like 1MB
	n = recv(sockfd, rbuf, sizeof(rbuf), 0);
	if (n < 0) error("ERROR reading from socket");
	printf("read=%ld bytes\n", n);
	printRequest(false, rbuf);

	close(sockfd);
	printf("Goodbye!\n");
	return 0;
}
