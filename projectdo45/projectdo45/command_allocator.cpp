#include "command_allocator.h"
#include <cassert>
 
command_allocator::~command_allocator() 
{
    // コマンドアロケータの解放
    if (commandAllocator_) 
    {
        commandAllocator_->Release();
        commandAllocator_ = nullptr;
    }
}
 
[[nodiscard]] bool command_allocator::create(const Dx12& device, const D3D12_COMMAND_LIST_TYPE type) noexcept 
{

    // コマンドリストのタイプを設定
    type_ = type;

    // コマンドアロケータの生成
    const auto hr = device.getd()->CreateCommandAllocator(type_, IID_PPV_ARGS(&commandAllocator_));
    if (FAILED(hr)) 
    {
        assert(false && "コマンドアロケータの作成に失敗しました");
        return false;
    }

    return true;
}
 
void command_allocator::reset() noexcept 
{

    if (!commandAllocator_)
    {
        assert(false && "コマンドアロケータが未作成です");
    }

    commandAllocator_->Reset();
}
 
[[nodiscard]] ID3D12CommandAllocator* command_allocator::getca() const noexcept 
{
    if (!commandAllocator_) 
    {
        assert(false && "コマンドアロケータが未作成です");
    }
    return commandAllocator_;
}
 

[[nodiscard]] D3D12_COMMAND_LIST_TYPE command_allocator::getType() const noexcept 
{
    if (!commandAllocator_) 
    {
        assert(false && "コマンドリストのタイプが未設定です");
    }
    return type_;
}
