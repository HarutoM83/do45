#include "command_list.h"
#include <cassert>

//---------------------------------------------------------------------------------
 
command_list::~command_list() 
{
    // コマンドリストの解放
    if (commandList_) 
    {
        commandList_->Release();
        commandList_ = nullptr;
    }
}

//---------------------------------------------------------------------------------
 
[[nodiscard]] bool command_list::create(const Dx12& device, const command_allocator& commandAllocator) noexcept 
{
    // コマンドリストの作成
    const auto hr = device.getd()->CreateCommandList(0, commandAllocator.getType(), commandAllocator.getca(), nullptr, IID_PPV_ARGS(&commandList_));
    if (FAILED(hr)) 
    {
        assert(false && "コマンドリストの作成に失敗しました");
        return false;
    }

    // コマンドリストを初期化状態に設定
    commandList_->Close();
    return true;
}

//---------------------------------------------------------------------------------

void command_list::reset(const command_allocator& commandAllocator) noexcept 
{
    if (!commandList_) 
    {
        assert(false && "コマンドリストが未作成です");
    }

    // コマンドリストをリセット
    commandList_->Reset(commandAllocator.getca(), nullptr);
}

//---------------------------------------------------------------------------------

[[nodiscard]] ID3D12GraphicsCommandList* command_list::getcl() const noexcept 
{
    if (!commandList_) 
    {
        assert(false && "コマンドリストが未作成です");
        return nullptr;
    }
    return commandList_;
}
