#pragma once
#include"Dx12.h"
class fence final
{
public:
    
    fence() = default;
     
    ~fence();
     
    [[nodiscard]] bool create(const Dx12& device) noexcept;
     
    void wait(UINT64 fenceValue) const noexcept;
     
    [[nodiscard]] ID3D12Fence* get() const noexcept;

private:
    ID3D12Fence* fence_{};         /// フェンス
    HANDLE       waitGpuEvent_{};  /// GPU と CPU 同期用のイベントハンドル
};

