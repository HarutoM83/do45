#include <Windows.h>
#include <string>

using namespace std;

namespace
{
    LRESULT CALLBACK WindowProc
    (
        HWND hwnd,
        UINT uMsg,
        WPARAM wParam,
        LPARAM lParam
    )
    {
        switch (uMsg)
        {
        case WM_DESTROY:  // ×ボタンが押された時
            PostQuitMessage(0);  // 「アプリを終了します」とWindowsに通知
            return 0;
        case WM_PAINT:    // ウィンドウの再描画が必要な時
            // 画面を更新する処理をここに書く
            return 0;
        case WM_KEYDOWN:  // キーが押された時
            // キー入力の処理をここに書く
            return 0;
        }
        // 自分で処理しないメッセージはWindowsに任せる
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}//namespace
class Window final
{
public:
    /*
    Window() = default;

    ~Window() = default;
    */
    /*
    int WINAPI WinMain
    (
        HINSTANCE hInstance,      // アプリケーションの識別番号
        HINSTANCE hPrevInstance,  // 基本使わなくていい
        LPSTR lpCmdLine,          // コマンドライン引数（起動時のオプション）
        int nCmdShow              // ウィンドウの表示方法（最大化、最小化など）
    )
    */
    HRESULT create
    (
        HINSTANCE hInstance,      // アプリケーションの識別番号
        int width,  
        int height,          
        string_view nCmdShow              // ウィンドウの表示方法（最大化、最小化など）
    )noexcept
    {
        // ここにメインの処理を書く

        // 1. ウィンドウクラス登録

        WNDCLASS wc{};
        wc.lpfnWndProc = WindowProc;           // ウィンドウプロシージャを指定（後述）
        wc.hInstance = hInstance;              // アプリケーションインスタンス
        wc.lpszClassName = nCmdShow.data();      // ウィンドウクラス名
        wc.hCursor = LoadCursor(nullptr, IDC_ARROW);  // マウスカーソル
        wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);  // 背景色

        RegisterClass(&wc);  // Windowsに登録

        // 2. ウィンドウ作成

        handle_ = CreateWindow
        (
            wc.lpszClassName,        // ウィンドウクラス名
            wc.lpszClassName,           // ウィンドウタイトル
            WS_OVERLAPPEDWINDOW,  // ウィンドウスタイル
            CW_USEDEFAULT, CW_USEDEFAULT,  // 位置（自動）
            width, height,            // サイズ（幅、高さ）
            nullptr, nullptr,          // 親ウィンドウ、メニュー
            hInstance,           // インスタンス
            nullptr                 // 追加データ
        );
        if (!handle_) 
        {
            return E_FAIL;
        }

        // ウィンドウを表示
        ShowWindow(handle_, SW_SHOW/*nCmdShow*/);  

        UpdateWindow(handle_);

        width_ = width;
        height_ = height;

        return S_OK;

        /*
        bool nextFream = true;

        //ゲームループ
        while (nextFream)
        {
            // 3. メッセージループ
            MSG msg{};  // メッセージを格納する構造体
            while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))  // メッセージが来るまで待機
            {
                TranslateMessage(&msg);  // キーボードメッセージを使いやすい形に変換
                DispatchMessage(&msg);   // 適切なウィンドウプロシージャに送信
            }
        }

        return 0;
        */

    };

    bool messageloop()const noexcept 
    {
        // 3. メッセージループ
        MSG msg{};  // メッセージを格納する構造体
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))  // メッセージが来るまで待機
        {
            TranslateMessage(&msg);  // キーボードメッセージを使いやすい形に変換
            DispatchMessage(&msg);   // 適切なウィンドウプロシージャに送信
        }
    }

    HWND handle()const noexcept
    {
        return handle_;
    };

    pair<int, int >size()const noexcept
    {
        return{ width_,height_ };
    };

private:
    HWND handle_{};
    int width_{};
    int height_{};
};


