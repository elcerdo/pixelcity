/*-----------------------------------------------------------------------------

  Win.cpp

  2006 Shamus Young

  -------------------------------------------------------------------------------

  Create the main window and make it go.

  -----------------------------------------------------------------------------*/

#define MOUSE_MOVEMENT          0.5f

#include <cmath>
#include <cstdarg>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <SDL/SDL.h>

#include "Linux.h"
#include "Camera.h"
#include "Car.h"
#include "Entity.h"
#include "Ini.h"
#include "Macro.h"
#include "Random.h"
#include "Render.h"
#include "Texture.h"
#include "Win.h"
#include "World.h"
#include "Visible.h"
#include "glTypes.h"

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")
#if SCREENSAVER
#pragma comment (lib, "scrnsave.lib")
#endif	

//static HWND         hwnd;
//static HINSTANCE    module;
static int          width;
static int          height;
static int          half_width;
static int          half_height;
static bool         lmb;
static bool         rmb;
static bool         mouse_forced;
static POINT        select_pos;
static POINT        mouse_pos;
static bool         quit;
//static HINSTANCE    instance;

///*-----------------------------------------------------------------------------
//
//  -----------------------------------------------------------------------------*/
//
//static void CenterCursor ()
//{
//
//    int             center_x;
//    int             center_y;
//    RECT            rect;
//
//    SetCursor (NULL);
//    mouse_forced = true;
//    GetWindowRect (hwnd, &rect);
//    center_x = rect.left + (rect.right - rect.left) / 2;
//    center_y = rect.top + (rect.bottom - rect.top) / 2;
//    SetCursorPos (center_x, center_y);
//
//}

///*-----------------------------------------------------------------------------
//
//  -----------------------------------------------------------------------------*/
//
//static void MoveCursor (int x, int y)
//{
//
//    int             center_x;
//    int             center_y;
//    RECT            rect;
//
//    SetCursor (NULL);
//    mouse_forced = true;
//    GetWindowRect (hwnd, &rect);
//    center_x = rect.left + x;
//    center_y = rect.top + y;
//    SetCursorPos (center_x, center_y);
//
//}


/*-----------------------------------------------------------------------------

  -----------------------------------------------------------------------------*/

//LRESULT CALLBACK WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//
//
//    RECT            r;
//    float           delta_x, delta_y;
//    POINT           p;
//    int             param;
//    int             key;
//
//    switch (message) 	{
//        case WM_SIZE:
//            param = wParam;      // resizing flag 
//            width = LOWORD(lParam);  // width of client area 
//            height = HIWORD(lParam); // height of client area 
//
//            if (param == SIZE_RESTORED) 
//                IniIntSet ("WindowMaximized", 0);
//            if (param == SIZE_MAXIMIZED) {
//                IniIntSet ("WindowMaximized", 1);
//            } else {
//                IniIntSet ("WindowWidth", width);
//                IniIntSet ("WindowHeight", height);
//            }
//            RenderResize ();
//            return 0;
//        case WM_MOVE:
//            GetClientRect (hwnd, &r);
//            height = r.bottom - r.top;
//            width = r.right - r.left;
//            IniIntSet ("WindowX", r.left);
//            IniIntSet ("WindowY", r.top);
//            IniIntSet ("WindowWidth", width);
//            IniIntSet ("WindowHeight", height);
//            half_width = width / 2;
//            half_height = height / 2;
//            break;
//        case WM_KEYDOWN:
//            key = (int) wParam; 
//
//            if (key == 'R')
//                WorldReset (); 
//            if (key == 'C')
//                CameraAutoToggle (); 
//            if (key == 'W')
//                RenderWireframeToggle ();
//            if (key == 'E')
//                RenderEffectCycle ();
//            if (key == 'L')
//                RenderLetterboxToggle ();
//            if (key == 'F')
//                RenderFPSToggle ();
//            if (key == 'G')
//                RenderFogToggle ();
//            if (key == 'T')
//                RenderFlatToggle ();
//            if (key == VK_F1)
//                RenderHelpToggle ();
//            if (key == 'B')
//                CameraNextBehavior ();
//            if (key == VK_ESCAPE)
//                quit = true;
//            if (key == VK_F5)
//                CameraReset ();
//            return 0;
//        case WM_LBUTTONDOWN:
//            lmb = true;
//            SetCapture (hwnd);
//            break;
//        case WM_RBUTTONDOWN:
//            rmb = true;
//            SetCapture (hwnd);
//            break;
//        case WM_LBUTTONUP:
//            lmb = false;
//            if (!rmb) {
//                ReleaseCapture ();
//                MoveCursor (select_pos.x, select_pos.y);
//            }
//            break;
//        case WM_RBUTTONUP:
//            rmb = false;
//            if (!lmb) {
//                ReleaseCapture ();
//                MoveCursor (select_pos.x, select_pos.y);
//            }
//            break;
//        case WM_MOUSEMOVE:
//            p.x = LOWORD(lParam);  // horizontal position of cursor 
//            p.y = HIWORD(lParam);  // vertical position of cursor 
//            if (p.x < 0 || p.x > width)
//                break;
//            if (p.y < 0 || p.y > height)
//                break;
//            if (!mouse_forced && !lmb && !rmb) {
//                select_pos = p; 
//            }
//            if (mouse_forced) {
//                mouse_forced = false;
//            } else if (rmb || lmb) {
//                CenterCursor ();
//                delta_x = (float)(mouse_pos.x - p.x) * MOUSE_MOVEMENT;
//                delta_y = (float)(mouse_pos.y - p.y) * MOUSE_MOVEMENT;
//                if (rmb && lmb) {
//                    GLvector    pos;
//                    CameraPan (delta_x);
//                    pos = CameraPosition ();
//                    pos.y += delta_y;
//                    CameraPositionSet (pos);
//                } else if (rmb) {
//                    CameraPan (delta_x);
//                    CameraForward (delta_y);
//                } else if (lmb) {
//                    GLvector    angle;
//                    angle = CameraAngle ();
//                    angle.y -= delta_x;
//                    angle.x += delta_y;
//                    CameraAngleSet (angle);
//                }
//            }
//            mouse_pos = p;
//            break;
//        case WM_CLOSE:
//            quit = true;
//            return 0;
//    }
//    return DefWindowProc(hWnd, message, wParam, lParam);   
//
//}

/*-----------------------------------------------------------------------------
  n o t e
  -----------------------------------------------------------------------------*/

void WinPopup (char* message, ...)
{

    va_list  		marker;
    char        buf[1024];

    va_start (marker, message);
    vsprintf (buf, message, marker); 
    va_end (marker);
    printf(buf);
}

/*-----------------------------------------------------------------------------

  -----------------------------------------------------------------------------*/

int WinWidth (void)
{

    return width;

}

/*-----------------------------------------------------------------------------

  -----------------------------------------------------------------------------*/

void WinMousePosition (int* x, int* y)
{

    *x = select_pos.x;
    *y = select_pos.y;

}


/*-----------------------------------------------------------------------------

  -----------------------------------------------------------------------------*/

int WinHeight (void)
{

    return height;

}

/*-----------------------------------------------------------------------------

  -----------------------------------------------------------------------------*/

void WinTerm (void)
{
}

///*-----------------------------------------------------------------------------
//
//  -----------------------------------------------------------------------------*/
//
//HWND WinHwnd (void)
//{
//
//    return hwnd;
//
//}

/*-----------------------------------------------------------------------------

  -----------------------------------------------------------------------------*/

bool WinInit (void)
{

    //WNDCLASSEX    wcex;
    //int           x, y;
    //int           style;
    //bool          max;

    //wcex.cbSize         = sizeof(WNDCLASSEX); 
    //wcex.style			    = CS_HREDRAW | CS_VREDRAW;
    //wcex.lpfnWndProc	  = (WNDPROC)WndProc;
    //wcex.cbClsExtra		  = 0;
    //wcex.cbWndExtra		  = 0;
    //wcex.hInstance		  = instance;
    //wcex.hIcon			    = NULL;
    //wcex.hCursor		    = LoadCursor(NULL, IDC_ARROW);
    //wcex.hbrBackground	= (HBRUSH)(COLOR_BTNFACE+1);
    //wcex.lpszMenuName	  = NULL;
    //wcex.lpszClassName	= APP_TITLE;
    //wcex.hIconSm		    = NULL;
    //if (!RegisterClassEx(&wcex)) {
    //    WinPopup ("Cannot create window class");
    //    return false;
    //}
    //x = IniInt ("WindowX");
    //y = IniInt ("WindowY");
    //style = WS_TILEDWINDOW;
    //style |= WS_MAXIMIZE;
    //width = IniInt ("WindowWidth");
    //height = IniInt ("WindowHeight");
    //width = CLAMP (width, 800, 2048);
    //height = CLAMP (height, 600, 2048);
    //half_width = width / 2;
    //half_height = height / 2;
    //max = IniInt ("WindowMaximized") == 1;
    //if (!(hwnd = CreateWindowEx (0, APP_TITLE, APP_TITLE, style,
    //                CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, instance, NULL))) {
    //    WinPopup ("Cannot create window");
    //    return false;
    //}
    //if (max) 
    //    ShowWindow (hwnd, SW_MAXIMIZE);
    //else
    //    ShowWindow (hwnd, SW_SHOW);
    //UpdateWindow (hwnd);
    //return true;

}

/*-----------------------------------------------------------------------------

  -----------------------------------------------------------------------------*/

void AppQuit ()
{

    quit = true;

}

/*-----------------------------------------------------------------------------

  -----------------------------------------------------------------------------*/

void AppInit (void)
{

    RandomInit (time (NULL));
    CameraInit ();
    RenderInit ();
    TextureInit ();
    WorldInit ();

}

/*-----------------------------------------------------------------------------

  -----------------------------------------------------------------------------*/

void AppUpdate ()
{

    CameraUpdate ();
    WorldUpdate ();
    TextureUpdate ();
    WorldUpdate ();
    VisibleUpdate ();
    CarUpdate ();
    EntityUpdate ();
    WorldUpdate ();
    RenderUpdate ();

}

/*-----------------------------------------------------------------------------
  W i n M a i n
  -----------------------------------------------------------------------------*/

void AppTerm (void) 
{

    TextureTerm ();
    WorldTerm ();
    RenderTerm ();
    CameraTerm ();
    WinTerm ();

}

/*-----------------------------------------------------------------------------
  W i n M a i n
  -----------------------------------------------------------------------------*/

int main() {
    WinInit ();
    AppInit ();

    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    quit=true;
                    break;
                default:
                    break;
            }
        } 

        AppUpdate ();
    }

    AppTerm ();
    return 0;
}

