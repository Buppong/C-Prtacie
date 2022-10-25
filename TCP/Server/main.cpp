#include <iostream>
#include <string>
#include <winsock2.h>


using namespace std;


void ShowErrorMessage(string message) {

	cout << "{오류발생}:" << message << '\n'; //오류메시지를 출력하고
	system("pause");
	exit(1); //프로그램을 종료함
} 
//네트워크 프로그래밍은 오류상황이 많이날수있는데 그래서 오류관련 핸들링함수는 필수이다.


int main() {

	WSDATA wsaData;
	SOCKET serverSocket, clientSocket;
	SOCKADDR_IN severAddress, client Address;
}

int SeverPort = 9876;
char received[256];

if (WSAStartup) {

	ShowErrorMessage("WSAStartup()");

	serverSocket = socket(PF_IMET, SOCK_STREAM, 0);
}

