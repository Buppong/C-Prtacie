#define _WINSOCK_DEPRECATED_NO_WARNINGS //��ü�Ǿ��ų� �����ؼ� ����϶�� ���̴�.
#include<iostream> 
#include<string>
#include<WinSock2.h>

using namespace std;



void ShowErrorMessage(string message) {

	cout <<"[�����߻�]:" << message << '\n';
	system("pause");
	exit(1);
}

int main()
{
	WSADATA wsaData;
	SOCKET clientSocket; // �����ּҸ� ������
	SOCKADDR_IN serverAddress; //�����ּҸ� ������ؼ�

	int severPort = 9876; //������������Ʈ�� ����ؾ���
	char received[256]; 
	string sent;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) //WINsock�� �ʱ�ȭ�մϴ�.
		ShowErrorMessage("WSAStartup()");

	clientSocket = socket(PF_INET, SOCK_STREAM, 0); //tcp ������ �����մϴ�.

	if (clientSocket == INVALID_SOCKET)
		ShowErrorMessage("socket()");

	memset(&serverAddress, 0, sizeof(serverAddress)); // �����ּҸ� 0���� �ʱ�ȭ�����Ŀ� ������ ���������� ����־���.
	serverAddress.sin_family= AF_INET;
	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); //���ڿ� IP�� ��Ʈ��ũ ����Ʈ ��������
	serverAddress.sin_port = htons(severPort); //2����Ʈ ���� ��Ʈ��ũ ����Ʈ ��������
	if (connect(clientSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
		ShowErrorMessage("connect()");
	cout << "[���� ����] connect()\n";

	while (1) {	//�ݺ������� ������ �޽����� �����ϰ� ���� �޽����� ���� �޽��ϴ�.
		cout << "[�޽�������]";
		getline(cin, sent);
		if (sent == "") continue;
		send(clientSocket, sent.c_str(), sent.length(), 0);
		int length = recv(clientSocket, received, sizeof(received), 0);
		received[length] = '\0';
		if (strcmp(received, "[exit]") == 0) {
			cout << "[���� �޽���]:" << received << '\n';
			break;
		}
		cout << "[���� �޽���]" << received << '\n';
	}

	closesocket(clientSocket);
	WSACleanup();
	system("pause");
	return 0;




}