#include <iostream>
#include <string>
#include <winsock2.h>


using namespace std;

/*소켓프로그래밍 함수와 Winsock2 소켓프로그래밍을 위한 함수에 대해서 이해할수있습니ㅣ다.

socket()


*/

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

if (WSAStartup) {

	test
}

