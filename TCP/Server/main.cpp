#include <iostream>
#include <string>
#include <winsock2.h>


using namespace std;

void ShowErrorMessage(string message) {

	cout << "{오류발생}:" << message << '\n';
	system("pause");
	exit(1);
}


int main() {

	WSDATA wsaData;
	SOCKET serverSocket, clientSocket;
	SOCKADDR_IN severAddress, client Address;
}

int SeverPort = 9876;
char received[256];

if(WSAStartup)