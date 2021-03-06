#include <windows.h>

#define STEP 100
#define W_SIZE_H 500+40//window height y
#define W_SIZE_W 800 + 20//window width x
#define W_START_X 0//window start position x
#define W_START_Y 0//window start position y
#define W_CAPTION "Form Caption"

HWND panel;
HBRUSH brushWhite, brushBlack; 
long x = 100, y = 100;

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	int i = 0, j = 0;
	long newx = 0, newy = 0;
	PAINTSTRUCT ps;
	RECT rect;
	bool flag = false;
	switch(Message) {
		case WM_DESTROY: PostQuitMessage(0); break;
		case WM_CREATE: //������ ����� � ������
    		brushWhite = (HBRUSH)GetStockObject(WHITE_BRUSH); 
    		brushBlack  = (HBRUSH)GetStockObject(BLACK_BRUSH); 
    		return 0; 
		case WM_KEYDOWN: {//����� ������� ������
		
			switch (wParam)
			{
				case VK_LEFT: (x - STEP >= NULL) ? x -= STEP : x = x; break;
				case VK_RIGHT: (x + STEP <= W_START_X + W_SIZE_W - STEP) ? x += STEP : x = x; break;
				case VK_UP: (y - STEP >= NULL) ? y -= STEP: y = y; break;
				case VK_DOWN: (y + STEP <= W_START_Y + W_SIZE_H - STEP) ? y += STEP : y = y; break;	
 			}
 			SetWindowPos(panel, 0, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
 			UpdateWindow(hwnd);
			break; 
		}
		case WM_MOUSEMOVE: {
			if (wParam == NULL) break;
			newx = LOWORD(lParam) / STEP * STEP;
			newy = HIWORD(lParam) / STEP * STEP;
			if ((x != newx) || (y != newy)){
				x = newx;
				y = newy;
				SetWindowPos(panel, 0, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
				UpdateWindow(hwnd);
			}
			break;
		}
		case WM_PAINT : {
			HDC hdc = BeginPaint(hwnd, &ps); 
            for (i = 0; i < 8; ++i){
            	for (j = 0; j < 5; ++j){
            		rect.left = i * STEP;
            		rect.top = j * STEP;
            		rect.bottom = (j + 1) * STEP;
            		rect.right = (i + 1) * STEP;
            		FillRect(hdc, &rect, ((i + j)%2 == 0) ? brushBlack : brushWhite);
				}	
			}
            EndPaint(hwnd, &ps);
			break;
		}
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* Use the name "A" to use the project icon */
	VirtualAllocEx(hwnd, NULL, 1024 * 1024 * 1024, MEM_COMMIT, PAGE_READWRITE); /* Reserve memory for our programm */
	DWORD dwExStyle = WS_EX_CLIENTEDGE|WS_EX_DLGMODALFRAME;
	DWORD dwStyle = WS_CHILD|WS_VISIBLE|SS_CENTER|SS_CENTERIMAGE|SS_SUNKEN;
	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass", W_CAPTION, WS_VISIBLE | WS_OVERLAPPEDWINDOW, W_START_X, W_START_Y, W_SIZE_W, W_SIZE_H, NULL, NULL, hInstance, NULL);
	panel = CreateWindowEx(dwExStyle, "STATIC", "Im a PANEL", dwStyle, x, y, STEP, STEP, hwnd, (HMENU)NULL, hInstance, (LPVOID)NULL);
	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
