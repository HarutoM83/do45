#pragma once
#include "Dx12.h"
class command_allocator final
{
public:
    
    command_allocator() = default;
             
    ~command_allocator();
             
    [[nodiscard]] bool create(const Dx12& device, const D3D12_COMMAND_LIST_TYPE type) noexcept;
        
    void reset() noexcept;
        
    [[nodiscard]] ID3D12CommandAllocator* getca() const noexcept;
         
    [[nodiscard]] D3D12_COMMAND_LIST_TYPE getType() const noexcept;

private:
    ID3D12CommandAllocator* commandAllocator_{};  /// コマンドアロケータ
    D3D12_COMMAND_LIST_TYPE type_{};              /// コマンドリストのタイプ
    
};

