#pragma once
#include "Dx12.h"
#include "command_allocator.h"
class command_list final
{
public:
    
    command_list() = default;
      
   ~command_list();
     
    [[nodiscard]] bool create(const Dx12& device, const command_allocator& commandAllocator) noexcept;
             
    void reset(const command_allocator& commandAllocator) noexcept;

    [[nodiscard]] ID3D12GraphicsCommandList* get() const noexcept;

private:
    ID3D12GraphicsCommandList* commandList_{}; // コマンドリスト
};

