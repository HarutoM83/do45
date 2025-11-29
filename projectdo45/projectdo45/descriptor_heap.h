#pragma once
#include "Dx12.h"
#include <cassert>

class descriptor_heap final{
public:
    // コンストラクタ
    descriptor_heap() = default;
    // デストラクタ
    ~descriptor_heap();

    /*
       @brief	ディスクリプタヒープを生成する
	   @param	device	デバイスクラスのインスタンス
	   @param	type	ディスクリプタヒープのタイプ
	   @param	numDescriptors	ディスクリプタの数
	   @param	shaderVisible	シェーダーからアクセス可能かどうか
	   @return	生成の成否
    */

    [[nodiscard]] bool create(const Dx12& dx12,D3D12_DESCRIPTOR_HEAP_TYPE type, UINT numDescriptors, bool shaderVisible = false) noexcept;

    /*
       @brief	ディスクリプタヒープを取得する
	   @return	ディスクリプタヒープのポインタ
    */

    ID3D12DescriptorHeap* DescriptorHeap() const noexcept;

    /*
        @brief	ディスクリプタヒープのタイプを取得する
	    @return	ディスクリプタヒープのタイプ
    */

    D3D12_DESCRIPTOR_HEAP_TYPE getType() const noexcept;

private:
    ID3D12DescriptorHeap* heap_{};
    D3D12_DESCRIPTOR_HEAP_TYPE type_{};
};

