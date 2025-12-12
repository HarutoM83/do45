#include "descriptor_heap.h"
#include <cassert>

descriptor_heap::~descriptor_heap() 
{
    // ディスクリプタヒープの解放
    if (heap_) {
        heap_->Release();
        heap_ = nullptr;
    }
}
//---------------------------------------------------------------------------------
[[nodiscard]] bool descriptor_heap::create(const Dx12& dx12, D3D12_DESCRIPTOR_HEAP_TYPE type, UINT numDescriptors, bool shaderVisible) noexcept 
{
    // ヒープの設定
    D3D12_DESCRIPTOR_HEAP_DESC heapDesc = {};
    heapDesc.Type = type;
    heapDesc.NumDescriptors = numDescriptors;
    heapDesc.Flags = shaderVisible ? D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE : D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    type_ = type;  // ヒープのタイプを保存

    // ディスクリプタヒープの生成
    HRESULT hr = dx12.device->CreateDescriptorHeap(&heapDesc, IID_PPV_ARGS(&heap_));
    if (FAILED(hr)) {
        assert(false && "ディスクリプタヒープの生成に失敗しました");
        return false;
    }

    return true;
}

//---------------------------------------------------------------------------------

[[nodiscard]] ID3D12DescriptorHeap* descriptor_heap::DescriptorHeap() const noexcept 
{
    if (!heap_) 
    {
        assert(false && "ディスクリプタヒープが未生成です");
    }

    return heap_;
}

//---------------------------------------------------------------------------------

[[nodiscard]] D3D12_DESCRIPTOR_HEAP_TYPE descriptor_heap::getType() const noexcept 
{
    if (!heap_) 
    {
        assert(false && "ディスクリプタヒープが未生成です");
    }
    return type_;
}


