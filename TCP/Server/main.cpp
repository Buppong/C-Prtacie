#include <iostream>
#include <string>
#include <WinSock2.h>


using namespace std;


void ShowErrorMessage(string message) {

	cout << "{�����߻�}:" << message << '\n'; //�����޽����� ����ϰ�
	system("pause");
	exit(1); //���α׷��� ������
} 
//��Ʈ��ũ ���α׷����� ������Ȳ�� ���̳����ִµ� �׷��� �������� �ڵ鸵�Լ��� �ʼ��̴�.


int main() {

	WSADATA wsaData; //wsapi����ü�� �ϳ��� ������ ������־���.
	SOCKET serverSocket, clientSocket; //socket�� �ΰ��� �����θ������.
	SOCKADDR_IN serverAddress, clientAddress;

	int SeverPort = 9876; // ������Ʈ�� 9876�� ����Ѵ�
	char received[256]; //Ŭ���̾�Ʈ�� ������ ���ڿ�����ũ�⸦ 256���� �����Ͽ���.

	if (WSAStartup(MAKEWORD(2,2),&wsaData) !=0)//makeword��� �׷�ü�� �̿��ؼ� �����ϰ� ��ø� �صξ��� winsocke�� �ʱ�ȭ�մϴ�. ����� ���������� winsock api�� �����ֵ����Ͽ���.

		ShowErrorMessage("WSAStartup()"); //0�� �ƴ϶�� �����޽����� ����ϴ°��Դϴ�.

	serverSocket = socket(PF_INET, SOCK_STREAM, 0); //tcp ������ , ���������� �ʱ�ȭ���ݴϴ�
	
	if (serverSocket = INVALID_SOCKET) 
		ShowErrorMessage("socket()");

	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET; //��� ü���� ����Ұ��� �����Ͽ����ϴ�.
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);//4����Ʈ ������ ��Ʈ��ũ ����Ʈ�������� �����Ͽ����ϴ� nl =long �������ǹ��ϱ⶧����
	serverAddress.sin_port = htons(SeverPort); //2����Ʈ ���� ��Ʈ��ũ�� ����Ʈ��������
	if (bind(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
		ShowErrorMessage("bind()");
	cout << "[�������]bind()\n";

	if (listen(serverSocket, 5) == SOCKET_ERROR)
		ShowErrorMessage("listen()");
	cout << "[���� ����]listen()\n";

	int sizeClientAddress = sizeof(clientAddress);
	clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddress, &sizeClientAddress);
	cout << "[�������]accept()\n";


	if (clientSocket == INVALID_SOCKET)
		ShowErrorMessage("accept()\n");
	while (1) {
		int length = recv(clientSocket, received, sizeof(received),0);
		received[length] = NULL;
		cout << "[Ŭ���̾�Ʈ�޽���:]" << received << '\n';
		cout << "[�޽��� ����:]" << received << '\n';
		if (strcmp(received, "[exit]") == 0)
		{
			send(clientSocket, received, sizeof(received) - 1, 0);
			cout << "[��������]\n";
			break;
		}

		send(clientSocket, received, sizeof(received) - 1, 0);

	}

	closesocket(clientSocket);
	closesocket(serverSocket);
	WSACleanup();
	system("pause");
	return 0;
	

	
	
}

