#pragma once
#include "Dx12.h"

class descriptor_heap{
public:
    // コンストラクタ
    descriptor_heap() {};
    // デストラクタ
    ~descriptor_heap() {};

    ID3D12DescriptorHeap* DescriptorHeap();
    D3D12_DESCRIPTOR_HEAP_TYPE getType();

private:
    ID3D12DescriptorHeap* heap_{};
    D3D12_DESCRIPTOR_HEAP_TYPE* type_{};
};

