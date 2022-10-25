#include <iostream>
#include <string>
#include <WinSock2.h>


using namespace std;


void ShowErrorMessage(string message) {

	cout << "{오류발생}:" << message << '\n'; //오류메시지를 출력하고
	system("pause");
	exit(1); //프로그램을 종료함
} 
//네트워크 프로그래밍은 오류상황이 많이날수있는데 그래서 오류관련 핸들링함수는 필수이다.


int main() {

	WSADATA wsaData; //wsapi구조체를 하나의 변수로 만들어주었다.
	SOCKET serverSocket, clientSocket; //socket을 두개로 변수로만들었다.
	SOCKADDR_IN serverAddress, clientAddress;

	int SeverPort = 9876; // 서버포트로 9876을 사용한다
	char received[256]; //클라이언트와 받을떄 문자열버퍼크기를 256으로 설정하였다.

	if (WSAStartup(MAKEWORD(2,2),&wsaData) !=0)//makeword라는 그룹체를 이용해서 간단하게 명시를 해두었고 winsocke을 초기화합니다. 결과를 성공적으로 winsock api에 볼수있도록하엿다.

		ShowErrorMessage("WSAStartup()"); //0이 아니라면 오류메시지를 출력하는것입니다.

	serverSocket = socket(PF_INET, SOCK_STREAM, 0); //tcp 형식임 , 서버소켓을 초기화해줍니다
	
	if (serverSocket = INVALID_SOCKET) 
		ShowErrorMessage("socket()");

	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET; //어떠한 체꼐를 사용할건지 설정하였습니다.
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);//4바이트 정수를 네트워크 바이트형식으로 저장하였습니다 nl =long 형식을의미하기때문에
	serverAddress.sin_port = htons(SeverPort); //2바이트 정수 네트워크를 바이트형식으로
	if (bind(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
		ShowErrorMessage("bind()");
	cout << "[현재상태]bind()\n";

	if (listen(serverSocket, 5) == SOCKET_ERROR)
		ShowErrorMessage("listen()");
	cout << "[현재 상태]listen()\n";

	int sizeClientAddress = sizeof(clientAddress);
	clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddress, &sizeClientAddress);
	cout << "[현재상태]accept()\n";


	if (clientSocket == INVALID_SOCKET)
		ShowErrorMessage("accept()\n");
	while (1) {
		int length = recv(clientSocket, received, sizeof(received),0);
		received[length] = NULL;
		cout << "[클라이언트메시지:]" << received << '\n';
		cout << "[메시지 전송:]" << received << '\n';
		if (strcmp(received, "[exit]") == 0)
		{
			send(clientSocket, received, sizeof(received) - 1, 0);
			cout << "[서버종료]\n";
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

