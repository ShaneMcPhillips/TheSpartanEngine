#include <windows.h>
 

//Window function for processing incoming messages.
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uInt, WPARAM wParam, LPARAM lParam);


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//Create WindowClass
	//Class name for handling
	const wchar_t CLASS_NAME[] = L"Initial Window Class";
	//window title
	const wchar_t WINDOW_TITLE[] = L"The Spartan Engine v-1.0-a";

	//width and height for window
	const int wnd_width = 1080;
	const int wnd_height = 920;

	//Define a window structure.
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); //Defines the size of the wndclass structure.
	wcex.style = CS_HREDRAW | CS_VREDRAW; //Defines a redraw everytime horizontal / vertical axis are resized.
	wcex.lpfnWndProc = WindowProc; //Sets the reference to the window message processing func.
	wcex.cbClsExtra = 0; //Extra bits needed for the window style? No.
	wcex.cbWndExtra = 0; //Extra bits needed for the window class? No.
	wcex.hInstance = hInstance; //HWND instance, pass down from WinMain argument defined.
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION); //Standard icon set.
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW); //Standard cursor set.
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH); //H-Brush not needed as directx will handle.
	wcex.lpszMenuName = nullptr; //No menu class structure.
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION); //Standard small icon set.

	//Register the class structure above.
	RegisterClassEx(&wcex);

	//Create Window
	HWND hWnd = CreateWindow(CLASS_NAME, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, wnd_width, wnd_height,
		nullptr, nullptr, hInstance, nullptr);

	//Check if window was created and filled in handle.
	if (hWnd == NULL) {
		//error handle here
		return 0;
	}
	
	//Display the window
	ShowWindow(hWnd, SW_SHOW);



	//Create Window and Display



	return 0;
}