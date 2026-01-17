#pragma once
#include <d3d12.h>
#include <dxgi1_4.h>
#include <cassert>

class Dx12 final
{
public:
    // コンストラクタ
    Dx12() {}
    // デストラクタ
    ~Dx12() {}

    IDXGIFactory4* CreateDXGIFactory();
    IDXGIAdapter1* GetHardwareAdapter(IDXGIFactory4* factory);
    void CreateD3D12Device(IDXGIAdapter1* adapter);
    ID3D12CommandQueue* CreateCommandQueue(ID3D12Device* device);
    void CreateSwapChain(IDXGIFactory4* factory, ID3D12CommandQueue* commandQueue, HWND hwnd);
    void                EnableDebugLayer();
    ID3D12Device* device;
    IDXGISwapChain3* swapChain;
    DXGI_SWAP_CHAIN_DESC1 swapChainDesc;
    
    [[nodiscard]] const DXGI_SWAP_CHAIN_DESC1& getDesc() const noexcept;
    [[nodiscard]] ID3D12Device* getd() const noexcept;
    [[nodiscard]] IDXGISwapChain3* getsc() const noexcept;
    
private:
    ID3D12Device* device_{};//デバイス
    IDXGISwapChain3* swapChain_{};//スワップチェイン
    DXGI_SWAP_CHAIN_DESC1 swapChainDesc_{};//スワップチェインの設定
};