#pragma once
#include"Dx12.h"
#include "descriptor_heap.h"
#include <vector>

using namespace std;

class render_target
{
public:
    // コンストラクタ
    render_target() = default;
    // デストラクタ
    ~render_target();

    [[nodiscard]] bool createBackBuffer(const Dx12& device, const SwapChain& swapChain, const descriptor_heap& heap) noexcept;

    [[nodiscard]] D3D12_CPU_DESCRIPTOR_HANDLE getDescriptorHandle(const Dx12& device, const descriptor_heap& heap, UINT index) const noexcept;

    [[nodiscard]] ID3D12Resource* get(uint32_t index) const noexcept;


private:
    vector<ID3D12Resource*> renderTargets_;  /// レンダーターゲットリソースの配列
};

