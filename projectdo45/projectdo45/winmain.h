
#pragma once

#include <Windows.h>
#include <string>

using namespace std;

class Window final
{
public:

    Window() = default;

    ~Window() = default;

    HRESULT create
    (
        HINSTANCE hInstance,      // アプリケーションの識別番号
        int width,
        int height,
        string_view nCmdShow              // ウィンドウの表示方法（最大化、最小化など）
    )noexcept;

    bool messageloop()const noexcept;

    HWND handle()const noexcept;

    pair<int, int >size()const noexcept;

private:
    HWND handle_{};
    int width_{};
    int height_{};
};