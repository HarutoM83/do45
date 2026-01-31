#pragma once
#include <d3d12.h>
#include <dxgi1_4.h>
#include <cassert>
#include "winmain.cpp"

class Dx12 final
{
public:
    // コンストラクタ
    Dx12() {}
    // デストラクタ
    ~Dx12() {}

    IDXGIFactory4* CreateDXGIFactory();
    IDXGIAdapter1* GetHardwareAdapter(IDXGIFactory4* factory);
    ID3D12Device* CreateD3D12Device(IDXGIAdapter1* adapter);
    ID3D12CommandQueue* CreateCommandQueue(ID3D12Device* device);
    IDXGISwapChain3* CreateSwapChain(IDXGIFactory4* factory, ID3D12CommandQueue* commandQueue, HWND hwnd);
    void                EnableDebugLayer();
    ID3D12Device* device;
    IDXGISwapChain3* swapChain;
    DXGI_SWAP_CHAIN_DESC1 swapChainDesc;
    ID3D12CommandQueue* commandQueue;
    
    bool CreateD3D12Device(const Dx12& dxgi) noexcept;
    bool CreateCommandQueue(const Dx12& dxgi) noexcept;
    bool CreateSwapChain(const Dx12& dxgi, const Window& window, const Dx12& commandQueue) noexcept;
    //[[nodiscard]] bool create(const Dx12& dxgi) noexcept;
    [[nodiscard]] const DXGI_SWAP_CHAIN_DESC1& getDesc() const noexcept;
    [[nodiscard]] ID3D12Device* getd() const noexcept;
    [[nodiscard]] IDXGISwapChain3* getsc() const noexcept;
    [[nodiscard]] ID3D12CommandQueue* getcq() const noexcept;
private:

    ID3D12Device* device_{};//デバイス
    IDXGISwapChain3* swapChain_{};//スワップチェイン
    ID3D12CommandQueue* commandQueue_{};//コマンドキュー
    DXGI_SWAP_CHAIN_DESC1 swapChainDesc_{};//スワップチェインの設定
};