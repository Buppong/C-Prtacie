#include <iostream>
#include <string>
#include <winsock2.h>


using namespace std;


void ShowErrorMessage(string message) {

	cout << "{�����߻�}:" << message << '\n'; //�����޽����� ����ϰ�
	system("pause");
	exit(1); //���α׷��� ������
} 
//��Ʈ��ũ ���α׷����� ������Ȳ�� ���̳����ִµ� �׷��� �������� �ڵ鸵�Լ��� �ʼ��̴�.


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

