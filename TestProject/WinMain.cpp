#include <windows.h>

#define NAMING_STRING_MAX_CHARS 256

WCHAR CLASS_NAME[NAMING_STRING_MAX_CHARS];
WCHAR WINDOW_TITLE[NAMING_STRING_MAX_CHARS];
 

//Window function for processing incoming messages.
LRESULT CALLBACK WndProc(HWND hWnd, UINT uInt, WPARAM wParam, LPARAM lParam);


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//Create WindowClass
	//Class name for handling
	wcscpy_s(CLASS_NAME, L"Initial Window Class");
	
	//window title
	//const wchar_t WINDOW_TITLE[] = L"The Spartan Engine v-1.0-a";
	wcscpy_s(WINDOW_TITLE, L"The Spartan Engine v-1.0-a");

	//width and height for window
	const int wnd_width = 1080;
	const int wnd_height = 920;

	//Define a window structure.
	WNDCLASSEX wcex = {0};

	wcex.cbSize = sizeof(WNDCLASSEX); //Defines the size of the wndclass structure.
	wcex.style = CS_HREDRAW | CS_VREDRAW; //Defines a redraw everytime horizontal / vertical axis are resized.
	wcex.lpfnWndProc = WndProc; //Sets the reference to the window message processing func.
	wcex.cbClsExtra = 0; //Extra bits needed for the window style? No.
	wcex.cbWndExtra = 0; //Extra bits needed for the window class? No.
	wcex.hInstance = hInstance; //HWND instance, pass down from WinMain argument defined.
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION); //Standard icon set.
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW); //Standard cursor set.
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH); //H-Brush not needed as directx will handle.
	wcex.lpszMenuName = nullptr; //No menu class structure.
	wcex.lpszClassName = CLASS_NAME;
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION); //Standard small icon set.

	//Register the class structure above.
	RegisterClassEx(&wcex);

	//Create Window
	HWND wnd = CreateWindowEx(NULL, CLASS_NAME, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, wnd_width, wnd_height,
		NULL, NULL, hInstance, NULL);


	//Check if window was created and filled in handle.
	if (!wnd) {
		//error message box
		MessageBox(NULL, (LPCWSTR)L"There was an error in creating the display window.\nReference: HWND is NULL", (LPCWSTR)L"Error", MB_ICONERROR | MB_OK | MB_DEFBUTTON1);
		return 0;
	}
	
	//Display the window
	ShowWindow(wnd, SW_SHOW);

	//Handle Messages
	MSG msg = {0};

	//Make sure we didn't terminate the window.
	while (msg.message != WM_QUIT) {

		//Using Peek Message since Get Message locks up thread until a message is received.
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			//process message for keystrokes and mouse clicks with translate. Send message to win proc with dispatch.
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}



	//Create Window and Display



	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uInt, WPARAM wParam, LPARAM lParam) {
	return DefWindowProc(hWnd, uInt, wParam, lParam);
}